#pragma once
#include"Personaj.h"

class Jucator : public Personaj
{
protected:

public:
	Jucator();
	std::string getDescription() override;
	void printAbilitateaSelectata(int n) override;
};