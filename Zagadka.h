#pragma once
#include "Biblioteki.h"
class Zagadka{
private:
	string Pytanie;
	string Ciekawostka;
	vector<string> MozliweOdpowiedzi;
	int Odp;

public:
	//Podstawa
	Zagadka(string plik);
	virtual ~Zagadka() {};
	string getString();

	//Inline
	inline const int& PrawOdp()const { return this->Odp; }
	inline const string& Ciekawosc()const { return this->Ciekawostka; }
};

