#pragma once
#include <exception>

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class for CDate Exceptions
	  */
	class CDateException : public std::exception
	{
	public:
		/** CDateException
		 * Constructs a CDateException
		 */
		CDateException() throw();
		/** CDateException
		 * Copy constructs a CDateException
		 * @param Ref - Reference to CDateException being copied 
		 */
		CDateException(const CDateException &Ref) throw();
		/** operator=
		 * Assigns another CDateException to this one
		 * @param Ref - Reference to CDateException to assign from
		 * @return Reference to current CDateException
		 */
		CDateException& operator=(const CDateException &Ref) throw();
		/** Destructor
		 */
		virtual ~CDateException();
		/** what
		 * Get string representing exception
		 * @return character string representing the exception
		 */
		virtual const char *what() const throw();
	};
};
