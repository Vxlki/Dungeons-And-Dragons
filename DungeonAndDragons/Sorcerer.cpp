#include "Sorcerer.h"

float Sorcerer::fireBall()
{
    srand(time(0));
    return rand() % 62;
}

float Sorcerer::electricWaves()
{
    srand(time(0));
    return rand() % 44;
}

float Sorcerer::summonOfTheDeads()
{
    srand(time(0));
    return rand() % 31;
}

std::string Sorcerer::getClasa()
{
    return "Sorcerer";
}

void Sorcerer::printAbilitateClasa(int& n)
{
    std::cout << "\t" << n++ << ". FireBall\n";
    std::cout << "\t" << n++ << ". Electric Waves\n";
    std::cout << "\t" << n++ << ". Summon the Deads\n\t";
}

float Sorcerer::damageAbilitateClasa(int n)
{
    switch (n)
    {
    case 1: return this->fireBall(); break;
    case 2: return this->electricWaves(); break;
    case 3: return this->summonOfTheDeads(); break;
    default: return 0;
    }
}

void Sorcerer::printOneAbilityClass(int n)
{
    switch (n)
    {
    case 1: std::cout << "\n\tEnemy threw a Fireball at you!\n"; break;
    case 2: std::cout << "\n\tEnemy sent Electric Waves at you!\n"; break;
    case 3: std::cout << "\n\tEnemy summoned the Deads on you!\n"; break;
    default: break;
    }
}
