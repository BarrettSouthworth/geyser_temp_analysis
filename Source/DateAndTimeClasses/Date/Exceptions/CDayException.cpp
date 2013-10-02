#include "CDayException.h"

using namespace GeyserEruptionCalc;

CDayException::CDayException() throw()
{
}

CDayException::CDayException(const CDayException &Ref) throw()
{
}

CDayException& CDayException::operator=(const CDayException &Ref) throw()
{
	std::exception::operator=(Ref);
	return *this;
}

CDayException::~CDayException()
{
}

const char *CDayException::what() const throw()
{
	return "CDayException";
}
