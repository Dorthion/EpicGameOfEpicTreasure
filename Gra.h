#pragma once
//Pod³¹czenia
#include "Biblioteki.h"
#include "LinkiDoGry.h"
#include "PanelAdministratorski.h"
class Gra{
private:
	int wybor;
	bool playing;
	string plik;
	string plikmiasto;
	string nazwakonta;
	string plikpotwor;
	int activeCharacter;
	int activemiasto;
	int activeMonster;
	int bud1;
	int bud2;
	int bud3;
	int ukryj;
	std::vector<Bohater> Bohaterzy;
	std::vector<Miasto> Miasta;
	std::vector<Potwory> PPotwory;

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
	void stworzBohatera();
	void stworzKonto();
	void poke();
	void odpoczynek();
	void Czekanie();
	void Czekanie2();
	void Podroz();
	void wybormiasta();
	void loadPotwor();
	void DodawanieStat();
	void cheatengine();
	void PreKruci();
	void Kruci();
	void PreBoss();
	void Boss();
	void SklepWejscie();
	void PlikBledu(string nazwa, int kod);

	//Dodatki Inline
	inline bool CzyGra() const { return this->playing; }
};

