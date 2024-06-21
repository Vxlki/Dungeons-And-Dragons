#include "Scenariu.h"
#include"ObiecteDexteritate.h"
#include"ObiecteInteligenta.h"
#include"ObiectePutere.h"
#include<fstream>
#include"CustomException.h"
#include"cstdlib"


void Scenariu::afisareScenariu()
{
	std::cout << this->numeIncapere;
	std::cout << std::endl;

	for (int i = 0; i < this->obiecteIncapere.size(); i++)
	{
		std::cout << "\t" << i + 1 << ". " << *(this->obiecteIncapere[i]) << std::endl;
	}
	std::cout << std::endl;
}

Scenariu::Scenariu(std::string fname)
{
	std::ifstream fin(fname);
	std::string aux;

	if (!fin.is_open())
	{
		IException* e = new CustomException("Eroare la deschiderea fisierului " + fname);
		throw e;
	}

	fin >> this->numeIncapere;
	fin.get();

	while (std::getline(fin,aux))
	{
		if(aux.find("Book")!=std::string::npos)
		{
			Obiecte* book = new ObiecteInteligenta("Book");
			this->obiecteIncapere.push_back(book);
		}
		if (aux.find("Portal") != std::string::npos)
		{
			std::string acces = aux.substr(7);
			Obiecte* o = new ObiecteDexteritate("Portal", acces);
			this->obiecteIncapere.push_back(o);
			this->accesIncaperiNoi.push_back(acces);
		}
		if (aux.find("Door") != std::string::npos)
		{
			std::string acces = aux.substr(5);
			Obiecte* o = new ObiecteDexteritate("Door", acces);
			this->obiecteIncapere.push_back(o);
			this->accesIncaperiNoi.push_back(acces);
		}
		if (aux.find("Enemy") != std::string::npos)
		{
			Obiecte* o = new ObiectePutere("Enemy");
			this->obiecteIncapere.push_back(o);
			Personaj* p = new NPC;
			this->enemy = p;
		}
	}
}

std::string Scenariu::getAccesIncaperiNoi(int choice)
{
	return this->obiecteIncapere[choice]->getAccesNextRoom();
}

void Scenariu::stergereObiect(int playersChoice)
{
	Obiecte* aux = this->obiecteIncapere[playersChoice];

	auto it = std::find(this->obiecteIncapere.begin(), this->obiecteIncapere.end(), aux);

	this->obiecteIncapere.erase(it);
}


int Scenariu::getDCsiTipObiect(int& DC, int& pChoice)
{
	std::cout << "\n\tTe aflii in: ";

	afisareScenariu();

	std::cout << "\n\tCe vrei sa incerci?\n\t";

	int choice;

	std::cin >> choice;
	choice -= 1;

	if (choice < this->obiecteIncapere.size())
	{
		this->obiecteIncapere[choice]->printObjInterraction();
		DC = this->obiecteIncapere[choice]->getDC();
		pChoice = choice;
		return this->obiecteIncapere[choice]->getIdentifier();
	}
	else
	{
		IException* e = new CustomException("User choice Error!");
		throw e;
	}
}

void Scenariu::customMessage(int choice)
{
	this->obiecteIncapere[choice]->printCustomMessage();
}
