#pragma once
#include <exception>

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class for CYear Exceptions
	  */
	class CYearException : public std::exception
	{
	public:
		/** CYearException
		 * Constructs a CYearException
		 */
		CYearException() throw();
		/** CYearException
		 * Copy constructs a CYearException
		 * @param Ref - Reference to CYearException being copied 
		 */
		CYearException(const CYearException &Ref) throw();
		/** operator=
		 * Assigns another CYearException to this one
		 * @param Ref - Reference to CYearException to assign from
		 * @return Reference to current CYearException
		 */
		CYearException& operator=(const CYearException &Ref) throw();
		/** Destructor
		 */
		virtual ~CYearException();
		/** what
		 * Get string representing exception
		 * @return character string representing the exception
		 */
		virtual const char *what() const throw();
	};
};
