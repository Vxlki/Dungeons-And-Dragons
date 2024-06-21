#include "CustomException.h"

CustomException::CustomException(std::string aux)
{
	this->exceptie = aux;
}

void CustomException::printException()
{
	std::cout << this->exceptie;
}
