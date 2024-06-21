#pragma once
#include<string>
#include<iostream>
class Obiecte
{
protected:
	int difficultyClass;
	std::string numeObiect;
public:
	Obiecte(std::string nume);
	int getDC();
	virtual void printObjInterraction() = 0;
	friend std::ostream& operator<<(std::ostream&, Obiecte&);
	virtual int getIdentifier() = 0;
	virtual void printCustomMessage() = 0;
	virtual std::string getAccesNextRoom();
};