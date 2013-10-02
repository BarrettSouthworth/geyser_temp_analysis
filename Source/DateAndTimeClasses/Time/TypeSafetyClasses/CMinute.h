#pragma once
#include "..\Exceptions\CMinuteException.h"

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class Represents a single minute
	  */
	class CMinute
	{
	public:
		/** Default Constructor
		  * Constructs CMinute as an invalid minute
		  */
		CMinute();
		/** Constructor
		  * Copies another CMinute
		  * @param Ref - CMinute to copy
		  */
		CMinute(const CMinute &Ref);
		/** Constructor
		  * Constructs CMinute with given minute value
		  * @param minute - minute value msut be in range 0 to 59
		  * @throws CMinuteException when minute is out of range
		  */
		CMinute(long minute);
		/** Assignment operator
		  * @param Ref - Reference to CMinute to assign value from
		  * @return Reference to current CMinute
		  */
		CMinute& operator=(const CMinute &Ref);
		/** Destructor
		  */
		~CMinute();
		/** GetMinute
		  * Retrieves the value of the minute
		  * @return value of the minute
		  * @throws CMinuteException when Minute is invalid
		  */
		long GetMinute() const;
		/** SetMinute
		  * Sets the minute with a value from 0 to 59
		  * @param minute - value to set to
		  * @throws CMinuteException when value is out of range
		  */
		void SetMinute(long minute);
		/** IsValidMinute
		  * Checks to see if the minute is valid
		  */
		bool IsValidMinute() const;
		/** SetInvalidMinute
		  * Marks the minute as invalid
		  */
		void SetInvalidMinute();
	private:
		/** Represents the value of a minute for a time value
		  */
		long m_minute;
	};
};
