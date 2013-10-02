#pragma once
#include "..\Exceptions\CSecondException.h"

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class Represents a single second
	  */
	class CSecond
	{
	public:
		/** Default Constructor
		  * Constructs CSecond as an invalid second
		  */
		CSecond();
		/** Constructor
		  * Copies another CSecond
		  * @param Ref - CSecond to copy
		  */
		CSecond(const CSecond &Ref);
		/** Constructor
		  * Constructs CSecond with given second value
		  * @param second - second value msut be in range 0 to 59
		  * @throws CSecondException when second is out of range
		  */
		CSecond(long second);
		/** Assignment operator
		  * @param Ref - Reference to CSecond to assign value from
		  * @return Reference to current CSecond
		  */
		CSecond& operator=(const CSecond &Ref);
		/** Destructor
		  */
		~CSecond();
		/** GetSecond
		  * Retrieves the value of the second
		  * @return value of the second
		  * @throws CSecondException when Second is invalid
		  */
		long GetSecond() const;
		/** SetSecond
		  * Sets the second with a value from 0 to 59
		  * @param second - value to set to
		  * @throws CSecondException when value is out of range
		  */
		void SetSecond(long second);
		/** IsValidSecond
		  * Checks to see if the second is valid
		  */
		bool IsValidSecond() const;
		/** SetInvalidSecond
		  * Marks the second as invalid
		  */
		void SetInvalidSecond();
	private:
		/** Represents the value of a second for a time value
		  */
		long m_second;
	};
};
