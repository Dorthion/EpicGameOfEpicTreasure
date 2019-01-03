#pragma once
#include "Biblioteki.h"
#include "LinkiDoGry.h"

class PanelAdministratorski{
private:
	int Mmenu;
	int wybor;
	int activemiasto;
	int activeMonster;
	string plikmiasto;
	string plikpotwor;
	std::vector<Miasto> Miasta;
	std::vector<Potwory> PPotwory;
public:
	PanelAdministratorski();
	virtual ~PanelAdministratorski();

	void Menu();
	void DodawaniePlikow();
	void saveMiasto();
	void NoweMiasto();
	void DodPotwor();
	void savePotwor();
	void loadMiasto();
	void loadPotwor();
	void PlikBledu(string nazwa, int kod);
};

