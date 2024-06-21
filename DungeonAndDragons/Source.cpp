#include<iostream>
#include"IException.h"
#include"Personaj.h"
#include"Scenariu.h"
#include"DungeonMaster.h"
#include"Game.h"
#include"Combat.h"
using namespace std;

int main()
{
	try
	{
		Game* g = new Game();
		int a = 2;
 	}
	catch (IException* e)
	{
		e->printException();
	}

	return 0;
}