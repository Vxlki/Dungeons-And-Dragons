#include "Combat.h"
#include<chrono>
#include<thread>
#include"CustomException.h"
#include"Dice.h"

int Combat::nrOptiuni = 1;

void Combat::afisareOptiuniJucator()
{
	this->jucator->afisareOptiuniCombat(this->nrOptiuni);
}

int Combat::calculatePlayersDC(int DC)
{
	Dice zar;
	int aux = -5;

	if (DC != 1)
	{
		for (int i = 2, j = 3; i <= 30, j <= 129; i += 2, j += 2)
		{
			zar += 1;
			if (DC == i || DC == j)
				break;
		}
	}
	return zar.getDiceRoll() + aux;
}

int Combat::compare(int DC, int diceRoll)
{
	if (DC >= diceRoll)
		return 1;
	else return 0;
}

Combat::Combat(Personaj* player, Personaj* enemy)
{
	this->jucator = player;
	this->enemy = enemy;

	do
	{
		std::cout << "\n\nEnemy's HP: " << this->enemy->getHP();
		afisareOptiuniJucator();
		
		int input;
		std::cin >> input;
	
		int puterePlayer = this->jucator->getPutere();
		int DC = this->calculatePlayersDC(puterePlayer);
		/*srand(time(0));
		int diceRoll = rand() % 20;*/

		
		if (input >= 1 && input < nrOptiuni)
		{
			Dice zar;

			if (this->compare(DC, zar.getDiceRoll()))
			{
				std::cout << "\n\tHIT!\n\n";
				this->enemy->scadeHP(this->jucator->getDamageDone(input));
				if (this->enemy->getHP() > 0)
					std::cout << "Enemy's HP: " << this->enemy->getHP() << std::endl;
			}
			else
			{
				std::cout << "MISS!\n";
			}

			if (this->enemy->getHP() > 0)
			{
				std::cout << "\n\tEnemy's turn...\n\n";
				std::this_thread::sleep_for(std::chrono::seconds(3));

				int enemyHitOrMiss = rand() % 100;


				if (enemyHitOrMiss > 50)
				{
					int aux = rand() % 4 + 1;
					this->enemy->printAbilitateaSelectata(aux);
					std::cout << "\n\t" << this->enemy->getName() << " HIT!\n";
					this->jucator->scadeHP(this->enemy->getDamageDone(aux));
				}
				else
				{
					std::cout << "\n\t" << this->enemy->getName() << " missed! Ahahah, you're lucky!\n";
				}
			}

			nrOptiuni = 1;
		}
		else
		{
			std::cout << "\n\n|| Input INVALID! ||\n\n";
		}
	} while (this->jucator->getHP() > 0 && this->enemy->getHP() > 0);

	if (this->jucator->getHP() < 0)
	{
		IException* e = new CustomException("\nInamicul a invins...\n");
		throw(e);
	}
	else
	{
		std::cout << "\n\n\tFelicitari! " << this->enemy->getName() << " a fost invins!\n";
	}
}
