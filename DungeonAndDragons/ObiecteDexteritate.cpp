#include "ObiecteDexteritate.h"

int ObiecteDexteritate::identifier = 1;

ObiecteDexteritate::ObiecteDexteritate(const char* nume, std::string acces) : Obiecte(nume)
{
	this->acces = acces;
}

void ObiecteDexteritate::printObjInterraction()
{
	std::cout << "\n\t" << this->numeObiect << " -> open\n";
}

int ObiecteDexteritate::getIdentifier()
{
	return identifier;
}

void ObiecteDexteritate::printCustomMessage()
{
	std::cout << "\n\tAi ajuns in " << this->acces << ".\n";
}

std::string ObiecteDexteritate::getAccesNextRoom()
{
	return this->acces;
}
