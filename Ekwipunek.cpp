#include "Ekwipunek.h"

Ekwipunek::Ekwipunek(){
	this->Ilosc = 3;
	this->NrPrzedmiotu = 0;
	this->Przedmiotwsk = new Przedmiot*[Ilosc];
	this->Inicjalizacja();
}

Ekwipunek::~Ekwipunek(){
	for (int i = 0; i < (int)this->NrPrzedmiotu; i++){//size_t
		delete this->Przedmiotwsk[i];
	}
	delete[] this->Przedmiotwsk;
}

Ekwipunek::Ekwipunek(const Ekwipunek &obj){
	this->Ilosc = obj.Ilosc;
	this->NrPrzedmiotu = obj.NrPrzedmiotu;
	this->Przedmiotwsk = new Przedmiot*[this->Ilosc];

	for (int i = 0; i < (int)this->NrPrzedmiotu; i++){//size_t
		this->Przedmiotwsk[i] = obj.Przedmiotwsk[i]->Kopiowanie();
	}

	Inicjalizacja(this->NrPrzedmiotu);
}

Przedmiot& Ekwipunek::operator[](const int index){
	if (index < 0 || index >= this->NrPrzedmiotu)
		throw("B³êdny numer!");

	return *this->Przedmiotwsk[index];
}

void Ekwipunek::operator=(const Ekwipunek &obj){
	for (int i = 0; i < (int)this->NrPrzedmiotu; i++){//size_t
		delete this->Przedmiotwsk[i];
	}
	delete[] this->Przedmiotwsk;

	this->Ilosc = obj.Ilosc;
	this->NrPrzedmiotu = obj.NrPrzedmiotu;
	this->Przedmiotwsk = new Przedmiot*[this->Ilosc];

	for (int i = 0; i < (int)this->NrPrzedmiotu; i++){//size_t
		this->Przedmiotwsk[i] = obj.Przedmiotwsk[i]->Kopiowanie();
	}

	Inicjalizacja(this->NrPrzedmiotu);
}

void Ekwipunek::expand(){
	this->Ilosc *= 2;

	Przedmiot **tempArr = new Przedmiot*[this->Ilosc];

	for (int i = 0; i < (int)this->NrPrzedmiotu; i++){//size_t
		tempArr[i] = this->Przedmiotwsk[i];
	}

	delete[] this->Przedmiotwsk;

	this->Przedmiotwsk = tempArr;

	this->Inicjalizacja(this->NrPrzedmiotu);
}

void Ekwipunek::Inicjalizacja(const int from){
	for (int i = from; i < Ilosc; i++){//size_t
		this->Przedmiotwsk[i] = nullptr;
	}
}

void Ekwipunek::Dodprzedmiot(const Przedmiot &przedmiot){
	if (this->NrPrzedmiotu >= this->Ilosc){ expand(); }
	this->Przedmiotwsk[this->NrPrzedmiotu++] = przedmiot.Kopiowanie();
}

void Ekwipunek::removeItem(int index){
	if (index < 0 || index >= this->NrPrzedmiotu)
		cout<<"Lista przedmiotów wysz³a poza zakres - naprawiæ?";

	delete this->Przedmiotwsk[index];
	this->Przedmiotwsk[index] = this->Przedmiotwsk[this->NrPrzedmiotu - 1];
	this->Przedmiotwsk[--this->NrPrzedmiotu] = nullptr;
}