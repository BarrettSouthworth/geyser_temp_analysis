#include "CMinute.h"

using namespace GeyserEruptionCalc;

enum CMINUTE_INVALID
{
	CMINUTE_INVALID_VALUE = -1
};

CMinute::CMinute()
{
	m_minute = CMINUTE_INVALID_VALUE;
}

CMinute::CMinute(const CMinute &Ref)
{
	m_minute = Ref.m_minute;
}

CMinute::CMinute(long minute)
{
	if(minute < 0 || minute > 59)
		throw new CMinuteException();
	m_minute = minute;
}

CMinute& CMinute::operator=(const CMinute &Ref)
{
	m_minute = Ref.m_minute;
	return *this;
}

CMinute::~CMinute()
{
}

long CMinute::GetMinute() const
{
	if(m_minute == CMINUTE_INVALID_VALUE)
		throw new CMinuteException();
	return m_minute;
}

void CMinute::SetMinute(long minute)
{
	if(minute < 0 || minute > 59)
		throw new CMinuteException();
	m_minute = minute;
}

bool CMinute::IsValidMinute() const
{
	return m_minute != CMINUTE_INVALID_VALUE;
}

void CMinute::SetInvalidMinute()
{
	m_minute = CMINUTE_INVALID_VALUE;
}
