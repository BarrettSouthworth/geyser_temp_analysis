#pragma once

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class Represents any number of secondss
	  */
	class CSeconds
	{
	public:
		/** Defualt Constructor
		  */
		CSeconds();
		/** Copy Constructor
		  * @param Ref - CSeconds to copy
		  */
		CSeconds(const CSeconds &Ref);
		/** Constructor
		  * @param secondss - secondss to set CSeconds to
		  */
		CSeconds(long long seconds);
		/** Assignment operator
		  * @param Ref - CSeconds to assign from
		  * @return Reference to current CSeconds
		  */
		const CSeconds& operator=(const CSeconds &Ref);
		/** Destructor
		  */
		~CSeconds();
		/** operator==
		  * @param Ref - Reference to CSeconds to compare to
		  * @return true if this == Ref, false otherwise
		  */
		bool operator==(const CSeconds &Ref) const;
		/** operator!=
		  * @param Ref - Reference to CSeconds to compare to
		  * @return true if this != Ref, false otherwise
		  */
		bool operator!=(const CSeconds &Ref) const;
		/** operator<
		  * @param Ref - Reference to CSeconds to compare to
		  * @return true if this < Ref, false otherwise
		  */
		bool operator<(const CSeconds &Ref) const;
		/** operator>
		  * @param Ref - Reference to CSeconds to compare to
		  * @return true if this > Ref, false otherwise
		  */
		bool operator>(const CSeconds &Ref) const;
		/** operator<=
		  * @param Ref - Reference to CSeconds to compare to
		  * @return true if this <= Ref, false otherwise
		  */
		bool operator<=(const CSeconds &Ref) const;
		/** operator>=
		  * @param Ref - Reference to CSeconds to compare to
		  * @return true if this >= Ref, false otherwise
		  */
		bool operator>=(const CSeconds &Ref) const;
		/** operator+
		  * @param Ref - Reference to CSeconds to add to current
		  * @return CSeconds result
		  */
		const CSeconds operator+(const CSeconds &Ref) const;
		/** operator+
		  * @param Ref - Reference to CSeconds to subtract from current
		  * @return CSeconds result
		  */
		const CSeconds operator-(const CSeconds &Ref) const;
		/** operator+=
		  * @param Ref - Reference to CSeconds to add to current
		  * @return Reference to current CSeconds
		  */
		const CSeconds& operator+=(const CSeconds &Ref);
		/** operator-=
		  * @param Ref - Reference to CSeconds to subtract from current
		  * @return Reference to current CSeconds
		  */
		const CSeconds& operator-=(const CSeconds &Ref);
		/** operator++ prefix
		  * postfix incrementer
		  * @return CSeconds by reference
		  */
		const CSeconds& operator++();
		/** operator-- prefix
		  * postfix decrementer
		  * @return CSeconds by reference
		  */
		const CSeconds& operator--();
		/** operator++ postfix
		  * postfix incrementer
		  * @return CSeconds by value
		  */
		const CSeconds operator++(int unused);
		/** operator-- postfix
		  * postfix decrementer
		  * @return CSeconds by value
		  */
		const CSeconds operator--(int unused);
		/** SetSecondss
		  * Sets number of secondss
		  * @param secondss - value to set CSeconds to
		  */
		void SetSeconds(long long seconds);
		/** GetSecondss
		  * Retrieves number of seconds
		  * @return the number of secondss can be negative to represent negative second intervals
		  */
		long long GetSeconds() const;
	private:
		/** Number of seconds
		  */
		long long m_seconds;
	};
};
