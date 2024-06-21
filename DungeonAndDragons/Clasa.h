#pragma once
#include<string>
class Clasa
{
protected:

public:
	virtual std::string getClasa() = 0;
	virtual void printAbilitateClasa(int& n) = 0;
	virtual float damageAbilitateClasa(int n) = 0;
	virtual void printOneAbilityClass(int n) = 0;
};