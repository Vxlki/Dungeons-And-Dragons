#pragma once
#include<string>
#include<iostream>
class Rasa
{
protected:

public:
	virtual std::string getRasa() = 0;
	virtual void printAbilitateRasa(int& n) = 0;
	virtual float damageAbilitate() = 0;
	virtual void printOneAbilityRace(int n) = 0;
};