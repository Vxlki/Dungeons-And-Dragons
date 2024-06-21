#pragma once
#include"Clasa.h"
#include<string>
#include<iostream>

class Fighter : public Clasa
{
protected:
	float swordStab();
	float tripleCutSword();
	float hammerHit();
public:
	std::string getClasa();
	void printAbilitateClasa(int& n) override;
	float damageAbilitateClasa(int n) override;
	void printOneAbilityClass(int n) override;
};