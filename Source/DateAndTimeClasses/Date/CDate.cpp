#include "CDate.h"
#include <math.h>

using namespace GeyserEruptionCalc;


CDate::CDate() :
	m_year(),
	m_month(),
	m_day()
{
}

CDate::CDate(const CDate &Ref) :
	m_year(Ref.m_year),
	m_month(Ref.m_month),
	m_day(Ref.m_day)
{
}

CDate::CDate(const CYear &year, const CMonth &month, const CDay &day) :
	m_year(year),
	m_month(month),
	m_day(day)
{
}

CDate::~CDate()
{
}

const CDate& CDate::operator=(const CDate &Ref)
{
	m_year = Ref.m_year;
	m_month = Ref.m_month;
	m_day = Ref.m_day;
	return *this;
}

void CDate::SetDate(const CYear &year, const CMonth &month, const CDay &day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}

void CDate::SetYear(const CYear &year)
{
	m_year = year;
}

void CDate::SetYear(long year)
{
	m_year.SetYear(year);
}

void CDate::SetMonth(const CMonth &month)
{
	m_month = month;
}

void CDate::SetMonth(long month)
{
	m_month.SetMonth(month);
}

void CDate::SetDay(const CDay &day)
{
	m_day = day;
}

void CDate::SetDay(long day)
{
	m_day.SetDay(day);
}

const CYear& CDate::GetYear() const
{
	if(!m_year.IsValidYear())
		throw new CYearException();
	return m_year;
}

const CMonth& CDate::GetMonth() const
{
	if(!m_month.IsValidMonth())
		throw new CMonthException();
	return m_month;
}

const CDay& CDate::GetDay() const
{
	if(!m_day.IsValidDay())
		throw new CDayException();
	return m_day;
}

bool CDate::operator==(const CDate &Ref) const
{
	CheckValidityWithThrows();
	Ref.CheckValidityWithThrows();
	if(m_year.GetYear() == Ref.m_year.GetYear() &&
		m_month.GetMonth() == Ref.m_month.GetMonth() &&
		m_day.GetDay() == Ref.m_day.GetDay())
		return true;
	return false;
}

bool CDate::operator!=(const CDate &Ref) const
{
	CheckValidityWithThrows();
	Ref.CheckValidityWithThrows();
	return !((*this)==Ref);
}

bool CDate::operator<(const CDate &Ref) const
{
	CheckValidityWithThrows();
	Ref.CheckValidityWithThrows();
	if((*this)==Ref)
		return false;
	if(m_year.GetYear() == Ref.m_year.GetYear())
	{
		if(m_month.GetMonth() == Ref.m_month.GetMonth())
		{
			if(m_day.GetDay() < Ref.m_day.GetDay())
				return true;
			return false;
		}
		if(m_month.GetMonth() < Ref.m_month.GetMonth())
			return true;
		return false;
	}
	if(m_year.GetYear() < Ref.m_year.GetYear())
		return true;
	return false;
}

bool CDate::operator>(const CDate &Ref) const
{
	CheckValidityWithThrows();
	Ref.CheckValidityWithThrows();
	if((*this)==Ref)
		return false;
	return !((*this)<Ref);
}

bool CDate::operator<=(const CDate &Ref) const
{
	CheckValidityWithThrows();
	Ref.CheckValidityWithThrows();
	if((*this)==Ref)
		return true;
	return (*this) < Ref;
}

bool CDate::operator>=(const CDate &Ref) const
{
	CheckValidityWithThrows();
	Ref.CheckValidityWithThrows();
	if((*this)==Ref)
		return true;
	return (*this) > Ref;
}

bool CDate::IsValidDate() const
{
	if(m_year.IsValidYear() && m_month.IsValidMonth() && m_day.IsValidDay())
	{
		if(m_month.GetMonth() == 1 && m_day.GetDay() <= 31)
			return true;
		if(m_month.GetMonth() == 2 && m_day.GetDay() <= 29 && m_year.IsLeapYear())
			return true;
		if(m_month.GetMonth() == 2 && m_day.GetDay() <= 28)
			return true;
		if(m_month.GetMonth() == 3 && m_day.GetDay() <= 31)
			return true;
		if(m_month.GetMonth() == 4 && m_day.GetDay() <= 30)
			return true;
		if(m_month.GetMonth() == 5 && m_day.GetDay() <= 31)
			return true;
		if(m_month.GetMonth() == 6 && m_day.GetDay() <= 30)
			return true;
		if(m_month.GetMonth() == 7 && m_day.GetDay() <= 31)
			return true;
		if(m_month.GetMonth() == 8 && m_day.GetDay() <= 31)
			return true;
		if(m_month.GetMonth() == 9 && m_day.GetDay() <= 30)
			return true;
		if(m_month.GetMonth() == 10 && m_day.GetDay() <= 31)
			return true;
		if(m_month.GetMonth() == 11 && m_day.GetDay() <= 30)
			return true;
		if(m_month.GetMonth() == 12 && m_day.GetDay() <= 31)
			return true;
	}
	return false;
}

DAYOFWEEK CDate::GetDayOfWeek(const CDate &Ref)
{
	Ref.CheckValidityWithThrows();
	long d,y,l;
	y = Ref.m_year.GetYear() - 1600;
	l = (long)(y/4) - (long)(y/100) + (long)(y/400);
	d = Ref.GetDayOfYear() + y * 365 + l;
	if(d%7 == 0)
		return ESATURDAY;
	if(d%7 == 1)
		return ESUNDAY;
	if(d%7 == 2)
		return EMONDAY;
	if(d%7 == 3)
		return ETUESDAY;
	if(d%7 == 4)
		return EWEDNESDAY;
	if(d%7 == 5)
		return ETHURSDAY;
	return EFRIDAY;
}

long CDate::GetDaysInMonth() const
{
	CheckValidityWithThrows();
	long tmp;
	tmp = m_month.GetMonth();
	if(tmp == 1)
		return 31;
	if(tmp == 2 && m_year.IsLeapYear())
		return 29;
	if(tmp == 2)
		return 28;
	if(tmp == 3)
		return 31;
	if(tmp == 4)
		return 30;
	if(tmp == 5)
		return 31;
	if(tmp == 6)
		return 30;
	if(tmp == 7)
		return 31;
	if(tmp == 8)
		return 31;
	if(tmp == 9)
		return 30;
	if(tmp == 10)
		return 31;
	if(tmp == 11)
		return 30;
	return 31;
}

long CDate::GetDaysInYear() const
{
	CheckValidityWithThrows();
	if(m_year.IsLeapYear())
		return 366;
	return 365;
}

long CDate::GetDayOfYear() const
{
	CheckValidityWithThrows();
	long d;
	d = m_day.GetDay();
	long m = m_month.GetMonth();
	if(m == 1)
		return d;
	d+=31;
	if(m == 2)
		return d;
	if(m_year.IsLeapYear())
		d += 29;
	else
		d += 28;
	if(m == 3)
		return d;
	d+=31;
	if(m == 4)
		return d;
	d+=30;
	if(m == 5)
		return d;
	d+=31;
	if(m == 6)
		return d;
	d+=30;
	if(m == 7)
		return d;
	d+=31;
	if(m == 8)
		return d;
	d+=31;
	if(m == 9)
		return d;
	d+=30;
	if(m == 10)
		return d;
	d+=31;
	if(m == 11)
		return d;
	d+=30;
	return d;
}

void CDate::CheckValidityWithThrows() const
{
	if(!IsValidDate())
		throw new CDateException();
}

