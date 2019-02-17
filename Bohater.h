#pragma once
#include "Biblioteki.h"
#include "Kolory.h"
#include "Miasto.h"
#include "Ekwipunek.h"

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
	int zrecznosc;		//£ucznik
	int magia;			//Mag
	int szczescie;		//Z³odziej
	int obrona;			//Tank

	//Dodatki
	int pktum;			//Punkty umiejêtnoœci
	int miasto;			//Miasto w którym siê znajduje
	int kasa;			//Pieni¹dze gracza
	Bronie bron;		//Broñ gracza
	Ekwipunek ekwipunek;//Ekwipunek gracza
	string nazwamiasta; //Nazwa Miasta

public:
	//Podstawa
	Bohater();
	Bohater(string nazwa, int poziom, int exp,
		int expnextlvl, int hp, int hpmax, int sila,
		int zrecznosc, int magia, int szczescie, 
		int obrona, int pktum, int miasto, int kasa);
	virtual ~Bohater() {};

	//Funkcje
	void inicjalizacja(const string nazwa);
	void Wyswietl()const;
	void lvlup();
	void odczytnazwy();
	void zlespanie();
	void Czekanie();
	void sklep(int nrbudynku);
	void GraczObrazenia(const int Obrazenia);
	void DodawanieStatystyk(int stat, int cena);
	void zalozprzedmiot(unsigned numer);
	void usunprzedmiot(const int numer);
	void Dodprzedmiot(const Przedmiot &przedmiot) { this->ekwipunek.Dodprzedmiot(przedmiot); }
	const Przedmiot& wybranyprzedmiot(const int numer);
	string getString() const;
	string loadekwipunek(bool ladowanie = false);
	string saveekwipunek();
	string budynki[9] = { "Tawerna","Gospoda", "Kowal", "KuŸnia",
	"Koszary", "Magiczna Wie¿a", "Gildia Z³odziei", "Rynek", "Pa³ac" };

	//Inline
	inline const bool graczgra() { return this->hp > 0; }
	inline const int graczsila() { return this->sila; }
	inline const int graczzrecznosc() { return this->zrecznosc; }
	inline const int graczmagia() { return this->magia; }
	inline const int graczszczescie() { return this->szczescie; }
	inline const int graczobrona() { return this->obrona; }
	inline const int graczpoziom() { return this->poziom; }
	inline const int graczexp() { return this->exp; }
	inline const int graczkasa() { return this->kasa; }
	inline const int graczpktum() { return this->pktum; }
	inline const int graczmiasto() { return this->miasto; }
	inline const int graczekwipunek()const { return this->ekwipunek.IloscEkw(); }
	inline const int graczexpnextlvl() { return this->expnextlvl; }
	inline const int graczhp() { return this->hp; }
	inline const int graczhpmax() { return this->hpmax; }
	inline const string gracznazwa() const { return this->nazwa; }
	inline void graczdodexp(const int exp) { this->exp += exp; }
	inline void graczdodkasa(const int kasa) { this->kasa += kasa; }
	inline void graczodekasa(const int kasa) { this->kasa -= kasa; }
	inline void graczzerokasa() { this->kasa = 0; }
	inline void graczdodmagia(const int magia) { this->magia += magia; }
	inline void graczodemagia(const int magia) { this->magia -= magia; }
	inline void graczzeromagia() { this->magia = 0; }
	inline void cheat1() { this->sila += 50; }
	inline void cheat2() { this->zrecznosc += 50; }
	inline void cheat3() { this->magia += 50; }
	inline void cheat4() { this->szczescie += 50; }
	inline void cheat5() { this->obrona += 50; }
	inline void cheat6() { this->hp += 200; }
	inline void cheat7() { this->hpmax += 200; }
	inline void cheat8() { this->exp += 500; }
	inline void cheat9() { this->kasa += 200; }
	inline void cheat10() { this->pktum += 20; }
	inline void cheat11() { this->poziom += 10; }
	inline void wyspanie() { this->hp = this->hpmax; }
	inline void graczbron(Bronie bron) { this->bron = bron; }
	inline int graczdmg() { return rand() % (this->sila + 4 + this->bron.bronsilamax() + 
		this->bron.bronzremax() + this->bron.bronmagiamax()) + (this->sila - 4 +
		this->bron.bronsilamin() + this->bron.bronzremin() + this->bron.bronmagiamin()); } 
};