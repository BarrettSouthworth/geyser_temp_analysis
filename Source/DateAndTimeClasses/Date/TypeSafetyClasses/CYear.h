#pragma once
#include "..\Exceptions\CYearException.h"

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class Represents a single year
	  */
	class CYear
	{
	public:
		/** Default Constructor
		  * Constructs CYear as an invalid year
		  */
		CYear();
		/** Constructor
		  * Copies another CYear
		  * @param Ref - CYear to copy
		  */
		CYear(const CYear &Ref);
		/** Constructor
		  * Constructs CYear with given year value
		  * @param year - year value msut be in range > 1800
		  * @throws CYearException when year is out of range
		  */
		CYear(long year);
		/** Assignment operator
		  * @param Ref - Reference to CYear to assign value from
		  * @return Reference to current CYear
		  */
		CYear& operator=(const CYear &Ref);
		/** Destructor
		  */
		~CYear();
		/** GetYear
		  * Retrieves the value of the year
		  * @return value of the year
		  * @throws CYearException when Year is invalid
		  */
		long GetYear() const;
		/** SetYear
		  * Sets the year with a value 1800 or higher
		  * @param year - value to set to
		  * @throws CYearException when value is out of range
		  */
		void SetYear(long year);
		/** IsValidYear
		  * Checks to see if the year is valid
		  */
		bool IsValidYear() const;
		/** SetInvalidYear
		  * Marks the year as invalid
		  */
		void SetInvalidYear();
		/** IsLeapYear
		  * reports if the year is a leap year
		  * @return true if it is a leap year, false otherwise
		  */
		bool IsLeapYear() const;
	private:
		/** Represents the value of a year for a time value
		  */
		long m_year;
	};
};
