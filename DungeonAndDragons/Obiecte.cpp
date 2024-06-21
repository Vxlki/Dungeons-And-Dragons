#include "Obiecte.h"
#include<iostream>

Obiecte::Obiecte(std::string nume)
{
	this->numeObiect = nume;
	srand(time(0));
	this->difficultyClass = rand() % 20;
}

int Obiecte::getDC()
{
	return this->difficultyClass;
}

std::string Obiecte::getAccesNextRoom()
{
	return nullptr;
}

std::ostream& operator<<(std::ostream& out, Obiecte& obj)
{
	out << obj.numeObiect;

	return out;
}
