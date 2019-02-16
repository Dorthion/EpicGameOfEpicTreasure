#include "Przedmiot.h"

Przedmiot::Przedmiot(){
	this->nazwa = "Wyzerowanie";
	this->poziom = 0;
	this->rzadkosc = -1;
	this->cenak = 0;
	this->cenas = 0;
}

Przedmiot::Przedmiot(int poziom, int rzadkosc){
	this->nazwa = "NazwaDoWymiany";
	this->poziom = rand() % (poziom + 4) + 1;
	this->rzadkosc = rzadkosc;
	this->cenak = (this->poziom + this->rzadkosc) + this->poziom*this->rzadkosc * 10;
	this->cenas = (int)(this->cenak / 2) + 1;
}

Przedmiot::Przedmiot(string nazwa, int poziom, int rzadkosc, int cenak, int cenas){
	this->nazwa = nazwa;
	this->poziom = poziom;
	this->rzadkosc = rzadkosc;
	this->cenak = cenak;
	this->cenas = cenas;
}