#include "CHourException.h"

using namespace GeyserEruptionCalc;

CHourException::CHourException() throw()
{
}

CHourException::CHourException(const CHourException &Ref) throw()
{
}

CHourException& CHourException::operator=(const CHourException &Ref) throw()
{
	std::exception::operator=(Ref);
	return *this;
}

CHourException::~CHourException()
{
}

const char *CHourException::what() const throw()
{
	return "CHourException";
}
