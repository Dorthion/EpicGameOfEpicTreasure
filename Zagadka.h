#pragma once
#include "Biblioteki.h"
class Zagadka{
private:
	string question;
	string ciekawostka;
	std::vector<std::string> MozliweOdpowiedzi;
	int Odp;

public:
	Zagadka(std::string plik);
	virtual ~Zagadka();
	std::string getAsString();

	inline const int& PrawOdp()const { return this->Odp; }
	inline const string& Ciekawosc()const { return this->ciekawostka; }
};

