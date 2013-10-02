#pragma once
#include "Exceptions\CDateException.h"
#include "TypeSafetyClasses\CDay.h"
#include "TypeSafetyClasses\CMonth.h"
#include "TypeSafetyClasses\CYear.h"

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** enum DAYOFWEEK
	  * Represents a particular day of the week
	  */
	enum DAYOFWEEK
	{
		/** Sunday
		  */
		ESUNDAY = 0,
		/** Monday
		  */
		EMONDAY = 1,
		/** Tuesday
		  */
		ETUESDAY = 2,
		/** Wednesday
		  */
		EWEDNESDAY = 3,
		/** Thursday
		  */
		ETHURSDAY = 4,
		/** Friday
		  */
		EFRIDAY = 5,
		/** Saturday
		  */
		ESATURDAY = 6
	};
	/** Class represents a data value
	  */
	class CDate
	{
	public:
		/** Constructor
		  * Sets all values as invalid
		  */
		CDate();
		/** Copy Constructor
		  * @param Ref - Reference to CDate to copy
		  */
		CDate(const CDate &Ref);
		/** Constructor
		  * @param year - year to set to
		  * @param month - month to set to
		  * @param day - day to set to
		  */
		CDate(const CYear &year, const CMonth &month, const CDay &day);
		/** Destructor
		  */
		~CDate();
		/** Assignment operator
		  * Set current date equal to another
		  * @param Ref - CDate date to set to
		  * @return Reference to current date
		  */
		const CDate& operator=(const CDate &Ref);
		/** SetDate
		  * Set all date values
		  * @param year - year to set to
		  * @param month - month to set to
		  * @param day - day to set to
		  */
		void SetDate(const CYear &year, const CMonth &month, const CDay &day);
		/** SetYear
		  * @param year - year to set to
		  */
		void SetYear(const CYear &year);
		/** SetYear
		  * Sets year based on long value
		  * @param year - year to set to
		  * @throws CYearException if invalid year
		  */
		void SetYear(long year);
		/** SetDay
		  * @param day - day to set to
		  */
		void SetMonth(const CMonth &month);
		/** SetMonth
		  * Sets month based on long value
		  * @param month - month to set to
		  * @throws CMonthException if invalid month
		  */
		void SetMonth(long month);
		/** SetYear
		  * @param day - day to set to
		  */
		void SetDay(const CDay &day);
		/** SetDay
		  * Sets day based on long value
		  * @param day - day to set to
		  * @throws CDayException if invalid day
		  */
		void SetDay(long day);
		/** GetYear
		  * Retrieves year
		  * @return CYear representing Year
		  * @throws CYearException if invalid year
		  */
		const CYear& GetYear() const;
		/** GetMonth
		  * Retrieves month
		  * @return CMonth representing Month
		  * @throws CMonthException if invalid month
		  */
		const CMonth& GetMonth() const;
		/** GetDay
		  * Retrieves day
		  * @return CDay representing Day
		  * @throws CDayException if invalid day
		  */
		const CDay& GetDay() const;
		/** operator==
		  * Compares two CDates for equality
		  * @param Ref - CDate to compare to
		  * @return true if equal, false otherwise
		  * @throws CDateException if either current CDate or given CDate are invalid
		  */
		bool operator==(const CDate &Ref) const;
		/** operator!=
		  * Compares two CDates for non-equality
		  * @param Ref - CDate to compare to
		  * @return true if not equal, false otherwise
		  * @throws CDateException if either current CDate or given CDate are invalid
		  */
		bool operator!=(const CDate &Ref) const;
		/** operator<
		  * Compares two CDates for less than
		  * @param Ref - CDate to compare to
		  * @return true if this < CDate, false otherwise
		  * @throws CDateException if either current CDate or given CDate are invalid
		  */
		bool operator<(const CDate &Ref) const;
		/** operator>
		  * Compares two CDates for greater than
		  * @param Ref - CDate to compare to
		  * @return true if this > CDate, false otherwise
		  * @throws CDateException if either current CDate or given CDate are invalid
		  */
		bool operator>(const CDate &Ref) const;
		/** operator<=
		  * Compares two CDates for less than or equal
		  * @param Ref - CDate to compare to
		  * @return true if this <= Ref, false otherwise
		  * @throws CDateException if either current CDate or given CDate are invalid
		  */
		bool operator<=(const CDate &Ref) const;
		/** operator>=
		  * Compares two CDates for greater than or equal
		  * @param Ref - CDate to compare to
		  * @return true if this >= Ref, false otherwise
		  * @throws CDateException if either current CDate or given CDate are invalid
		  */
		bool operator>=(const CDate &Ref) const;
		/** IsValidDate
		  * @return true if it is a valid date, false otherwise
		  */
		bool IsValidDate() const;
		/** GetDayOfWeek
		  * @param Ref - CDate to get day of the week for
		  * @return DAYOFWEEK the day of the week
		  * @throws CDateException if invalid date
		  */
		static DAYOFWEEK GetDayOfWeek(const CDate &Ref);
		/** GetDaysInMonth
		  * Returns number of days in the supplied month
		  * @return number of days in the month
		  * @throws CDateException if invalid date
		  */
		long GetDaysInMonth() const;
		/** GetDaysInYear 
		  * @return number of days in the year
		  * @throws CDateException if invalid date
		  */
		long GetDaysInYear() const;
		/** GetDayOfYear 
		  * @return current day of the year
		  * @throws CDateException if invalid date
		  */
		long GetDayOfYear() const;
	private:
		/** CheckValidityWithThrows
		  * Checks to see if it is a valid date and throws an exception if it isn't
		  */
		void CheckValidityWithThrows() const;
	private:
		/** year value
		  */
		CYear m_year;
		/** Month Value
		  */
		CMonth m_month;
		/** Day Value
		  */
		CDay m_day;
	};
};
