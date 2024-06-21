#pragma once
#include<iostream>
#include<vector>
#include"Obiecte.h"
#include"NPC.h"

class Scenariu
{
protected:
	std::string numeIncapere;
	std::vector<Obiecte*> obiecteIncapere;
	std::vector<std::string> accesIncaperiNoi;
	Personaj* enemy = nullptr;
public:
	void afisareScenariu();
	Scenariu(std::string fname);
	int getDCsiTipObiect(int& DC, int& pChoice);
	std::string getAccesIncaperiNoi(int choice);
	void customMessage(int choice);

	void stergereObiect(int playersChoice);
};