#include "CYearException.h"

using namespace GeyserEruptionCalc;

CYearException::CYearException() throw()
{
}

CYearException::CYearException(const CYearException &Ref) throw()
{
}

CYearException& CYearException::operator=(const CYearException &Ref) throw()
{
	std::exception::operator=(Ref);
	return *this;
}

CYearException::~CYearException()
{
}

const char *CYearException::what() const throw()
{
	return "CYearException";
}
