#pragma once
#include "..\Exceptions\CMonthException.h"

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class Represents a single month
	  */
	class CMonth
	{
	public:
		/** Default Constructor
		  * Constructs CMonth as an invalid month
		  */
		CMonth();
		/** Constructor
		  * Copies another CMonth
		  * @param Ref - CMonth to copy
		  */
		CMonth(const CMonth &Ref);
		/** Constructor
		  * Constructs CMonth with given month value
		  * @param month - month value msut be in range 1 to 12
		  * @throws CMonthException when month is out of range
		  */
		CMonth(long month);
		/** Assignment operator
		  * @param Ref - Reference to CMonth to assign value from
		  * @return Reference to current CMonth
		  */
		CMonth& operator=(const CMonth &Ref);
		/** Destructor
		  */
		~CMonth();
		/** GetMonth
		  * Retrieves the value of the month
		  * @return value of the month
		  * @throws CMonthException when Month is invalid
		  */
		long GetMonth() const;
		/** SetMonth
		  * Sets the month with a value from 1 to 12
		  * @param month - value to set to
		  * @throws CMonthException when value is out of range
		  */
		void SetMonth(long month);
		/** IsValidMonth
		  * Checks to see if the month is valid
		  */
		bool IsValidMonth() const;
		/** SetInvalidMonth
		  * Marks the month as invalid
		  */
		void SetInvalidMonth();
	private:
		/** Represents the value of a month for a time value
		  */
		long m_month;
	};
};
