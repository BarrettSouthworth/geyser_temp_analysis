#include "CTime.h"

using namespace GeyserEruptionCalc;

CTime::CTime() :
	m_hour(),
	m_minute(),
	m_second()
{
}

CTime::CTime(const CTime &Ref) :
	m_hour(Ref.m_hour),
	m_minute(Ref.m_minute),
	m_second(Ref.m_second)
{
}

CTime::CTime(const CHour &hour, const CMinute &minute, const CSecond &second) :
	m_hour(hour),
	m_minute(minute),
	m_second(second)
{
}

CTime::~CTime()
{
}

CTime& CTime::operator=(const CTime &Ref)
{
	m_hour = Ref.m_hour;
	m_minute = Ref.m_minute;
	m_second = Ref.m_second;
	return *this;
}

void CTime::SetTime(const CHour &hour, const CMinute &minute, const CSecond &second)
{
	m_hour = hour;
	m_minute = minute;
	m_second = second;
}

void CTime::SetHour(const CHour &hour)
{
	m_hour = hour;
}

void CTime::SetHour(long hour)
{
	m_hour.SetHour(hour);
}

void CTime::SetMinute(const CMinute &minute)
{
	m_minute = minute;
}

void CTime::SetMinute(long minute)
{
	m_minute.SetMinute(minute);
}

void CTime::SetSecond(const CSecond &second)
{
	m_second = second;
}

void CTime::SetSecond(long second)
{
	m_second.SetSecond(second);
}

const CHour& CTime::GetHour() const
{
	if(!m_hour.IsValidHour())
		throw new CHourException();
	return m_hour;
}

const CMinute& CTime::GetMinute() const
{
	if(!m_minute.IsValidMinute())
		throw new CMinuteException();
	return m_minute;
}

const CSecond& CTime::GetSecond() const
{
	if(!m_second.IsValidSecond())
		throw new CSecondException();
	return m_second;
}

bool CTime::operator==(const CTime &Ref) const
{
	CheckValidityWithThrows(Ref);
	if(m_hour.GetHour() == Ref.m_hour.GetHour() &&
		m_minute.GetMinute() == Ref.m_minute.GetMinute() &&
		m_second.GetSecond() == Ref.m_second.GetSecond())
	{
		return true;
	}
	return false;
}

bool CTime::operator!=(const CTime &Ref) const
{
	CheckValidityWithThrows(Ref);
	return !(*this == Ref);
}

bool CTime::operator<(const CTime &Ref) const
{
	CheckValidityWithThrows(Ref);
	if(*this == Ref)
		return false;
	if(m_hour.GetHour() > Ref.m_hour.GetHour())
		return false;
	else if(m_hour.GetHour() < Ref.m_hour.GetHour())
		return true;
	if(m_minute.GetMinute() > Ref.m_minute.GetMinute())
		return false;
	else if(m_minute.GetMinute() > Ref.m_minute.GetMinute())
		return true;
	if(m_second.GetSecond() > Ref.m_second.GetSecond())
		return false;
	return true;
}

bool CTime::operator>(const CTime &Ref) const
{
	CheckValidityWithThrows(Ref);
	if(*this == Ref)
		return false;
	return !(*this < Ref);
}


bool CTime::operator<=(const CTime &Ref) const
{
	CheckValidityWithThrows(Ref);
	if(*this==Ref)
		return true;
	if(*this<Ref)
		return true;
	return false;
}

bool CTime::operator>=(const CTime &Ref) const
{
	CheckValidityWithThrows(Ref);
	if(*this == Ref)
		return true;
	if(*this > Ref)
		return true;
	return false;
}

bool CTime::IsValidTime() const
{
	if(m_hour.IsValidHour() && m_minute.IsValidMinute() && m_second.IsValidSecond())
		return true;
	return false;
}

void CTime::CheckValidityWithThrows(const CTime &Ref) const
{
	if(!IsValidTime())
		throw new CTimeException();
	if(!Ref.IsValidTime())
		throw new CTimeException();
}

