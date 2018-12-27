#include "Bohater.h"

Bohater::Bohater(){//Wyzerowanie statystyk
	this->nazwa = "";
	this->poziom = 0;
	this->exp = 0;
	this->expnextlvl = 0;
	this->hp = 0;
	this->hpmax = 0;
	this->sila = 0;
	this->zrecznosc = 0;
	this->magia = 0;
	this->szczescie = 0;
	this->obrona = 0;
	this->pktum = 0;
}


Bohater::~Bohater(){
}

Bohater::Bohater(string nazwa, int poziom, int exp,
	int expnextlvl, int hp, int hpmax, int sila,
	int zrecznosc, int magia, int szczescie,
	int obrona, int pktum){//Pocz¹tkowe statystyki
	this->nazwa = nazwa;
	this->poziom = poziom;
	this->exp = exp;
	this->expnextlvl = expnextlvl;
	this->hp = hp;
	this->hpmax = hpmax;
	this->sila = sila;
	this->zrecznosc = zrecznosc;
	this->magia = magia;
	this->szczescie = szczescie;
	this->obrona = obrona;
	this->pktum = pktum;
}
void Bohater::inicjalizacja(const string nazwa){
	//G³ówne elementy postaci
	this->nazwa = nazwa;
	this->poziom = 1;
	this->exp = 0;
	this->expnextlvl = 100;
	this->hp = 100;
	this->hpmax = 100;

	//Statystyki gracza
	this->sila = 10;
	this->zrecznosc = 5;
	this->magia = 5;
	this->szczescie = 5;
	this->obrona = 5;

	//Dodatki
	this->pktum = 0;

	//Update
	this->update();
}

void Bohater::Wyswietl() const{
	system("cls");
	cout << "Statystyki Bohatera: " << endl;
	cout << "Nazwa: " << this->nazwa << endl;
	cout << "Poziom: " << this->poziom << endl;
	cout << "Exp: " << this->exp << endl;
	cout << "Exp do kolejnego poziomu: " << this->expnextlvl << endl << endl;
	cout << "Punkty umiejetnosci: " << this->pktum << endl;
	cout << endl;
	cout << "Sila: " << this->sila << endl;
	cout << "Zrecznosc: " << this->zrecznosc << endl;
	cout << "Magia: " << this->magia << endl;
	cout << "Szczescie: " << this->szczescie << endl;
	cout << "Obrona: " << this->obrona << endl;
	cout << endl;
	cout << "Hp " << this->hp << " / " << this->hpmax << endl;
}

void Bohater::lvlup(){
	if (this->exp >= this->expnextlvl){
		this->exp -= this->expnextlvl;
		this->poziom++;
		this->expnextlvl = static_cast<int>((50 / 3)*((pow(poziom, 3)
			- 6 * pow(poziom, 2))
			+ 17 * poziom - 12)) + 100;

		this->pktum++;

		this->update();
		cout << "Zwiêkszono poziom bohatera " << this->poziom << "!" << "\n\n";
	} else {
		cout << "Potrzeba wiêcej doœwiadczenia" << endl;
	}
}

void Bohater::update(){
	this->expnextlvl = static_cast<int>(
		(50 / 3)*((pow(poziom, 3)
			- 6 * pow(poziom, 2))
			+ 17 * poziom - 12)) + 100;

	//this->hpmax = (this->hp) + this->poziom * 5;
}

string Bohater::getAsString() const{
	return nazwa + " " + to_string(poziom) + " "+ to_string(exp) + " "
	+ to_string(expnextlvl) + " " + to_string(hp) + " " + to_string(hpmax) + " "
	+ to_string(sila) + " " + to_string(zrecznosc) + " "+ to_string(magia) + " "
	+ to_string(szczescie) + " " + to_string(szczescie) + " "+ to_string(pktum);
}

void Bohater::odpoczynek() {
	cout << "W³aœnie odpoczywasz"<<endl;
	this->hp = this->hpmax;
}

void Bohater::zranienie() {
	cout << "Zostales zraniony" << endl;
	this->hp = this->hp - 5;
}