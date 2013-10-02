#pragma once
#include <exception>

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class for CDay Exceptions
	  */
	class CDayException : public std::exception
	{
	public:
		/** CDayException
		 * Constructs a CDayException
		 */
		CDayException() throw();
		/** CDayException
		 * Copy constructs a CDayException
		 * @param Ref - Reference to CDayException being copied 
		 */
		CDayException(const CDayException &Ref) throw();
		/** operator=
		 * Assigns another CDayException to this one
		 * @param Ref - Reference to CDayException to assign from
		 * @return Reference to current CDayException
		 */
		CDayException& operator=(const CDayException &Ref) throw();
		/** Destructor
		 */
		virtual ~CDayException();
		/** what
		 * Get string representing exception
		 * @return character string representing the exception
		 */
		virtual const char *what() const throw();
	};
};
