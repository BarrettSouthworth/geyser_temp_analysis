#include "CSeconds.h"

using namespace GeyserEruptionCalc;

CSeconds::CSeconds() :
	m_seconds(0)
{
}

CSeconds::CSeconds(const CSeconds &Ref) :
	m_seconds(Ref.m_seconds)
{
}

CSeconds::CSeconds(long long seconds) :
	m_seconds(seconds)
{
}

const CSeconds& CSeconds::operator=(const CSeconds &Ref)
{
	m_seconds = Ref.m_seconds;
	return *this;
}

CSeconds::~CSeconds()
{
}

bool CSeconds::operator==(const CSeconds &Ref) const
{
	return m_seconds == Ref.m_seconds;
}

bool CSeconds::operator!=(const CSeconds &Ref) const
{
	return m_seconds != Ref.m_seconds;
}

bool CSeconds::operator<(const CSeconds &Ref) const
{
	return m_seconds < Ref.m_seconds;
}

bool CSeconds::operator>(const CSeconds &Ref) const
{
	return m_seconds > Ref.m_seconds;
}

bool CSeconds::operator<=(const CSeconds &Ref) const
{
	return m_seconds <= Ref.m_seconds;
}

bool CSeconds::operator>=(const CSeconds &Ref) const
{
	return m_seconds >= Ref.m_seconds;
}

const CSeconds CSeconds::operator+(const CSeconds &Ref) const
{
	return CSeconds(m_seconds + Ref.m_seconds);
}

const CSeconds CSeconds::operator-(const CSeconds &Ref) const
{
	return CSeconds(m_seconds - Ref.m_seconds);
}

const CSeconds& CSeconds::operator+=(const CSeconds &Ref)
{
	m_seconds += Ref.m_seconds;
	return *this;
}

const CSeconds& CSeconds::operator-=(const CSeconds &Ref)
{
	m_seconds -= Ref.m_seconds;
	return *this;
}

const CSeconds& CSeconds::operator++()
{
	m_seconds++;
	return *this;
}

const CSeconds& CSeconds::operator--()
{
	m_seconds--;
	return *this;
}

const CSeconds CSeconds::operator++(int unused)
{
	m_seconds++;
	return CSeconds(m_seconds);
}

const CSeconds CSeconds::operator--(int unused)
{
	m_seconds--;
	return CSeconds(m_seconds);
}

void CSeconds::SetSeconds(long long seconds)
{
	m_seconds = seconds;
}

long long CSeconds::GetSeconds() const
{
	return m_seconds;
}

