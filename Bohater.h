#pragma once
#include "Biblioteki.h"
#include "Kolory.h"
#include "Miasto.h"
class Bohater{
private:
	//G³ówne elementy postaci
	string nazwa;		//Nazwa postaci
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
	int miasto;			//Miasto w którym siê znajduje
	int kasa;			//Pieni¹dze gracza

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
	void DodawanieStatystyk(int stat, int value);
	string getAsString() const;

	//Inline
	inline const bool graczgra() { return this->hp > 0; }
	inline const int graczsila() { return this->sila; }
	inline const int graczzrecznosc() { return this->zrecznosc; }
	inline const int graczmagia() { return this->magia; }
	inline const int graczszczescie() { return this->szczescie; }
	inline const int graczobrona() { return this->obrona; }
	inline const int graczpoziom() { return this->poziom; }
	inline const int& graczexp() { return this->exp; }
	inline void graczdodexp(const int exp) { this->exp += exp; }
	inline void graczdodkasa(const int kasa) { this->kasa += kasa; }
	inline void graczodekasa(const int kasa) { this->kasa -= kasa; }
	inline void graczzerokasa() { this->kasa = 0; }
	inline void cheat() { this->exp += 50; }
	inline const int graczexpnextlvl() { return this->expnextlvl; }
	inline const int graczhp() { return this->hp ; }
	inline const int graczhpmax() { return this->hpmax; }
	inline const int& graczpktum() { return this->pktum; }
	inline const int graczmiasto() { return this->miasto; }
	inline int graczdmg() { return rand() % (this->sila + 4) + (this->sila - 4); } // + this->weapon.getDamageMax()) + (this->damageMin + this->weapon.getDamageMin()); }
	inline const int& graczkasa() { return this->kasa; }
	inline const std::string& getName() const { return this->nazwa; }
};

