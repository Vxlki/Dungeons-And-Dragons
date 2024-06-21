#pragma once
#include"Rasa.h"
#include<string>

class Goblin : public Rasa
{
protected:
	float goblinBarrel();
public:
	std::string getRasa();
	void printAbilitateRasa(int& n);
	float damageAbilitate();
	void printOneAbilityRace(int n) override;
};