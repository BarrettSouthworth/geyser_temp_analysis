#include "CSecondException.h"

using namespace GeyserEruptionCalc;

CSecondException::CSecondException() throw()
{
}

CSecondException::CSecondException(const CSecondException &Ref) throw()
{
}

CSecondException& CSecondException::operator=(const CSecondException &Ref) throw()
{
	std::exception::operator=(Ref);
	return *this;
}

CSecondException::~CSecondException()
{
}

const char *CSecondException::what() const throw()
{
	return "CSecondException";
}
