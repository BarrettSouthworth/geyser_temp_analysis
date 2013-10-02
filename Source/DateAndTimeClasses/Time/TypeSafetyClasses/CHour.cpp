#include "CHour.h"

using namespace GeyserEruptionCalc;

enum CHOUR_INVALID
{
	CHOUR_INVALID_VALUE = -1
};

CHour::CHour()
{
	m_hour = CHOUR_INVALID_VALUE;
}

CHour::CHour(const CHour &Ref)
{
	m_hour = Ref.m_hour;
}

CHour::CHour(long hour)
{
	if(hour < 0 || hour > 23)
		throw new CHourException();
	m_hour = hour;
}

CHour& CHour::operator=(const CHour &Ref)
{
	m_hour = Ref.m_hour;
	return *this;
}

CHour::~CHour()
{
}

long CHour::GetHour() const
{
	if(m_hour == CHOUR_INVALID_VALUE)
		throw new CHourException();
	return m_hour;
}

void CHour::SetHour(long hour)
{
	if(hour < 0 || hour > 23)
		throw new CHourException();
	m_hour = hour;
}

bool CHour::IsValidHour() const
{
	return m_hour != CHOUR_INVALID_VALUE;
}

void CHour::SetInvalidHour()
{
	m_hour = CHOUR_INVALID_VALUE;
}
