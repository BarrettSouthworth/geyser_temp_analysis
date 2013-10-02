#include "CDateTimeSpanException.h"

using namespace GeyserEruptionCalc;

CDateTimeSpanException::CDateTimeSpanException() throw()
{
}

CDateTimeSpanException::CDateTimeSpanException(const CDateTimeSpanException &Ref) throw()
{
}

CDateTimeSpanException& CDateTimeSpanException::operator=(const CDateTimeSpanException &Ref) throw()
{
	std::exception::operator=(Ref);
	return *this;
}

CDateTimeSpanException::~CDateTimeSpanException()
{
}

const char *CDateTimeSpanException::what() const throw()
{
	return "CDateTimeSpanException";
}
