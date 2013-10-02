#include "CYear.h"

using namespace GeyserEruptionCalc;

enum CYEAR_INVALID
{
	CYEAR_INVALID_VALUE = -1
};

CYear::CYear()
{
	m_year = CYEAR_INVALID_VALUE;
}

CYear::CYear(const CYear &Ref)
{
	m_year = Ref.m_year;
}

CYear::CYear(long year)
{
	if(year < 1800)
		throw new CYearException();
	m_year = year;
}

CYear& CYear::operator=(const CYear &Ref)
{
	m_year = Ref.m_year;
	return *this;
}

CYear::~CYear()
{
}

long CYear::GetYear() const
{
	if(m_year == CYEAR_INVALID_VALUE)
		throw new CYearException();
	return m_year;
}

void CYear::SetYear(long year)
{
	if(year < 1800)
		throw new CYearException();
	m_year = year;
}

bool CYear::IsValidYear() const
{
	return m_year != CYEAR_INVALID_VALUE;
}

void CYear::SetInvalidYear()
{
	m_year = CYEAR_INVALID_VALUE;
}

bool CYear::IsLeapYear() const
{
	if(m_year%400 == 0)
		return true;
	if(m_year%100 == 0)
		return false;
	if(m_year%4 == 0)
		return true;
	return false;
}
