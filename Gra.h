#pragma once
//Pod³¹czenia
#include "Biblioteki.h"
#include "Bohater.h"
#include "Kolory.h"
class Gra{
private:
	int wybor;
	bool playing;
	string plik;
	string nazwakonta;
	int activeCharacter;
	std::vector<Bohater> Bohaterzy;
	
	//std::vector<Przeciwnik> Przeciwnicy;

public:
	

	Gra();
	virtual ~Gra();

	//G³ówne funcke
	void Menu();
	void InitGry();
	void loadBohater();
	void saveBohater();
	void stworzBohatera();
	void stworzKonto();
	//void red();

	//Jakieœ dodatki
	inline bool CzyGra() const { return this->playing; }
	//void red(){ SetConsoleTextAttribute(hOut, FOREGROUND_RED); }
};

