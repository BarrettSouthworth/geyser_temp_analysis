#pragma once
#include <exception>

#pragma once
#include <exception>

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class for CTime Exceptions
	  */
	class CTimeException : public std::exception
	{
	public:
		/** CTimeException
		 * Constructs a CTimeException
		 */
		CTimeException() throw();
		/** CTimeException
		 * Copy constructs a CTimeException
		 * @param Ref - Reference to CTimeException being copied 
		 */
		CTimeException(const CTimeException &Ref) throw();
		/** operator=
		 * Assigns another CTimeException to this one
		 * @param Ref - Reference to CTimeException to assign from
		 * @return Reference to current CTimeException
		 */
		CTimeException& operator=(const CTimeException &Ref) throw();
		/** Destructor
		 */
		virtual ~CTimeException();
		/** what
		 * Get string representing exception
		 * @return character string representing the exception
		 */
		virtual const char *what() const throw();
	};
};

