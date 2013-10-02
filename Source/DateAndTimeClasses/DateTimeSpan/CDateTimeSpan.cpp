#include "CDateTimeSpan.h"

using namespace GeyserEruptionCalc;

CDateTimeSpan::CDateTimeSpan() :
	m_seconds(0)
{
}

CDateTimeSpan::CDateTimeSpan(const CDateTimeSpan &Ref) :
	m_seconds(Ref.m_seconds)
{
}

CDateTimeSpan::CDateTimeSpan(long long seconds) :
	m_seconds(seconds)
{
}

const CDateTimeSpan& CDateTimeSpan::operator=(const CDateTimeSpan &Ref)
{
	m_seconds = Ref.m_seconds;
	return *this;
}

CDateTimeSpan::~CDateTimeSpan()
{
}

void CDateTimeSpan::SetSpan(long long seconds)
{
	m_seconds = seconds;
}

long long CDateTimeSpan::GetSpan() const
{
	return m_seconds;
}

