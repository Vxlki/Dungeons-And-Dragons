#include "Game.h"

Game::Game() : DMaster(DungeonMaster::createInstance())
{
	int input = -1;
	std::cout << "\n\nPress 0 for exit...\n";
	while (this->DMaster.afisareMesajHitOrMiss())
	{
		int ok = -1;
	} 
}

Game::~Game()
{
	this->DMaster.deleteInstance();
}
