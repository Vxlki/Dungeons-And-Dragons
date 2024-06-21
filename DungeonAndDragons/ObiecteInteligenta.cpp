#include "ObiecteInteligenta.h"

int ObiecteInteligenta::identifier = 2;

ObiecteInteligenta::ObiecteInteligenta(std::string nume) : Obiecte(nume)
{
}

void ObiecteInteligenta::printObjInterraction()
{
	std::cout << "\n\t" << this->numeObiect << " -> read\n";
}

int ObiecteInteligenta::getIdentifier()
{
	return identifier;
}

void ObiecteInteligenta::printCustomMessage()
{
	std::cout << "\n\tAi interactionat cu " << this->numeObiect << ".\n";
}
