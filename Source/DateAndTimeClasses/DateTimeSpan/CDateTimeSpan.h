#pragma once
#include "Exceptions\CDateTimeSpanException.h"

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class represents a DateTimeSpan
	  */
	class CDateTimeSpan
	{
	public:
		CDateTimeSpan();
		CDateTimeSpan(const CDateTimeSpan &Ref);
		CDateTimeSpan(long long seconds);
		const CDateTimeSpan& operator=(const CDateTimeSpan &Ref);
		~CDateTimeSpan();
		void SetSpan(long long seconds);
		long long GetSpan() const;
	private:
		long long m_seconds;
	};
}
