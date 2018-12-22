#pragma once
#include "Biblioteki.h"
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
	void update();
};

