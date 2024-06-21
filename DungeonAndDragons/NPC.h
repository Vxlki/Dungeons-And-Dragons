#pragma once
#include"Personaj.h"

class NPC : public Personaj
{
protected:

public:
	NPC(std::string nume = "NPC");
	std::string getDescription() override;
	void printAbilitateaSelectata(int n) override;
};