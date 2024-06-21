#pragma once
#include"Obiecte.h"

class ObiecteDexteritate : public Obiecte
{
protected:
	static int identifier;
	std::string acces;
public:
	ObiecteDexteritate(const char* nume, std::string acces);
	void printObjInterraction();
	int getIdentifier();
	void printCustomMessage() override;
	std::string getAccesNextRoom() override;
};