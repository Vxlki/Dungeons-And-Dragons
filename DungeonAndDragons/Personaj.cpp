#define NR_CLASA 2
#define NR_RASA 3
#define NR_TRECUT 3

#include "Personaj.h"
#include"Sorcerer.h"
#include"Fighter.h"
#include"Goblin.h"
#include"Human.h"
#include"Elf.h"
#include"CustomException.h"

std::string Personaj::trecutToString(int aux)
{
	if (aux == 0)
		return "Soldat";
	else if (aux == 1)
		return "Acolit";
	else
		return "Hot";
}

void Personaj::printCalitati()
{
	std::cout << "\nCalitatile tale actuale sunt:\n\n\tInteligenta: " << this->inteligenta
		<< "\n\tDexteritate: " << this->dexteritate
		<< "\n\tPutere: " << this->putere << "\n\n";
}

int Personaj::getConsoleWidth() 
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwSize.X;
}

void Personaj::printCentered(std::string s)
{
	int consoleWidth = getConsoleWidth();
	int padding = (consoleWidth - s.length()) / 2;
	std::cout << std::setw(padding + s.length()) << std::setfill(' ') << s << std::endl;
}

Personaj::Personaj(std::string nume)
{
	std::cout << "\n";
	printCentered("DUNGEONS & DRAGONS");

	this->numePersonaj = nume;

	std::cout << "\nDungeon Master: \tWelcome to Dungeons and Dragons! What is your name, traveler?\n\nName: ";

	std::cin >> this->numePersonaj;


	this->clasaPersonaj = nullptr;
	this->rasaPersonaj = nullptr;
	this->inteligenta = 0;
	this->dexteritate = 0;
	this->putere = 0;
	this->HP = 100;
	this->trecutPersonaj = Default;

	int choice;
	
	std::cout << "\nDungeon Master: \tHello, " << this->numePersonaj << "! Nice meeting you! Good luck in your aventure. You will need it!\n\n";

	do
	{
		std::cout << "\n\tAlege-ti clasa personajului:\n\t\t1. Sorcerer;\n\t\t2. Fighter.\n\t\t";
		std::cin >> choice;
		switch (choice)
		{
		case 1: this->clasaPersonaj = new Sorcerer; this->inteligenta += 7; this->dexteritate += 10; this->HP += 5; break;
		case 2: this->clasaPersonaj = new Fighter; this->dexteritate += 4; this->putere = +3; this->HP += 15; break;
		default: std::cout << "\nOptiune invalida!\n"; break;
		}
	} while (!this->clasaPersonaj);

	do
	{
		std::cout << "\n\tAlege-ti rasa personajului:\n\t\t1. Human;\n\t\t2. Elf;\n\t\t3. Goblin.\n\t\t";
		std::cin >> choice;
		switch (choice)
		{
		case 1: this->rasaPersonaj = new Human; this->putere += 2; this->inteligenta += 3; break;
		case 2: this->rasaPersonaj = new Elf; this->dexteritate += 5; break;
		case 3: this->rasaPersonaj = new Goblin; this->inteligenta += 6; break;
		default: std::cout << "\nOptiune invalida!\n"; break;
		}
	} while (!this->rasaPersonaj);

	do
	{
		std::cout << "\n\tAlege-ti trecutul personajului : \n\t\t1. Soldat; \n\t\t2. Acolit; \n\t\t3. Hot.\n\t\t";
		std::cin >> choice;
		switch (choice)
		{
		case 1: this->trecutPersonaj = Soldat; this->putere += 3; this->inteligenta += 2; break;
		case 2: this->trecutPersonaj = Acolit; this->inteligenta += 5; break;
		case 3: this->trecutPersonaj = Hot; this->dexteritate += 3; this->putere += 2; break;
		default: std::cout << "\nOptiune invalida!\n"; break;
		}
	} while (!this->trecutPersonaj);

	int puncte = 30;

	while (puncte >= 1)
	{
		IException* e = new CustomException("\nOptiune invalida! Nu ai suficiente puncte ramase.\n");

		this->printCalitati();

		try
		{
			std::cout << "\n\tCate puncte in inteligenta?(1-" << puncte << ")\n\t";
			std::cin >> choice;
			if (choice > puncte)
				throw e;
			this->inteligenta += choice;
			puncte -= choice;
			if (puncte < 1)
				break;

			std::cout << "\n\tCate puncte in dexteritate?(1-" << puncte << ")\n\t";
			std::cin >> choice;
			if (choice > puncte)
				throw e;
			this->dexteritate += puncte;
			puncte -= choice;
			if (puncte < 1)
				break;

			std::cout << "\n\tCate puncte in putere?(1-" << puncte << ")\n\t";
			std::cin >> choice;
			if (choice > puncte)
				throw e;
			this->putere += puncte;
			puncte -= choice;
			if (puncte < 1)
				break;
		}
		catch (IException* e)
		{
			e->printException();
		}
	}
	this->printCalitati();
}

Personaj::Personaj(int debugging, int d2, std::string nume)
{
	this->numePersonaj = nume;
	this->inteligenta = 15;
	this->putere = 10;
	this->dexteritate = 5;
	this->HP = 100;
	this->clasaPersonaj = new Sorcerer;
	this->inteligenta += 7;
	this->dexteritate += 10;
	this->HP += 5;
	this->rasaPersonaj = new Elf;
	this->dexteritate += 5;
	this->trecutPersonaj = Soldat;
	this->putere += 3;
	this->inteligenta += 2;

}

Personaj::Personaj(int NPC, std::string nume)
{
	this->numePersonaj = nume;
	this->clasaPersonaj = nullptr;
	this->rasaPersonaj = nullptr;
	this->inteligenta = 0;
	this->dexteritate = 0;
	this->putere = 0;
	this->HP = 100;

	int choice;
	srand(time(0));

	do
	{
		choice = rand() % NR_CLASA;
		switch (choice)
		{
		case 1: this->clasaPersonaj = new Sorcerer; this->inteligenta += 7; this->dexteritate += 10; this->HP += 5; break;
		case 2: this->clasaPersonaj = new Fighter; this->dexteritate += 4; this->putere = +3; this->HP += 15; break;
		//default: std::cout << "Optiune invalida\n"; break;
		}
	} while (!this->clasaPersonaj);

	do
	{
		choice = rand() % NR_RASA;
		switch (choice)
		{
		case 1: this->rasaPersonaj = new Human; this->putere += 2; this->inteligenta += 3; break;
		case 2: this->rasaPersonaj = new Elf; this->dexteritate += 5; break;
		case 3: this->rasaPersonaj = new Goblin; this->inteligenta += 6; break;
		//default: std::cout << "Optiune invalida\n"; break;
		}
	} while (!this->rasaPersonaj);

	do
	{
		choice = rand() % NR_TRECUT;
		switch (choice)
		{
		case 1: this->trecutPersonaj = Soldat; this->putere += 3; this->inteligenta += 2; break;
		case 2: this->trecutPersonaj = Acolit; this->inteligenta += 5; break;
		case 3: this->trecutPersonaj = Hot; this->dexteritate += 3; this->putere += 2; break;
		// default: std::cout << "Optiune invalida\n"; break;
		}
	} while (!this->trecutPersonaj);

	int puncte = 30;
	do
	{
		choice = rand() % puncte;
		this->inteligenta += choice;
		puncte -= choice;
		choice = rand() % puncte;
		this->dexteritate += choice;
		puncte -= choice;
		choice = rand() % puncte;
		this->putere += choice;
		puncte -= choice;
	} while (puncte > 1);
}

std::string Personaj::getDescription()
{
	std::string aux;
	aux = this->numePersonaj + " " + this->clasaPersonaj->getClasa() + " " + this->rasaPersonaj->getRasa() +
		" " + this->trecutToString(this->trecutPersonaj) + "\nInteligenta: " + std::to_string(this->inteligenta) +
		+ "\nDexteritate: " + std::to_string(this->dexteritate) + "\nPutere: " + std::to_string(this->putere)
		+ "\nHP: " + std::to_string(this->HP);

	return aux;
}

std::string Personaj::getName()
{
	return this->numePersonaj;
}

int Personaj::getInteligenta()
{
	return this->inteligenta;
}

int Personaj::getDexteritate()
{
	return this->dexteritate;
}

int Personaj::getPutere()
{
	return this->putere;
}

float Personaj::getHP()
{
	return this->HP;
}

void Personaj::afisareOptiuniCombat(int& n)
{
	std::cout << "\nHP: " << this->HP << "\n\n";
	this->rasaPersonaj->printAbilitateRasa(n);
	this->clasaPersonaj->printAbilitateClasa(n);
}

void Personaj::scadeHP(float hit)
{
	this->HP -= hit;
}

float Personaj::getDamageDone(int choice)
{
	if (choice == 1)
		return this->rasaPersonaj->damageAbilitate();
	else
		return this->clasaPersonaj->damageAbilitateClasa(choice - 1);
}

void Personaj::cresteInteligenta(int iq)
{
	this->inteligenta += iq;
}
