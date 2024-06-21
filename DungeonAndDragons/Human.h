#pragma once
#include"Rasa.h"
#include<string>

class Human : public Rasa
{
protected:
	float aruncareFurca();
public:
	std::string getRasa();
	void printAbilitateRasa(int& n);
	float damageAbilitate();
	void printOneAbilityRace(int n) override;
};