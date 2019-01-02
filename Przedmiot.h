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
	virtual ~Przedmiot();

	//Dodatki virtual
	virtual Przedmiot* clone()const = 0;
	virtual string toString()const = 0;
	virtual string toStringSave()const = 0;

	//Dodatki inline
	inline string debugPrint() const { return this->nazwa; }
	inline const string& getName() const { return this->nazwa; }
	inline const int& getLevel() const { return this->poziom; }
	inline const int& getBuyValue() const { return this->cenas; }
	inline const int& getSellValue() const { return this->cenak; }
	inline const int& getRarity() const { return this->rzadkosc; }
	inline void setName(string nazwa) { this->nazwa = nazwa; }
};

//Rzadkosc Broni
enum rzadkosc {
	ZWYKLY = 0,
	POWSZECHNY,
	RZADKI,
	EPICKI,
	LEGENDARNY
};