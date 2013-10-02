#include "CMinutes.h"

using namespace GeyserEruptionCalc;

CMinutes::CMinutes() :
	m_minutes(0)
{
}

CMinutes::CMinutes(const CMinutes &Ref) :
	m_minutes(Ref.m_minutes)
{
}

CMinutes::CMinutes(long minutes) :
	m_minutes(minutes)
{
}

const CMinutes& CMinutes::operator=(const CMinutes &Ref)
{
	m_minutes = Ref.m_minutes;
	return *this;
}

CMinutes::~CMinutes()
{
}

bool CMinutes::operator==(const CMinutes &Ref) const
{
	return m_minutes == Ref.m_minutes;
}

bool CMinutes::operator!=(const CMinutes &Ref) const
{
	return m_minutes != Ref.m_minutes;
}

bool CMinutes::operator<(const CMinutes &Ref) const
{
	return m_minutes < Ref.m_minutes;
}

bool CMinutes::operator>(const CMinutes &Ref) const
{
	return m_minutes > Ref.m_minutes;
}

bool CMinutes::operator<=(const CMinutes &Ref) const
{
	return m_minutes <= Ref.m_minutes;
}

bool CMinutes::operator>=(const CMinutes &Ref) const
{
	return m_minutes >= Ref.m_minutes;
}

const CMinutes CMinutes::operator+(const CMinutes &Ref) const
{
	return CMinutes(m_minutes + Ref.m_minutes);
}

const CMinutes CMinutes::operator-(const CMinutes &Ref) const
{
	return CMinutes(m_minutes - Ref.m_minutes);
}

const CMinutes& CMinutes::operator+=(const CMinutes &Ref)
{
	m_minutes += Ref.m_minutes;
	return *this;
}

const CMinutes& CMinutes::operator-=(const CMinutes &Ref)
{
	m_minutes -= Ref.m_minutes;
	return *this;
}

const CMinutes& CMinutes::operator++()
{
	m_minutes++;
	return *this;
}

const CMinutes& CMinutes::operator--()
{
	m_minutes--;
	return *this;
}

const CMinutes CMinutes::operator++(int unused)
{
	m_minutes++;
	return CMinutes(m_minutes);
}

const CMinutes CMinutes::operator--(int unused)
{
	m_minutes--;
	return CMinutes(m_minutes);
}

void CMinutes::SetMinutes(long minutes)
{
	m_minutes = minutes;
}

long CMinutes::GetMinutes() const
{
	return m_minutes;
}

