#pragma once

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class Represents any number of hours
	  */
	class CHours
	{
	public:
		/** Defualt Constructor
		  */
		CHours();
		/** Copy Constructor
		  * @param Ref - CHours to copy
		  */
		CHours(const CHours &Ref);
		/** Constructor
		  * @param hours - hours to set CHours to
		  */
		CHours(long hours);
		/** Assignment operator
		  * @param Ref - CHours to assign from
		  * @return Reference to current CHours
		  */
		const CHours& operator=(const CHours &Ref);
		/** Destructor
		  */
		~CHours();
		/** operator==
		  * @param Ref - Reference to CHours to compare to
		  * @return true if this == Ref, false otherwise
		  */
		bool operator==(const CHours &Ref) const;
		/** operator!=
		  * @param Ref - Reference to CHours to compare to
		  * @return true if this != Ref, false otherwise
		  */
		bool operator!=(const CHours &Ref) const;
		/** operator<
		  * @param Ref - Reference to CHours to compare to
		  * @return true if this < Ref, false otherwise
		  */
		bool operator<(const CHours &Ref) const;
		/** operator>
		  * @param Ref - Reference to CHours to compare to
		  * @return true if this > Ref, false otherwise
		  */
		bool operator>(const CHours &Ref) const;
		/** operator<=
		  * @param Ref - Reference to CHours to compare to
		  * @return true if this <= Ref, false otherwise
		  */
		bool operator<=(const CHours &Ref) const;
		/** operator>=
		  * @param Ref - Reference to CHours to compare to
		  * @return true if this >= Ref, false otherwise
		  */
		bool operator>=(const CHours &Ref) const;
		/** operator+
		  * @param Ref - Reference to CHours to add to current
		  * @return CHours result
		  */
		const CHours operator+(const CHours &Ref) const;
		/** operator+
		  * @param Ref - Reference to CHours to subtract from current
		  * @return CHours result
		  */
		const CHours operator-(const CHours &Ref) const;
		/** operator+=
		  * @param Ref - Reference to CHours to add to current
		  * @return Reference to current CHours
		  */
		const CHours& operator+=(const CHours &Ref);
		/** operator-=
		  * @param Ref - Reference to CHours to subtract from current
		  * @return Reference to current CHours
		  */
		const CHours& operator-=(const CHours &Ref);
		/** operator++ prefix
		  * postfix incrementer
		  * @return CHours by reference
		  */
		const CHours& operator++();
		/** operator-- prefix
		  * postfix decrementer
		  * @return CHours by reference
		  */
		const CHours& operator--();
		/** operator++ postfix
		  * postfix incrementer
		  * @return CHours by value
		  */
		const CHours operator++(int unused);
		/** operator-- postfix
		  * postfix decrementer
		  * @return CHours by value
		  */
		const CHours operator--(int unused);
		/** SetHours
		  * Sets number of hours
		  * @param hours - value to set CHours to
		  */
		void SetHours(long hours);
		/** GetHours
		  * Retrieves number of hours
		  * @return the number of hours can be negative to represent negative hour intervals
		  */
		long GetHours() const;
	private:
		/** Number of hours
		  */
		long m_hours;
	};
};