#include "Elf.h"

float Elf::throwIceSpikes()
{
    srand(time(0));
    return rand() % 34;
}

std::string Elf::getRasa()
{
    return "Elf";
}

void Elf::printAbilitateRasa(int& n)
{
    std::cout <<"\t" << n++ << ". Throw Ice Spikes\n";
}

float Elf::damageAbilitate()
{
    return throwIceSpikes();
}

void Elf::printOneAbilityRace(int n)
{
    std::cout << "\n\tEnemy threw Ice Spikes\n";
}
