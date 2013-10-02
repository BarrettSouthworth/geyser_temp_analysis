#pragma once
#include <exception>

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class for CSecond Exceptions
	  */
	class CSecondException : public std::exception
	{
	public:
		/** CSecondException
		 * Constructs a CSecondException
		 */
		CSecondException() throw();
		/** CSecondException
		 * Copy constructs a CSecondException
		 * @param Ref - Reference to CSecondException being copied 
		 */
		CSecondException(const CSecondException &Ref) throw();
		/** operator=
		 * Assigns another CSecondException to this one
		 * @param Ref - Reference to CSecondException to assign from
		 * @return Reference to current CSecondException
		 */
		CSecondException& operator=(const CSecondException &Ref) throw();
		/** Destructor
		 */
		virtual ~CSecondException();
		/** what
		 * Get string representing exception
		 * @return character string representing the exception
		 */
		virtual const char *what() const throw();
	};
};
