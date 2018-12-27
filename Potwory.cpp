#include "Potwory.h"

Potwory::Potwory(int poziom){
	this->poziom = poziom;
	this->maxhp = rand() % (poziom * 10) + (poziom * 2);
	this->hp = this->maxhp;
	this->mindmg = this->poziom * 1;
	this->maxdmg = (this->poziom * 2) - 1;
	this->szansa = rand() % 100 + 1;
	this->obrona = rand() % poziom * 5 + 1;
	this->kasa = rand() % poziom * 5 + 1;
}

Potwory::~Potwory(){
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