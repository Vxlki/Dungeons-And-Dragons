#include "NPC.h"

NPC::NPC(std::string nume) : Personaj(2, nume)
{
}

std::string NPC::getDescription()
{
    std::string aux = "NPC:\n";
    aux += Personaj::getDescription();

    return aux;
}

void NPC::printAbilitateaSelectata(int n)
{
    if (n <= 3)
        this->clasaPersonaj->printOneAbilityClass(n);
    else
        this->rasaPersonaj->printOneAbilityRace(n);
}
