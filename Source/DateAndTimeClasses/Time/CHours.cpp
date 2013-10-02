#include "CHours.h"

using namespace GeyserEruptionCalc;

CHours::CHours() :
	m_hours(0)
{
}

CHours::CHours(const CHours &Ref) :
	m_hours(Ref.m_hours)
{
}

CHours::CHours(long hours) :
	m_hours(hours)
{
}

const CHours& CHours::operator=(const CHours &Ref)
{
	m_hours = Ref.m_hours;
	return *this;
}

CHours::~CHours()
{
}

bool CHours::operator==(const CHours &Ref) const
{
	return m_hours == Ref.m_hours;
}

bool CHours::operator!=(const CHours &Ref) const
{
	return m_hours != Ref.m_hours;
}

bool CHours::operator<(const CHours &Ref) const
{
	return m_hours < Ref.m_hours;
}

bool CHours::operator>(const CHours &Ref) const
{
	return m_hours > Ref.m_hours;
}

bool CHours::operator<=(const CHours &Ref) const
{
	return m_hours <= Ref.m_hours;
}

bool CHours::operator>=(const CHours &Ref) const
{
	return m_hours >= Ref.m_hours;
}

const CHours CHours::operator+(const CHours &Ref) const
{
	return CHours(m_hours + Ref.m_hours);
}

const CHours CHours::operator-(const CHours &Ref) const
{
	return CHours(m_hours - Ref.m_hours);
}

const CHours& CHours::operator+=(const CHours &Ref)
{
	m_hours += Ref.m_hours;
	return *this;
}

const CHours& CHours::operator-=(const CHours &Ref)
{
	m_hours -= Ref.m_hours;
	return *this;
}

const CHours& CHours::operator++()
{
	m_hours++;
	return *this;
}

const CHours& CHours::operator--()
{
	m_hours--;
	return *this;
}

const CHours CHours::operator++(int unused)
{
	m_hours++;
	return CHours(m_hours);
}

const CHours CHours::operator--(int unused)
{
	m_hours--;
	return CHours(m_hours);
}

void CHours::SetHours(long hours)
{
	m_hours = hours;
}

long CHours::GetHours() const
{
	return m_hours;
}

