#include "CDays.h"

using namespace GeyserEruptionCalc;

CDays::CDays() :
	m_days(0)
{
}

CDays::CDays(const CDays &Ref) :
	m_days(Ref.m_days)
{
}

CDays::CDays(long days) :
	m_days(days)
{
}

const CDays& CDays::operator=(const CDays &Ref)
{
	m_days = Ref.m_days;
	return *this;
}

CDays::~CDays()
{
}

bool CDays::operator==(const CDays &Ref) const
{
	return m_days == Ref.m_days;
}

bool CDays::operator!=(const CDays &Ref) const
{
	return m_days != Ref.m_days;
}

bool CDays::operator<(const CDays &Ref) const
{
	return m_days < Ref.m_days;
}

bool CDays::operator>(const CDays &Ref) const
{
	return m_days > Ref.m_days;
}

bool CDays::operator<=(const CDays &Ref) const
{
	return m_days <= Ref.m_days;
}

bool CDays::operator>=(const CDays &Ref) const
{
	return m_days >= Ref.m_days;
}

const CDays CDays::operator+(const CDays &Ref) const
{
	return CDays(m_days + Ref.m_days);
}

const CDays CDays::operator-(const CDays &Ref) const
{
	return CDays(m_days - Ref.m_days);
}

const CDays& CDays::operator+=(const CDays &Ref)
{
	m_days += Ref.m_days;
	return *this;
}

const CDays& CDays::operator-=(const CDays &Ref)
{
	m_days -= Ref.m_days;
	return *this;
}

const CDays& CDays::operator++()
{
	m_days++;
	return *this;
}

const CDays& CDays::operator--()
{
	m_days--;
	return *this;
}

const CDays CDays::operator++(int unused)
{
	m_days++;
	return CDays(m_days);
}

const CDays CDays::operator--(int unused)
{
	m_days--;
	return CDays(m_days);
}

void CDays::SetDays(long days)
{
	m_days = days;
}

long CDays::GetDays() const
{
	return m_days;
}

