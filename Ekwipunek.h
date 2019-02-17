#pragma once
#include"Biblioteki.h"
#include"Bronie.h"

class Ekwipunek{
private:
	int Ilosc;
	int NrPrzedmiotu;
	Przedmiot **Przedmiotwsk;
	void Kopiowanie();
	void Inicjalizacja(const int LiczbaIni = 0);

public:
	//Podstawa
	Ekwipunek();
	~Ekwipunek();
	Ekwipunek(const Ekwipunek &obiekt);
	
	//Operatory
	Przedmiot& operator[](const int numer);
	void operator=(const Ekwipunek &obiekt);

	//Funkcje
	void Dodprzedmiot(const Przedmiot &przedmiot);
	void Usunprzedmiot(int numer);

	//Inline
	inline int IloscEkw()const { return this->NrPrzedmiotu; };
};