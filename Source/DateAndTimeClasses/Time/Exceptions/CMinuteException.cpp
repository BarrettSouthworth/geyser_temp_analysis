#include "CMinuteException.h"

using namespace GeyserEruptionCalc;

CMinuteException::CMinuteException() throw()
{
}

CMinuteException::CMinuteException(const CMinuteException &Ref) throw()
{
}

CMinuteException& CMinuteException::operator=(const CMinuteException &Ref) throw()
{
	std::exception::operator=(Ref);
	return *this;
}

CMinuteException::~CMinuteException()
{
}

const char *CMinuteException::what() const throw()
{
	return "CMinuteException";
}
