#pragma once
#include "Biblioteki.h"
#include "LinkiDoGry.h"

class PanelAdministratorski{
private:
	bool Mmenu;
	int wybor;
	int activemiasto;
	int activeMonster;
	string plikmiasto;
	string plikpotwor;
	vector<Miasto> Miasta;
	vector<Potwory> PPotwory;

public:
	//Podstawa
	PanelAdministratorski();
	virtual ~PanelAdministratorski() {};

	//Funkcje
	void Menu();
	void DodawaniePlikow();
	void saveMiasto();
	void NoweMiasto();
	void DodPotwor();
	void savePotwor();
	void loadMiasto();
	void loadPotwor();
	void PlikBledu(string nazwa, int kod); //Nazwa i kod b³êdu
};

