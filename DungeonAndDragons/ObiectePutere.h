#pragma once
#include"Obiecte.h"

class ObiectePutere : public Obiecte
{
protected:
	static int identifier;
public:
	ObiectePutere(std::string nume);
	void printObjInterraction() override;
	int getIdentifier();
	void printCustomMessage() override;
};