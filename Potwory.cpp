#include "Potwory.h"

Potwory::Potwory() {
	this->nazwa = "";
	this->poziom = 0;
	this->maxhp = 0;
	this->hp = 0;
	this->mindmg = 0;
	this->maxdmg = 0;
	this->szansa = 0;
	this->obrona = 0;
	this->kasa = 0;
	this->numerpotwora = 0;
}

Potwory::Potwory(int poziom){
	this->nazwa = "Random nazwa";
	this->poziom = poziom;
	this->maxhp = rand() % (poziom * 10) + (poziom * 2);
	this->hp = this->maxhp;
	this->mindmg = this->poziom * 1;
	this->maxdmg = (this->poziom * 2) - 1;
	this->szansa = rand() % 100 + 1;
	this->obrona = rand() % poziom * 5 + 1;
	this->kasa = rand() % poziom * 10 + 1;
}

Potwory::~Potwory(){
}

void Potwory::inicjalizacja(string nazwa, int max) {
	//G��wne elementy postaci
	this->poziom = poziom;
	this->maxhp = rand() % (poziom * 10) + (poziom * 2);
	this->hp = this->maxhp;
	this->mindmg = this->poziom * 1;
	this->maxdmg = (this->poziom * 2) - 1;
	this->szansa = rand() % 100 + 1;
	this->obrona = rand() % poziom * 5 + 1;
	this->kasa = rand() % poziom * 10 + 1;
	this->numerpotwora = max;
}

std::string Potwory::GetAsString()const{
	return "Poziom: " + std::to_string(this->poziom) + "\n" +
		"Hp: " + std::to_string(this->hp) + " / " + std::to_string(this->maxhp) + "\n" +
		"Sila: " + std::to_string(this->mindmg) + " - " + std::to_string(this->maxdmg) + "\n" +
		"Obrona: " + std::to_string(this->obrona) + "\n" +
		"Ilosc monet: " + std::to_string(this->kasa) + "\n" +
		"Szansa na item: " + std::to_string(this->szansa) + "\n";
}

void Potwory::Obrazenia(int damage){
	this->hp -= damage;
	if (this->hp <= 0){
		this->hp = 0;
	}
}

Potwory::Potwory(string nazwa, int numerpotwora, int poziom, int hp, int maxhp, int mindmg,
	int maxdmg, int kasa, int obrona, int szansa) {
	this->poziom = poziom;
	this->maxhp = rand() % (poziom * 10) + (poziom * 2);
	this->hp = this->maxhp;
	this->mindmg = this->poziom * 1;
	this->maxdmg = (this->poziom * 2) - 1;
	this->szansa = rand() % 100 + 1;
	this->obrona = rand() % poziom * 5 + 1;
	this->kasa = rand() % poziom * 10 + 1;
	this->numerpotwora = numerpotwora;
}