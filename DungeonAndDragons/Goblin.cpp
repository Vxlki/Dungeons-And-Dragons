#include "Goblin.h"

float Goblin::goblinBarrel()
{
    srand(time(0));
    return rand() % 23;
}

std::string Goblin::getRasa()
{
    return "Goblin";
}

void Goblin::printAbilitateRasa(int& n)
{
    std::cout << "\t" << n++ << ". Goblin Barrel\n";
}

float Goblin::damageAbilitate()
{
    return goblinBarrel();
}

void Goblin::printOneAbilityRace(int n)
{
    std::cout << "\n\tEnemy thre a Goblin Barrel at you!\n";
}
