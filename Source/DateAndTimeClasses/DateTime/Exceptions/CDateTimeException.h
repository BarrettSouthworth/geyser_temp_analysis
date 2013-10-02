#pragma once
#include <exception>

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class for CDateTime Exceptions
	  */
	class CDateTimeException : public std::exception
	{
	public:
		/** CDateTimeException
		 * Constructs a CDateTimeException
		 */
		CDateTimeException() throw();
		/** CDateTimeException
		 * Copy constructs a CDateTimeException
		 * @param Ref - Reference to CDateTimeException being copied 
		 */
		CDateTimeException(const CDateTimeException &Ref) throw();
		/** operator=
		 * Assigns another CDateTimeException to this one
		 * @param Ref - Reference to CDateTimeException to assign from
		 * @return Reference to current CDateTimeException
		 */
		CDateTimeException& operator=(const CDateTimeException &Ref) throw();
		/** Destructor
		 */
		virtual ~CDateTimeException();
		/** what
		 * Get string representing exception
		 * @return character string representing the exception
		 */
		virtual const char *what() const throw();
	};
};
