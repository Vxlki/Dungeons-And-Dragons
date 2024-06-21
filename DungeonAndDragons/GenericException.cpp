#include "GenericException.h"

GenericException::GenericException(std::string aux)
{
	exceptie = aux;
}

void GenericException::printException()
{
	std::cout << this->exceptie;
}
