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

void Bohater::Wyswietl() const
{
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
	cout << "Obrana: " << this->obrona << endl;
	cout << endl;
	cout << "Hp " << this->hp << " / " << this->hpmax << endl;
	/*cout << "= Stamina: " << this->stamina << " / " << this->staminaMax << endl;
	cout << "= Damage: " << this->damageMin << "( +" << this->weapon.getDamageMin() << ")" << " - " << this->damageMax << "( +" << this->weapon.getDamageMax() << ")" << "\n";
	cout << "= Defence: " << this->defence << "( +" << std::to_string(this->getAddedDefence()) << ")" << "\n";
	cout << "= Accuracy: " << this->accuracy << endl;
	cout << "= Distance Travelled: " << this->distanceTravelled << "\n";
	cout << "= Gold: " << this->gold << "\n";
	cout << "\n";
	cout << "= Weapon: " << this->weapon.getName()
		<< " Lvl: " << this->weapon.getLevel()
		<< " Dam: " << this->weapon.getDamageMin() << " - " << this->weapon.getDamageMax() << "\n";
	cout << "= Armor Head: " << this->armor_head.getName()
		<< " Lvl: " << this->armor_head.getLevel()
		<< " Def: " << this->armor_head.getDefence() << "\n";
	cout << "= Armor Chest: " << this->armor_chest.getName()
		<< " Lvl: " << this->armor_chest.getLevel()
		<< " Def: " << this->armor_chest.getDefence() << "\n";
	cout << "= Armor Arms: " << this->armor_arms.getName()
		<< " Lvl: " << this->armor_arms.getLevel()
		<< " Def: " << this->armor_arms.getDefence() << "\n";
	cout << "= Armor Legs: " << this->armor_legs.getName()
		<< " Lvl: " << this->armor_legs.getLevel()
		<< " Def: " << this->armor_legs.getDefence() << endl << endl;*/
}

void Bohater::update(){
	this->expnextlvl = static_cast<int>(
		(50 / 3)*((pow(poziom, 3)
			- 6 * pow(poziom, 2))
			+ 17 * poziom - 12)) + 100;

	this->hpmax = (this->sila) + this->poziom * 5;
	//this->damageMin = this->strength;
	//this->damageMax = this->strength + 2;
	//this->defence = this->dexterity + (this->intelligence / 2);
	//this->accuracy = (this->dexterity / 2) + intelligence;
	//this->luck = this->intelligence;

	//this->hp = this->hpMax;
}
