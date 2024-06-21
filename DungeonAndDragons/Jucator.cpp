#include "Jucator.h"

Jucator::Jucator() : Personaj()
{
}

std::string Jucator::getDescription()
{
	std::string aux = "Jucator:\n";
	aux += Personaj::getDescription();

	return aux;
}

void Jucator::printAbilitateaSelectata(int n)
{
}
