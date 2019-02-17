#include "Ekwipunek.h"

Ekwipunek::Ekwipunek(){
	this->Ilosc = 3;
	this->NrPrzedmiotu = 0;
	this->Przedmiotwsk = new Przedmiot*[Ilosc];
	this->Inicjalizacja();
}

Ekwipunek::~Ekwipunek(){
	for (int i = 0; i < (int)this->NrPrzedmiotu; i++){
		delete this->Przedmiotwsk[i];
	}
	delete[] this->Przedmiotwsk;
}

Ekwipunek::Ekwipunek(const Ekwipunek &obiekt){
	this->Ilosc = obiekt.Ilosc;
	this->NrPrzedmiotu = obiekt.NrPrzedmiotu;
	this->Przedmiotwsk = new Przedmiot*[this->Ilosc];
	for (int i = 0; i < (int)this->NrPrzedmiotu; i++){
		this->Przedmiotwsk[i] = obiekt.Przedmiotwsk[i]->Kopiowanie();
	}
	Inicjalizacja(this->NrPrzedmiotu);
}

Przedmiot& Ekwipunek::operator[](const int index){
	if (index < 0 || index >= this->NrPrzedmiotu)
		cout<<"B³êdny numer!"<<endl;

	return *this->Przedmiotwsk[index];
}

void Ekwipunek::operator=(const Ekwipunek &obiekt){
	for (int i = 0; i < (int)this->NrPrzedmiotu; i++){
		delete this->Przedmiotwsk[i];
	}
	delete[] this->Przedmiotwsk;
	this->Ilosc = obiekt.Ilosc;
	this->NrPrzedmiotu = obiekt.NrPrzedmiotu;
	this->Przedmiotwsk = new Przedmiot*[this->Ilosc];
	for (int i = 0; i < (int)this->NrPrzedmiotu; i++){
		this->Przedmiotwsk[i] = obiekt.Przedmiotwsk[i]->Kopiowanie();
	}
	Inicjalizacja(this->NrPrzedmiotu);
}

void Ekwipunek::Kopiowanie(){
	this->Ilosc *= 2;
	Przedmiot **tempwsk = new Przedmiot*[this->Ilosc];
	for (int i = 0; i < (int)this->NrPrzedmiotu; i++){
		tempwsk[i] = this->Przedmiotwsk[i];
	}
	delete[] this->Przedmiotwsk;
	this->Przedmiotwsk = tempwsk;
	this->Inicjalizacja(this->NrPrzedmiotu);
}

void Ekwipunek::Inicjalizacja(const int LiczbaIni){
	for (int i = LiczbaIni; i < Ilosc; i++){
		this->Przedmiotwsk[i] = nullptr;
	}
}

void Ekwipunek::Dodprzedmiot(const Przedmiot &przedmiot){
	if (this->NrPrzedmiotu >= this->Ilosc){ Kopiowanie(); }
	this->Przedmiotwsk[this->NrPrzedmiotu++] = przedmiot.Kopiowanie();
}

void Ekwipunek::Usunprzedmiot(int numer){
	if (numer < 0 || numer >= this->NrPrzedmiotu)
		cout<<"Lista przedmiotów wysz³a poza zakres"<<endl;

	delete this->Przedmiotwsk[numer];
	this->Przedmiotwsk[numer] = this->Przedmiotwsk[this->NrPrzedmiotu - 1];
	this->Przedmiotwsk[--this->NrPrzedmiotu] = nullptr;
}