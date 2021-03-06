#pragma once
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
	int AktywnyBohater;
	int AktywneMiasto;
	int AktywnyPotwor;
	int bud1;
	int bud2;
	int bud3;
	int ukryj;
	vector<Bohater> Bohaterzy;
	vector<Miasto> Miasta;
	vector<Potwory> PPotwory;

public:
	//Podstawa
	Gra();
	virtual ~Gra() {};

	//G��wne funkcje
	void Menu();
	void WyswietlMenu();
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
	void ZmianaBroni();
	void PreKruci();
	void Kruci();
	void PreBoss();
	void Boss();
	void SklepWejscie();
	void UsunKonto();
	void Wolniej(const string& Wiadomosc, unsigned int LiczbaMS);
	void PlikBledu(string nazwa, int kod);

	//Dodatki Inline
	inline bool CzyGra() const { return this->playing; }
};

