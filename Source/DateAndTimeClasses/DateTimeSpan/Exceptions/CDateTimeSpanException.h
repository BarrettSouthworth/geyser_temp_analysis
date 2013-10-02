#pragma once
#include <exception>

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class for CDateTimeException Exceptions
	  */
	class CDateTimeSpanException : public std::exception
	{
	public:
		/** CDateTimeSpanException
		 * Constructs a CDateTimeSpanException
		 */
		CDateTimeSpanException() throw();
		/** CDateTimeSpanException
		 * Copy constructs a CDateTimeSpanException
		 * @param Ref - Reference to CDateTimeSpanException being copied 
		 */
		CDateTimeSpanException(const CDateTimeSpanException &Ref) throw();
		/** operator=
		 * Assigns another CDateTimeSpanException to this one
		 * @param Ref - Reference to CDateTimeSpanException to assign from
		 * @return Reference to current CDateTimeSpanException
		 */
		CDateTimeSpanException& operator=(const CDateTimeSpanException &Ref) throw();
		/** Destructor
		 */
		virtual ~CDateTimeSpanException();
		/** what
		 * Get string representing exception
		 * @return character string representing the exception
		 */
		virtual const char *what() const throw();
	};
};
