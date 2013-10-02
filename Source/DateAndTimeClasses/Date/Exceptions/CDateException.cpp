#include "CDateException.h"

using namespace GeyserEruptionCalc;

CDateException::CDateException() throw()
{
}

CDateException::CDateException(const CDateException &Ref) throw()
{
}

CDateException& CDateException::operator=(const CDateException &Ref) throw()
{
	std::exception::operator=(Ref);
	return *this;
}

CDateException::~CDateException()
{
}

const char *CDateException::what() const throw()
{
	return "CDateException";
}
