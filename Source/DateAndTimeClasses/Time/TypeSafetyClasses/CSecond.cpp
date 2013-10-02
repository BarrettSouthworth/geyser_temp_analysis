#include "CSecond.h"

using namespace GeyserEruptionCalc;

enum CSECOND_INVALID
{
	CSECOND_INVALID_VALUE = -1
};

CSecond::CSecond()
{
	m_second = CSECOND_INVALID_VALUE;
}

CSecond::CSecond(const CSecond &Ref)
{
	m_second = Ref.m_second;
}

CSecond::CSecond(long second)
{
	if(second < 0 || second > 59)
		throw new CSecondException();
	m_second = second;
}

CSecond& CSecond::operator=(const CSecond &Ref)
{
	m_second = Ref.m_second;
	return *this;
}

CSecond::~CSecond()
{
}

long CSecond::GetSecond() const
{
	if(m_second == CSECOND_INVALID_VALUE)
		throw new CSecondException();
	return m_second;
}

void CSecond::SetSecond(long second)
{
	if(second < 0 || second > 59)
		throw new CSecondException();
	m_second = second;
}

bool CSecond::IsValidSecond() const
{
	return m_second != CSECOND_INVALID_VALUE;
}

void CSecond::SetInvalidSecond()
{
	m_second = CSECOND_INVALID_VALUE;
}
