#pragma once
#include "Biblioteki.h"
#include "Kolory.h"
class Bohater
{
private:
	//G³ówne elementy postaci
	string nazwa;
	int poziom;			//Aktualny poziom
	int exp;			//Ilosc doswiadczenia
	int expnextlvl;		//Ilosc doswiadczenia do kolejnego lvl
	int hp;				//Aktualny stan zdrowia
	int hpmax;			//Maksymalne HP

	//Statystyki gracza
	int sila;			//Wojownik
	int zrecznosc;		//£ucznik, Elf
	int magia;			//Mag
	int szczescie;		//Z³odziej, szczêœcie na itemy
	int obrona;			//Tank

	//Dodatki
	int pktum;			//Punkty umiejêtnoœci
public:
	Bohater();
	Bohater(string nazwa, int poziom, int exp,
		int expnextlvl, int hp, int hpmax, int sila,
		int zrecznosc, int magia, int szczescie, 
		int obrona, int pktum);
	virtual ~Bohater();

	void inicjalizacja(const string nazwa);
	void Wyswietl()const;
	void lvlup();
	void update();
	void odpoczynek();
	void zranienie();
	string getAsString() const;

	inline const bool graczgra() { return this->hp > 0; }
	inline const int graczsila() { return this->sila > 0; }
	inline const int graczzrecznosc() { return this->zrecznosc > 0; }
	inline const int graczmagia() { return this->magia > 0; }
	inline const int graczszczescie() { return this->szczescie > 0; }
	inline const int graczobrona() { return this->obrona > 0; }
	inline const int graczpoziom() { return this->poziom > 0; }
	inline const int graczexp() { return this->exp; }
	inline const int graczexpnextlvl() { return this->expnextlvl; }
	inline const int graczhp() { return this->hp > 0; }
	inline const int graczhpmax() { return this->hpmax > 0; }
	inline const int graczpktum() { return this->pktum > 0; }
	inline const std::string& getName() const { return this->nazwa; }
};

