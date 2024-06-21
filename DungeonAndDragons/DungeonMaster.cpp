#include "DungeonMaster.h"
#include"Dice.h"

DungeonMaster* DungeonMaster::instance = nullptr;

DungeonMaster::DungeonMaster()
{
	this->scene = new Scenariu("Library.txt");
	this->jucator = new Jucator();
}

DungeonMaster::~DungeonMaster()
{
	delete this->scene;
	delete this->batalie;
	delete this->enemy;
	delete this->jucator;

	this->scene = nullptr;
	this->batalie = nullptr;
	this->enemy = nullptr;
	this->jucator = nullptr;

}

void DungeonMaster::calculatePlayersDC(int DC)
{
	Dice zar;
	int aux = -5;

	if (DC != 1)
	{
		for (int i = 2, j = 3; i <= 30, j <= 29; i += 2, j += 2)
		{
			zar += 1;
			if (DC == i || DC == j)
				break;
		}
	}
	this->playersDC = zar.getDiceRoll() + aux;
}

int DungeonMaster::compare(int playersDC, int requiredDC)
{
	if (playersDC >= requiredDC)
		return 1;
	else return 0;
}

void DungeonMaster::printAruncareaCuZarul(int DC)
{
	std::cout << "\n\tAi dat cu zarul " << DC << "\n\t";
}

DungeonMaster& DungeonMaster::createInstance()
{
	if (!instance)
		instance = new DungeonMaster;
	return *instance;
}

void DungeonMaster::deleteInstance()
{
	if (this->instance)
	{
		delete this->instance;
		this->~DungeonMaster();
	}
	else
	{
		std::cout << "\nDungeon Master a fost deja sters!\n";
	}
}

int DungeonMaster::afisareMesajHitOrMiss()
{
	int requiredDc, ok = 0;
	int identifier = this->scene->getDCsiTipObiect(requiredDc, this->playersChoice);

	if (identifier == 1)
	{
		this->playersDC = this->jucator->getDexteritate();
		this->calculatePlayersDC(this->playersDC);
		this->printAruncareaCuZarul(this->playersDC);
		if (compare(this->playersDC, requiredDc))
		{
			ok = 1;
		}
	}
	else if (identifier == 2)
	{
		this->playersDC = this->jucator->getInteligenta();
		this->calculatePlayersDC(this->playersDC);
		this->printAruncareaCuZarul(this->playersDC);
		if (compare(this->playersDC, requiredDc))
		{
			ok = 1;
		}
	}
	else
	{
		this->playersDC = this->jucator->getPutere();
		this->calculatePlayersDC(this->playersDC);
		this->printAruncareaCuZarul(this->playersDC);
		if (compare(this->playersDC, requiredDc))
		{
			ok = 1;
		}
	}

	if (ok == 1)
	{
		std::cout << "\n\tActiunea a avut succes!\n";
		
		switch (identifier)
		{
			case 1:
			{
				std::string acces = this->scene->getAccesIncaperiNoi(this->playersChoice);
				this->scene->customMessage(this->playersChoice);
				acces = acces + ".txt";
				this->scene = new Scenariu(acces);
			}
			break;
			case 2:
			{
				Dice zar;
				int a = zar.getDiceRoll();
				std::cout << "\n\tAi primit " << a << " INTELECT!\n";
				this->jucator->cresteInteligenta(a);
				this->scene->stergereObiect(playersChoice);
			}
			break;
			case 3:
			{
				this->enemy = new NPC("The Ancient Dragon of Goblins");
				this->batalie = new Combat(this->jucator, this->enemy);
				this->scene->stergereObiect(playersChoice);
			}
			break;
			default: break;
		}
	}
	else
	{
		std::cout << "\n\tActiunea NU a avut succes!\n";
	}
	if (this->playersChoice >= 0)
		return 1;
	else
		return 0;
}

void DungeonMaster::afisareScenariu()
{
	this->scene->afisareScenariu();
}
