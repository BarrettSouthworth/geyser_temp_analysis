#include "CMonthException.h"

using namespace GeyserEruptionCalc;

CMonthException::CMonthException() throw()
{
}

CMonthException::CMonthException(const CMonthException &Ref) throw()
{
}

CMonthException& CMonthException::operator=(const CMonthException &Ref) throw()
{
	std::exception::operator=(Ref);
	return *this;
}

CMonthException::~CMonthException()
{
}

const char *CMonthException::what() const throw()
{
	return "CMonthException";
}
