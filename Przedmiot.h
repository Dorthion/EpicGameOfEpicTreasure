#pragma once
#include"Biblioteki.h"

class Przedmiot{
private:
	string nazwa;	//Nazwa przedmiotu
	int poziom;		//Poziom przedmiotu
	int rzadkosc;	//Rzadkoœæ przedmiotu
	int cenak;		//Cena Kupna
	int cenas;		//Cena Sprzedania

public:
	//Podstawa
	Przedmiot();
	Przedmiot( int poziom, int rzadkosc);
	Przedmiot(string nazwa, int poziom,
		int rzadkosc, int cenak, int cenas);
	virtual ~Przedmiot() {};

	//Dodatki virtual
	virtual Przedmiot* Kopiowanie()const = 0;
	virtual string toString()const = 0;
	virtual string saveString()const = 0;

	//Dodatki inline
	inline string przeNazwa() const { return this->nazwa; } //Poka¿ nazwê bez zmian
	inline const string& przedmiotNazwa() const { return this->nazwa; }
	inline const int& przedmiotPoziom() const { return this->poziom; }
	inline const int& przedmiotCenak() const { return this->cenas; }
	inline const int& przedmiotCenas() const { return this->cenak; }
	inline const int& przedmiotRzadkosc() const { return this->rzadkosc; }
	inline void ustawNazwe(string nazwa) { this->nazwa = nazwa; }
};

//Rzadkosc Broni
enum rzadkosc {
	ZWYKLY = 0,
	POWSZECHNY,
	RZADKI,
	EPICKI,
	LEGENDARNY
};