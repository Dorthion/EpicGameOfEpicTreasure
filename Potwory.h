#pragma once
#include "Biblioteki.h"
class Potwory{
private:
	string nazwa;
	int numerpotwora;
	int poziom;
	int hp;
	int maxhp;
	int mindmg;
	int maxdmg;
	int kasa;
	int obrona;
	int szansa;
public:
	//Podstawa
	Potwory();
	Potwory(int poziom);
	virtual ~Potwory();

	//Funkcje
	std::string GetAsString()const;
	inline bool pzyje() { return this->hp > 0; }
	void Obrazenia(int sila);
	std::string Wyswietl()const;
	Potwory(string nazwa, int numerpotwora, int poziom, int hp,
	int maxhp, int mindmg, int maxdmg, int kasa,
	int obrona, int szansa);
	void inicjalizacja(std::string nazwa, int max, int poziom);

	//Inline
	inline int plvl()const { return this->poziom; }
	inline int pmindmg() { return this->mindmg; }
	inline int pmaxdmg() { return this->maxdmg; }
	//inline int pdmg()const { return rand() % this->maxdmg + this->mindmg; }
	inline int pexp()const { return this->poziom * 15; }
	inline int php()const { return this->hp; }
	inline int pmaxhp()const { return this->maxhp; }
	inline int pobrona()const { return this->obrona; }
	inline int pszansa()const { return this->szansa; }
	inline int pkasa()const { return this->kasa; }
	inline const std::string& getName() const { return this->nazwa; }
	inline const int nrpotwora() { return this->numerpotwora; }
};

