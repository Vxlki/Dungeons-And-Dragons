#include "ObiectePutere.h"

int ObiectePutere::identifier = 3;

ObiectePutere::ObiectePutere(std::string nume) : Obiecte(nume)
{
}

void ObiectePutere::printObjInterraction()
{
	std::cout << "\n\t" << this->numeObiect << " -> attack\n";
}

int ObiectePutere::getIdentifier()
{
	return identifier;
}

void ObiectePutere::printCustomMessage()
{
	std::cout << "\n\tAcum te lupti cu: ";
}
