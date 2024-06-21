#pragma once
#include"Clasa.h"
#include<string>
#include<iostream>

class Sorcerer : public Clasa
{
protected:
	float fireBall();
	float electricWaves();
	float summonOfTheDeads();
public:
	std::string getClasa();
	void printAbilitateClasa(int& n) override;
	float damageAbilitateClasa(int n) override;
	void printOneAbilityClass(int n) override;
};