#pragma once
#include "Biblioteki.h"
#include "Kolory.h"
#include "Miasto.h"
class Bohater{
private:
	//G��wne elementy postaci
	string nazwa;		//Nazwa postaci
	int poziom;			//Aktualny poziom
	int exp;			//Ilosc doswiadczenia
	int expnextlvl;		//Ilosc doswiadczenia do kolejnego lvl
	int hp;				//Aktualny stan zdrowia
	int hpmax;			//Maksymalne HP

	//Statystyki gracza
	int sila;			//Wojownik
	int zrecznosc;		//�ucznik, Elf
	int magia;			//Mag
	int szczescie;		//Z�odziej, szcz�cie na itemy
	int obrona;			//Tank

	//Dodatki
	int pktum;			//Punkty umiej�tno�ci
	int miasto;			//Miasto w kt�rym si� znajduje
	int kasa;

public:
	//Temp
	std::string nazwamiasta;

	//Podstawa
	Bohater();
	Bohater(string nazwa, int poziom, int exp,
		int expnextlvl, int hp, int hpmax, int sila,
		int zrecznosc, int magia, int szczescie, 
		int obrona, int pktum, int miasto, int kasa);
	virtual ~Bohater();

	//Funkcje
	void inicjalizacja(const string nazwa);
	void Wyswietl()const;
	void lvlup();
	void update();
	void odpoczynek();
	void odczytnazwy();
	void zranienie();
	void zlespanie();
	void GraczObrazenia(const int Obrazenia);
	string getAsString() const;

	//Inline
	inline const bool graczgra() { return this->hp > 0; }
	inline const int graczsila() { return this->sila > 0; }
	inline const int graczzrecznosc() { return this->zrecznosc > 0; }
	inline const int graczmagia() { return this->magia > 0; }
	inline const int graczszczescie() { return this->szczescie > 0; }
	inline const int graczobrona() { return this->obrona > 0; }
	inline const int graczpoziom() { return this->poziom > 0; }
	inline const int graczexp() { return this->exp; }
	inline const int graczdodexp(int dod) { return this->exp + dod; }
	inline const int graczdodkasa(int dod) { return this->kasa + dod; }
	inline const int graczexpnextlvl() { return this->expnextlvl; }
	inline const int graczhp() { return this->hp ; }
	inline const int graczhpmax() { return this->hpmax; }
	inline const int graczpktum() { return this->pktum > 0; }
	inline const int graczmiasto() { return this->miasto; }
	inline const int graczdmg()const { return rand() % ((rand() % (this->sila + 4) + (this->sila - 4))); } // + this->weapon.getDamageMax()) + (this->damageMin + this->weapon.getDamageMin()); }
	inline const int graczkasa() { return this->kasa; }
	inline const std::string& getName() const { return this->nazwa; }
};

