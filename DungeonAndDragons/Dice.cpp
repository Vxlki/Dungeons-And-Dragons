#include "Dice.h"
#include<iostream>

Dice::Dice()
{
	srand(time(0));
	this->diceRoll = rand() % 20;
}

void Dice::operator+=(int i)
{
	this->diceRoll += i;
}

int Dice::getDiceRoll()
{
	return this->diceRoll;
}
