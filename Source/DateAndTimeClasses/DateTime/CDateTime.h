#pragma once
#include "Exceptions\CDateTimeException.h"
#include "..\Date\CDate.h"
#include "..\Time\CTime.h"
#include "..\Date\CDays.h"
#include "..\Time\CHours.h"
#include "..\Time\CMinutes.h"
#include "..\Time\CSeconds.h"

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Forward Declaration for a DateTimeSpan
	  */
	class CDateTimeSpan;
	/** Class represents a DateTime
	  * It eliminates Daylights savings time internally, and output would have to request adjustment
	  * All Sunrise/Sunset/Moonrise/MoonSet calcs are for Old Faithfuls, longitude/latitude
	  */
	class CDateTime
	{
	public:
		CDateTime();
		CDateTime(const CDateTime &Ref);
		CDateTime(const CDate &date, const CTime &time, bool IsDST=false);
		~CDateTime();
		const CDateTime& operator=(const CDateTime &Ref);
		void SetDate(const CDate &date);
		void SetTime(const CTime &time);
		const CDate& GetDate() const;
		const CTime& GetTime() const;
		void AddDays(long days);
		void AddMonths(long months);
		void AddHours(long hours);
		static const CDateTime DSTStart(const CYear &year);
		static const CDateTime DSTEnd(const CYear &year);
		static const CDateTime NthDayOfWeek(const CYear &year, const CMonth &month, DAYOFWEEK weekday, int n);
		static const CDateTime LastDayOfWeekInMonth(const CYear &year, const CMonth &month, DAYOFWEEK weekday);
		/*const CDateTime SunRise() const;
		const CDateTime SunSet() const;
		const CDateTime MoonRise() const;
		const CDateTime MoonSet() const;*/
		bool operator==(const CDateTime &Ref) const;
		bool operator!=(const CDateTime &Ref) const;
		bool operator<(const CDateTime &Ref) const;
		bool operator>(const CDateTime &Ref) const;
		bool operator>=(const CDateTime &Ref) const;
		bool operator<=(const CDateTime &Ref) const;
		const CDateTimeSpan operator-(const CDateTime &Ref) const;
		const CDateTime operator+(const CDateTimeSpan &Ref) const;
		const CDateTime operator-(const CDateTimeSpan &Ref) const;
		const CDateTime& operator+=(const CDateTimeSpan &Ref);
		const CDateTime& operator-=(const CDateTimeSpan &Ref);
		const CDateTime operator+(const CDays &Ref) const;
		const CDateTime operator-(const CDays &Ref) const;
		const CDateTime& operator+=(const CDays &Ref);
		const CDateTime& operator-=(const CDays &Ref);
		const CDateTime operator+(const CHours &Ref) const;
		const CDateTime operator-(const CHours &Ref) const;
		const CDateTime& operator+=(const CHours &Ref);
		const CDateTime& operator-=(const CHours &Ref);
		const CDateTime operator+(const CMinutes &Ref) const;
		const CDateTime operator-(const CMinutes &Ref) const;
		const CDateTime& operator+=(const CMinutes &Ref);
		const CDateTime& operator-=(const CMinutes &Ref);
		const CDateTime operator+(const CSeconds &Ref) const;
		const CDateTime operator-(const CSeconds &Ref) const;
		const CDateTime& operator+=(const CSeconds &Ref);
		const CDateTime& operator-=(const CSeconds &Ref);
		bool IsValidDateTime() const;
	private:
		void CheckValidDateTimeWithThrows() const;
		void IncMonth();
		void DecMonth();
	private:
		CDate m_date;
		CTime m_time;
	};
};
