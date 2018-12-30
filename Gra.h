#pragma once
//Pod³¹czenia
#include "Biblioteki.h"
#include "LinkiDoGry.h"
class Gra{
private:
	int wybor;
	bool playing;
	string plik;
	string plikmiasto;
	string nazwakonta;
	string plikpotwor;
	//string plikludzi;
	int activeCharacter;
	int activemiasto;
	int activeMonster;
	std::vector<Bohater> Bohaterzy;
	std::vector<Miasto> Miasta;
	std::vector<Potwory> PPotwory;
	//std::vector<Potwory> PPotwory;

public:
	//Podstawa
	Gra();
	virtual ~Gra();

	//G³ówne funkcje
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
	void Podroz();
	void wybormiasta();
	void DodPotwor();
	void savePotwor();
	void loadPotwor();
	void PlikBledu(string nazwa, int kod);

	//Jakieœ dodatki
	inline bool CzyGra() const { return this->playing; }
};

