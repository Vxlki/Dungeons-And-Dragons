#pragma once
#include"Scenariu.h"
#include"Jucator.h"
#include"Combat.h"

class DungeonMaster
{
protected:
	static DungeonMaster* instance;
	DungeonMaster();
	~DungeonMaster();

	Scenariu* scene;
	Personaj* jucator;
	Personaj* enemy = nullptr;
	Combat* batalie = nullptr;
	int playersDC;
	int playersChoice;
	void calculatePlayersDC(int DC);
	int compare(int playersDC, int requiredDC);
	void printAruncareaCuZarul(int DC);
public:
	static DungeonMaster& createInstance();
	void deleteInstance();
	int afisareMesajHitOrMiss();
	void afisareScenariu();
};