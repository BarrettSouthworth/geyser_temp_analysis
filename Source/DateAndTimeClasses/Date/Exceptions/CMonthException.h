#pragma once
#include <exception>

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class for CMonth Exceptions
	  */
	class CMonthException : public std::exception
	{
	public:
		/** CMonthException
		 * Constructs a CMonthException
		 */
		CMonthException() throw();
		/** CMonthException
		 * Copy constructs a CMonthException
		 * @param Ref - Reference to CMonthException being copied 
		 */
		CMonthException(const CMonthException &Ref) throw();
		/** operator=
		 * Assigns another CMonthException to this one
		 * @param Ref - Reference to CMonthException to assign from
		 * @return Reference to current CMonthException
		 */
		CMonthException& operator=(const CMonthException &Ref) throw();
		/** Destructor
		 */
		virtual ~CMonthException();
		/** what
		 * Get string representing exception
		 * @return character string representing the exception
		 */
		virtual const char *what() const throw();
	};
};
