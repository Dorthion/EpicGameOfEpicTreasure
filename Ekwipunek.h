#pragma once
#include"Biblioteki.h"
#include"Bronie.h"

class Ekwipunek{
private:
	int Ilosc;
	int NrPrzedmiotu; //nrOfItems
	Przedmiot **Przedmiotwsk; //itemArr
	void expand();
	void Inicjalizacja(const int from = 0);

public:
	//Podstawa
	Ekwipunek();
	~Ekwipunek();
	Ekwipunek(const Ekwipunek &obj);
	
	//Operatory
	Przedmiot& operator[](const int numer);
	void operator=(const Ekwipunek &obj);

	//Funkcje
	void Dodprzedmiot(const Przedmiot &przedmiot);
	void removeItem(int index);

	//Inline
	inline int size()const { return this->NrPrzedmiotu; };
	inline void debugPrint() const{
		for (int i = 0; i < (int)this->NrPrzedmiotu; i++){ //size_t
			cout << this->Przedmiotwsk[i]->przeNazwa() << endl;
		}
	}
};