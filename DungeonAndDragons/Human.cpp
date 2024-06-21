#include "Human.h"

float Human::aruncareFurca()
{
    srand(time(0));
    return rand() % 11;
}

std::string Human::getRasa()
{
    return "Human";
}

void Human::printAbilitateRasa(int& n)
{
    std::cout << "\t" << n++ << ". Aruncare cu furca\n";
}

float Human::damageAbilitate()
{
    return aruncareFurca();
}

void Human::printOneAbilityRace(int n)
{
    std::cout << "\n\tEnemy threw a pitchfork at you!\n";
}
