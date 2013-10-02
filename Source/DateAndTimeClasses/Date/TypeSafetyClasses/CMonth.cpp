#include "CMonth.h"

using namespace GeyserEruptionCalc;

enum CMONTH_INVALID
{
	CMONTH_INVALID_VALUE = -1
};

CMonth::CMonth()
{
	m_month = CMONTH_INVALID_VALUE;
}

CMonth::CMonth(const CMonth &Ref)
{
	m_month = Ref.m_month;
}

CMonth::CMonth(long month)
{
	if(month < 1 || month > 12)
		throw new CMonthException();
	m_month = month;
}

CMonth& CMonth::operator=(const CMonth &Ref)
{
	m_month = Ref.m_month;
	return *this;
}

CMonth::~CMonth()
{
}

long CMonth::GetMonth() const
{
	if(m_month == CMONTH_INVALID_VALUE)
		throw new CMonthException();
	return m_month;
}

void CMonth::SetMonth(long month)
{
	if(month < 1 || month > 12)
		throw new CMonthException();
	m_month = month;
}

bool CMonth::IsValidMonth() const
{
	return m_month != CMONTH_INVALID_VALUE;
}

void CMonth::SetInvalidMonth()
{
	m_month = CMONTH_INVALID_VALUE;
}
