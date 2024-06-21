#include "Fighter.h"

float Fighter::swordStab()
{
    srand(time(0));
    return rand() % 43;
}

float Fighter::tripleCutSword()
{
    srand(time(0));
    return rand() % 22;
}

float Fighter::hammerHit()
{
    srand(time(0));
    return rand() % 55;
}

std::string Fighter::getClasa()
{
    return "Fighter";
}

void Fighter::printAbilitateClasa(int& n)
{
    std::cout << "\t" << n++ << ". Sword Stab\n";
    std::cout << "\t" << n++ << ". Triple Cut\n";
    std::cout << "\t" << n++ << ". Hammer Hit\n\t";
}

float Fighter::damageAbilitateClasa(int n)
{
    switch (n)
    {
    case 1: return this->swordStab(); break;
    case 2: return this->tripleCutSword(); break;
    case 3: return this->hammerHit(); break;
    default: return 0;
    }
}

void Fighter::printOneAbilityClass(int n)
{
    switch (n)
    {
    case 1: std::cout << "\n\tEnemy stabbed you with his sword!\n"; break;
    case 2: std::cout << "\n\tEnemy tripple cut sword-ed you!\n"; break;
    case 3: std::cout << "\n\tEnemy Hammer hit-ed you!\n"; break;
    default: break;
    }
}
