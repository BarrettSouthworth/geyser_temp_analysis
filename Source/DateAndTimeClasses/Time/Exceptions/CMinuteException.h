#pragma once
#include <exception>

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class for CMinute Exceptions
	  */
	class CMinuteException : public std::exception
	{
	public:
		/** CMinuteException
		 * Constructs a CMinuteException
		 */
		CMinuteException() throw();
		/** CMinuteException
		 * Copy constructs a CMinuteException
		 * @param Ref - Reference to CMinuteException being copied 
		 */
		CMinuteException(const CMinuteException &Ref) throw();
		/** operator=
		 * Assigns another CMinuteException to this one
		 * @param Ref - Reference to CMinuteException to assign from
		 * @return Reference to current CMinuteException
		 */
		CMinuteException& operator=(const CMinuteException &Ref) throw();
		/** Destructor
		 */
		virtual ~CMinuteException();
		/** what
		 * Get string representing exception
		 * @return character string representing the exception
		 */
		virtual const char *what() const throw();
	};
};
