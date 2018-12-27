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
	Kolory kolor;
	system("cls");
	kolor.gold(); cout << " ===============================================" << endl;
	kolor.blue(); cout << "//"; kolor.red(); cout<< "\tStatystyki Bohatera : "; kolor.blue(); cout <<"\t\t\t\\\\" << endl;
	kolor.blue(); cout << "||\tNazwa: "; kolor.green(); cout<< this->nazwa; kolor.blue(); cout << "\t\t\t||" << endl;
	kolor.blue(); cout << "||\tPoziom: "; kolor.green(); cout << this->poziom; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tExp: "; kolor.green(); cout << this->exp; kolor.blue(); cout << "\t\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tExp do kolejnego poziomu: "; kolor.green(); cout << this->expnextlvl; kolor.blue(); cout << "\t\t||" << endl;
	kolor.blue(); cout << "||\tPunkty umiejetnosci: "; kolor.green(); cout << this->pktum; kolor.blue(); cout << "\t\t\t||" << endl;
	kolor.blue(); cout << "||\t\t\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tSila: "; kolor.green(); cout << this->sila; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tZrecznosc: "; kolor.green(); cout << this->zrecznosc; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tMagia: "; kolor.green(); cout << this->magia; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tSzczescie: "; kolor.green(); cout << this->szczescie; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tObrona: "; kolor.green(); cout << this->obrona; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\t\t\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tHp "; kolor.green(); cout << this->hp << " / " << this->hpmax; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "\\\\\t" << "\t\t\t\t\t//" << endl;
	kolor.gold(); cout << " ===============================================" << endl;
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