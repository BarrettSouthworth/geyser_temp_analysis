#pragma once
#include "..\Exceptions\CHourException.h"

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class Represents a single hour
	  */
	class CHour
	{
	public:
		/** Default Constructor
		  * Constructs CHour as an invalid hour
		  */
		CHour();
		/** Constructor
		  * Copies another CHour
		  * @param Ref - CHour to copy
		  */
		CHour(const CHour &Ref);
		/** Constructor
		  * Constructs CHour with given hour value
		  * @param hour - hour value msut be in range 0 to 23
		  * @throws CHourException when hour is out of range
		  */
		CHour(long hour);
		/** Assignment operator
		  * @param Ref - Reference to CHour to assign value from
		  * @return Reference to current CHour
		  */
		CHour& operator=(const CHour &Ref);
		/** Destructor
		  */
		~CHour();
		/** GetHour
		  * Retrieves the value of the hour
		  * @return value of the hour
		  * @throws CHourException when Hour is invalid
		  */
		long GetHour() const;
		/** SetHour
		  * Sets the hour with a value from 0 to 23
		  * @param hour - value to set to
		  * @throws CHourException when value is out of range
		  */
		void SetHour(long hour);
		/** IsValidHour
		  * Checks to see if the hour is valid
		  */
		bool IsValidHour() const;
		/** SetInvalidHour
		  * Marks the hour as invalid
		  */
		void SetInvalidHour();
	private:
		/** Represents the value of a hour for a time value
		  */
		long m_hour;
	};
};
