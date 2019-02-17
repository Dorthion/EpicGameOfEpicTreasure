#pragma once
#include "Biblioteki.h"
#include "Przedmiot.h"
#include "wsk.h"

class Bronie : public Przedmiot {
private:
	int minsila;		//Si³a
	int maxsila;
	int minzre;			//Zrêcznoœæ
	int maxzre;
	int minmagia;		//Magia
	int maxmagia;
	int minszcz;		//Szczêœcie
	int maxszcz;
	int minobr;			//Obrona
	int maxobr;

public:
	//Podstawa
	Bronie();
	Bronie( int nrbuydynku, int poziom, int rzadkosc );
	Bronie( int mindmg, int maxdmg,
	int minzre, int maxzre,
	int minmagia, int maxmagia,
	int minszcz, int maxszcz,
	int minobr, int maxobr,
	string nazwa, int poziom,
	int cenak, int cenas, int rzadkosc);
	virtual ~Bronie() {};
	virtual Bronie* Kopiowanie()const;//Virtualka
	string toString()const;
	string saveString()const;

	//Inline
	inline int bronsilamin()const { return this->minsila; }
	inline int bronsilamax()const { return this->maxsila; }
	inline int bronzremin()const { return this->minzre; }
	inline int bronzremax()const { return this->maxzre; }
	inline int bronmagiamin()const { return this->minmagia; }
	inline int bronmagiamax()const { return this->maxmagia; }
	inline int bronszczmin()const { return this->minszcz; }
	inline int bronszczmax()const { return this->maxszcz; }
	inline int bronobrmin()const { return this->minobr; }
	inline int bronobrmax()const { return this->maxobr; }
};