#pragma once
#include"Clasa.h"
#include"Rasa.h"
#include<iostream>
#include<iomanip>
#include<Windows.h>

typedef enum
{
	Default = 0, Soldat, Acolit, Hot
}Trecut;

class Personaj
{
protected:
	std::string numePersonaj;
	int inteligenta;
	int putere;
	int dexteritate;
	float HP;
	Clasa* clasaPersonaj;
	Rasa* rasaPersonaj;
	Trecut trecutPersonaj;
	std::string trecutToString(int aux);
	void printCalitati();

	static void printCentered(std::string s);
	static int getConsoleWidth();				//for it just to be a little bit more estetically pleasing
public:
	Personaj(std::string nume = "Nume_Implicit");
	Personaj(int debugging, int d2, std::string nume = "Nume_Implicit");
	Personaj(int NPC, std::string nume = "Nume_Implicit");

	virtual std::string getDescription();
	std::string getName();
	int getInteligenta();
	int getDexteritate();
	int getPutere();
	float getHP();
	
	void afisareOptiuniCombat(int& n);
	void scadeHP(float hit);
	float getDamageDone(int choice);
	void cresteInteligenta(int iq);
	virtual void printAbilitateaSelectata(int n) = 0;
};