#pragma once
#include"Personaj.h"
class Combat
{
protected:
	static int nrOptiuni;
	Personaj* jucator;
	Personaj* enemy;
	void afisareOptiuniJucator();
	int calculatePlayersDC(int DC);
	int compare(int DC, int diceRoll);
public:
	Combat(Personaj* player, Personaj* enemy);
};