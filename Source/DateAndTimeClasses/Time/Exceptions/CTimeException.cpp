#include "CTimeException.h"

using namespace GeyserEruptionCalc;

CTimeException::CTimeException() throw()
{
}

CTimeException::CTimeException(const CTimeException &Ref) throw()
{
}

CTimeException& CTimeException::operator=(const CTimeException &Ref) throw()
{
	std::exception::operator=(Ref);
	return *this;
}

CTimeException::~CTimeException()
{
}

const char *CTimeException::what() const throw()
{
	return "CTimeException";
}
