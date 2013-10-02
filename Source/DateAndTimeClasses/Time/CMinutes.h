#pragma once

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class Represents any number of minutes
	  */
	class CMinutes
	{
	public:
		/** Defualt Constructor
		  */
		CMinutes();
		/** Copy Constructor
		  * @param Ref - CMinutes to copy
		  */
		CMinutes(const CMinutes &Ref);
		/** Constructor
		  * @param minutes - minutes to set CMinutes to
		  */
		CMinutes(long minutes);
		/** Assignment operator
		  * @param Ref - CMinutes to assign from
		  * @return Reference to current CMinutes
		  */
		const CMinutes& operator=(const CMinutes &Ref);
		/** Destructor
		  */
		~CMinutes();
		/** operator==
		  * @param Ref - Reference to CMinutes to compare to
		  * @return true if this == Ref, false otherwise
		  */
		bool operator==(const CMinutes &Ref) const;
		/** operator!=
		  * @param Ref - Reference to CMinutes to compare to
		  * @return true if this != Ref, false otherwise
		  */
		bool operator!=(const CMinutes &Ref) const;
		/** operator<
		  * @param Ref - Reference to CMinutes to compare to
		  * @return true if this < Ref, false otherwise
		  */
		bool operator<(const CMinutes &Ref) const;
		/** operator>
		  * @param Ref - Reference to CMinutes to compare to
		  * @return true if this > Ref, false otherwise
		  */
		bool operator>(const CMinutes &Ref) const;
		/** operator<=
		  * @param Ref - Reference to CMinutes to compare to
		  * @return true if this <= Ref, false otherwise
		  */
		bool operator<=(const CMinutes &Ref) const;
		/** operator>=
		  * @param Ref - Reference to CMinutes to compare to
		  * @return true if this >= Ref, false otherwise
		  */
		bool operator>=(const CMinutes &Ref) const;
		/** operator+
		  * @param Ref - Reference to CMinutes to add to current
		  * @return CMinutes result
		  */
		const CMinutes operator+(const CMinutes &Ref) const;
		/** operator+
		  * @param Ref - Reference to CMinutes to subtract from current
		  * @return CMinutes result
		  */
		const CMinutes operator-(const CMinutes &Ref) const;
		/** operator+=
		  * @param Ref - Reference to CMinutes to add to current
		  * @return Reference to current CMinutes
		  */
		const CMinutes& operator+=(const CMinutes &Ref);
		/** operator-=
		  * @param Ref - Reference to CMinutes to subtract from current
		  * @return Reference to current CMinutes
		  */
		const CMinutes& operator-=(const CMinutes &Ref);
		/** operator++ prefix
		  * postfix incrementer
		  * @return CMinutes by reference
		  */
		const CMinutes& operator++();
		/** operator-- prefix
		  * postfix decrementer
		  * @return CMinutes by reference
		  */
		const CMinutes& operator--();
		/** operator++ postfix
		  * postfix incrementer
		  * @return CMinutes by value
		  */
		const CMinutes operator++(int unused);
		/** operator-- postfix
		  * postfix decrementer
		  * @return CMinutes by value
		  */
		const CMinutes operator--(int unused);
		/** SetMinutes
		  * Sets number of minutes
		  * @param minutes - value to set CMinutes to
		  */
		void SetMinutes(long minutes);
		/** GetMinutes
		  * Retrieves number of minutes
		  * @return the number of minutes can be negative to represent negative minute intervals
		  */
		long GetMinutes() const;
	private:
		/** Number of minutes
		  */
		long m_minutes;
	};
};