#pragma once
#include"Obiecte.h"
class ObiecteInteligenta : public Obiecte
{
protected:
	static int identifier;
public:
	ObiecteInteligenta(std::string nume);
	void printObjInterraction() override;
	int getIdentifier();
	void printCustomMessage() override;
};