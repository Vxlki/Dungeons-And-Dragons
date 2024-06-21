#pragma once
#include<string>
#include"Rasa.h"

class Elf : public Rasa
{
protected:
	float throwIceSpikes();
public:
	std::string getRasa();
	void printAbilitateRasa(int& n) override;
	float damageAbilitate();
	void printOneAbilityRace(int n) override;
};