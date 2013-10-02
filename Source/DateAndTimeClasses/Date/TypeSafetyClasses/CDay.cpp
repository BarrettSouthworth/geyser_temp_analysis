#include "CDay.h"

using namespace GeyserEruptionCalc;

enum CDAY_INVALID
{
	CDAY_INVALID_VALUE = -1
};

CDay::CDay()
{
	m_day = CDAY_INVALID_VALUE;
}

CDay::CDay(const CDay &Ref)
{
	m_day = Ref.m_day;
}

CDay::CDay(long day)
{
	if(day < 1 || day > 31)
		throw new CDayException();
	m_day = day;
}

CDay& CDay::operator=(const CDay &Ref)
{
	m_day = Ref.m_day;
	return *this;
}

CDay::~CDay()
{
}

long CDay::GetDay() const
{
	if(m_day == CDAY_INVALID_VALUE)
		throw new CDayException();
	return m_day;
}

void CDay::SetDay(long day)
{
	if(day < 1 || day > 31)
		throw new CDayException();
	m_day = day;
}

bool CDay::IsValidDay() const
{
	return m_day != CDAY_INVALID_VALUE;
}

void CDay::SetInvalidDay()
{
	m_day = CDAY_INVALID_VALUE;
}
