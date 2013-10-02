#pragma once
#include <exception>

/** namespace represents classes for Geyser Eruption Calculations
  */
namespace GeyserEruptionCalc
{
	/** Class for CHour Exceptions
	  */
	class CHourException : public std::exception
	{
	public:
		/** CHourException
		 * Constructs a CHourException
		 */
		CHourException() throw();
		/** CHourException
		 * Copy constructs a CHourException
		 * @param Ref - Reference to CHourException being copied 
		 */
		CHourException(const CHourException &Ref) throw();
		/** operator=
		 * Assigns another CHourException to this one
		 * @param Ref - Reference to CHourException to assign from
		 * @return Reference to current CHourException
		 */
		CHourException& operator=(const CHourException &Ref) throw();
		/** Destructor
		 */
		virtual ~CHourException();
		/** what
		 * Get string representing exception
		 * @return character string representing the exception
		 */
		virtual const char *what() const throw();
	};
};
