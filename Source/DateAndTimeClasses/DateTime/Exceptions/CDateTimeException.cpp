#include "CDateTimeException.h"

using namespace GeyserEruptionCalc;

CDateTimeException::CDateTimeException() throw()
{
}

CDateTimeException::CDateTimeException(const CDateTimeException &Ref) throw()
{
}

CDateTimeException& CDateTimeException::operator=(const CDateTimeException &Ref) throw()
{
	std::exception::operator=(Ref);
	return *this;
}

CDateTimeException::~CDateTimeException()
{
}

const char *CDateTimeException::what() const throw()
{
	return "CDateTimeException";
}
