#pragma once
//Pod³¹czenia
#include "Biblioteki.h"
#include "Bohater.h"
#include "Miasto.h"
#include "Kolory.h"
class Gra{
private:
	int wybor;
	bool playing;
	string plik;
	string plikmiasto;
	string nazwakonta;
	int activeCharacter;
	int activemiasto;
	std::vector<Bohater> Bohaterzy;
	std::vector<Miasto> Miasta;
	//std::vector<Przeciwnik> Przeciwnicy;

public:
	

	Gra();
	virtual ~Gra();

	//G³ówne funcke
	void Menu();
	void InitGry();
	void loadBohater();
	void loadMiasto();
	void saveBohater();
	void saveMiasto();
	void stworzBohatera();
	void stworzKonto();
	void poke();
	void NoweMiasto();
	void wybormiasta();

	//Jakieœ dodatki
	inline bool CzyGra() const { return this->playing; }
};

