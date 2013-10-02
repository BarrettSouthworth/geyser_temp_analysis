#pragma once
#include "..\Exceptions\CDayException.h"

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class Represents a single day
	  */
	class CDay
	{
	public:
		/** Default Constructor
		  * Constructs CDay as an invalid day
		  */
		CDay();
		/** Constructor
		  * Copies another CDay
		  * @param Ref - CDay to copy
		  */
		CDay(const CDay &Ref);
		/** Constructor
		  * Constructs CDay with given day value
		  * @param day - day value msut be in range 1 to 31
		  * @throws CDayException when day is out of range
		  */
		CDay(long day);
		/** Assignment operator
		  * @param Ref - Reference to CDay to assign value from
		  * @return Reference to current CDay
		  */
		CDay& operator=(const CDay &Ref);
		/** Destructor
		  */
		~CDay();
		/** GetDay
		  * Retrieves the value of the day
		  * @return value of the day
		  * @throws CDayException when Day is invalid
		  */
		long GetDay() const;
		/** SetDay
		  * Sets the day with a value from 1 to 31
		  * @param day - value to set to
		  * @throws CDayException when value is out of range
		  */
		void SetDay(long day);
		/** IsValidDay
		  * Checks to see if the day is valid
		  */
		bool IsValidDay() const;
		/** SetInvalidDay
		  * Marks the day as invalid
		  */
		void SetInvalidDay();
	private:
		/** Represents the value of a day for a time value
		  */
		long m_day;
	};
};
