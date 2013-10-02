#pragma once

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class Represents any number of days
	  */
	class CDays
	{
	public:
		/** Defualt Constructor
		  */
		CDays();
		/** Copy Constructor
		  * @param Ref - CDays to copy
		  */
		CDays(const CDays &Ref);
		/** Constructor
		  * @param days - days to set CDays to
		  */
		CDays(long days);
		/** Assignment operator
		  * @param Ref - CDays to assign from
		  * @return Reference to current CDays
		  */
		const CDays& operator=(const CDays &Ref);
		/** Destructor
		  */
		~CDays();
		/** operator==
		  * @param Ref - Reference to CDays to compare to
		  * @return true if this == Ref, false otherwise
		  */
		bool operator==(const CDays &Ref) const;
		/** operator!=
		  * @param Ref - Reference to CDays to compare to
		  * @return true if this != Ref, false otherwise
		  */
		bool operator!=(const CDays &Ref) const;
		/** operator<
		  * @param Ref - Reference to CDays to compare to
		  * @return true if this < Ref, false otherwise
		  */
		bool operator<(const CDays &Ref) const;
		/** operator>
		  * @param Ref - Reference to CDays to compare to
		  * @return true if this > Ref, false otherwise
		  */
		bool operator>(const CDays &Ref) const;
		/** operator<=
		  * @param Ref - Reference to CDays to compare to
		  * @return true if this <= Ref, false otherwise
		  */
		bool operator<=(const CDays &Ref) const;
		/** operator>=
		  * @param Ref - Reference to CDays to compare to
		  * @return true if this >= Ref, false otherwise
		  */
		bool operator>=(const CDays &Ref) const;
		/** operator+
		  * @param Ref - Reference to CDays to add to current
		  * @return CDays result
		  */
		const CDays operator+(const CDays &Ref) const;
		/** operator+
		  * @param Ref - Reference to CDays to subtract from current
		  * @return CDays result
		  */
		const CDays operator-(const CDays &Ref) const;
		/** operator+=
		  * @param Ref - Reference to CDays to add to current
		  * @return Reference to current CDays
		  */
		const CDays& operator+=(const CDays &Ref);
		/** operator-=
		  * @param Ref - Reference to CDays to subtract from current
		  * @return Reference to current CDays
		  */
		const CDays& operator-=(const CDays &Ref);
		/** operator++ prefix
		  * postfix incrementer
		  * @return CDays by reference
		  */
		const CDays& operator++();
		/** operator-- prefix
		  * postfix decrementer
		  * @return CDays by reference
		  */
		const CDays& operator--();
		/** operator++ postfix
		  * postfix incrementer
		  * @return CDays by value
		  */
		const CDays operator++(int unused);
		/** operator-- postfix
		  * postfix decrementer
		  * @return CDays by value
		  */
		const CDays operator--(int unused);
		/** SetDays
		  * Sets number of days
		  * @param days - value to set CDays to
		  */
		void SetDays(long days);
		/** GetDays
		  * Retrieves number of days
		  * @return the number of days can be negative to represent negative day intervals
		  */
		long GetDays() const;
	private:
		/** Number of days
		  */
		long m_days;
	};
};