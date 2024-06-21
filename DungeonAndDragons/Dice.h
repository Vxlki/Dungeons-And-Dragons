#pragma once
class Dice
{
	int diceRoll;
public:
	Dice();

	void operator+=(int i);

	int getDiceRoll();
};