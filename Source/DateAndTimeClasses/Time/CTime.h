#pragma once
#include "TypeSafetyClasses\CHour.h"
#include "TypeSafetyClasses\CMinute.h"
#include "TypeSafetyClasses\CSecond.h"
#include "Exceptions\CTimeException.h"

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class represents a time value
	  */
	class CTime
	{
	public:
		/** Default constructor
		  * Sets all times to invalid
		  */
		CTime();
		/** Copy Constructor
		  * @param Ref - Reference to CTime to be copied
		  */
		CTime(const CTime &Ref);
		/** Constructor
		  * @param hour - hour value
		  * @param minute - minute value
		  * @param second - second value
		  */
		CTime(const CHour &hour, const CMinute &minute, const CSecond &second);
		/** Destructor
		  */
		~CTime();
		/** Assignment operator
		  * @param Ref - CTime to assign to current CTime
		  * @return Reference to current CTime
		  */
		CTime& operator=(const CTime &Ref);
		/** SetTime
		  * Sets the time
		  * @param hour - hour to set time to
		  * @param minute - minute to set time to
		  * @param second - second to set time to
		  */
		void SetTime(const CHour &hour, const CMinute &minute, const CSecond &second);
		/** SetHour
		  * Sets the hour
		  * @param hour - CHour to be used to set hour
		  */
		void SetHour(const CHour &hour);
		/** SetHour
		  * Sets the hour
		  * @param hour - hour to be used to set hour
		  * @throws CHourException if hour is out of range
		  */
		void SetHour(long hour);
		/** SetMinute
		  * Sets the minute
		  * @param minute - CMinute to be used to set minute
		  */
		void SetMinute(const CMinute &minute);
		/** SetMinute
		  * Sets the minute
		  * @param minute - value to be used to set minute
		  * @throws CMinuteException if minute is out of range
		  */
		void SetMinute(long minute);
		/** SetSecond
		  * Sets the second
		  * @param second - CSecond to be used to set minute
		  */
		void SetSecond(const CSecond &second);
		/** SetSecond
		  * Sets the second
		  * @param second - value to be used to set second
		  * @throws CSecondException if minute is out of range
		  */
		void SetSecond(long second);
		/** GetHour
		  * Retrieves hour
		  * @return CHour reference representing hour
		  * @throws CHourException if invalid CHour
		  */
		const CHour& GetHour() const;
		/** GetMinute
		  * Retrieves Minute
		  * @return CMinute reference representing minute
		  * @throws CMinuteException if invalid CMinute
		  */
		const CMinute& GetMinute() const;
		/** GetSecond
		  * Retrieves Seconds
		  * @return CSecond reference representing second
		  * @throws CSecondException if invalid CSecond
		  */
		const CSecond& GetSecond() const;
		/** operator==
		  * Compares two CTimes for equality
		  * @param Ref - CTime to compare to
		  * @return true if equal, false otherwise
		  * @throws CTimeException if either this or Ref are invalid CTimes
		  */
		bool operator==(const CTime &Ref) const;
		/** operator!=
		  * Compares two CTimes for non equality
		  * @param Ref - CTime to compare to
		  * @return true if not equal, false otherwise
		  * @throws CTimeException if either this or Ref are invalid CTimes
		  */
		bool operator!=(const CTime &Ref) const;
		/** operator<
		  * Compares two CTimes for this < Ref
		  * @param Ref - CTime to compare to
		  * @return true if this < Ref, false otherwise
		  * @throws CTimeException if either this or Ref are invalid CTimes
		  */
		bool operator<(const CTime &Ref) const;
		/** operator>
		  * Compares two CTimes for this > Ref
		  * @param Ref - CTime to compare to
		  * @return true if this > Ref, false otherwise
		  * @throws CTimeException if either this or Ref are invalid CTimes
		  */
		bool operator>(const CTime &Ref) const;
		/** operator<=
		  * Compares two CTimes for less than or equal
		  * @param Ref - CTime to compare to
		  * @return true if this <= Ref, false otherwise
		  * @throws CTimeException if either this or Ref are invalid CTimes
		  */
		bool operator<=(const CTime &Ref) const;
		/** operator>=
		  * Compares two CTimes for greater than or equal
		  * @param Ref - CTime to compare to
		  * @return true if this >= Ref, false otherwise
		  * @throws CTimeException if either this or Ref are invalid CTimes
		  */
		bool operator>=(const CTime &Ref) const;
		/** IsValidTime
		  * Checks to see if time is fully initialized
		  * @return true if time is valid
		  */
		bool IsValidTime() const;
	private:
		/** CheckValidityWithThrows
		  * Internal function for checking to see if current and Reference CTime are valid
		  * @param Ref - CTime Reference
		  * @throws CTimeException if one of the two isn't valid
		  */
		void CheckValidityWithThrows(const CTime &Ref) const;
	private:
		/** Hour unit
		  */
		CHour m_hour;
		/** Minute unit
		  */
		CMinute m_minute;
		/** Second unit
		  */
		CSecond m_second;
	};
};
