#pragma once
#include "Biblioteki.h"
class Potwory{
private:
	std::string nazwa;
	int poziom;
	int hp;
	int maxhp;
	int mindmg;
	int maxdmg;
	int kasa;
	int obrona;
	int szansa;
public:
	Potwory(int poziom);
	virtual ~Potwory();

	std::string GetAsString()const;
	void Obrazenia(int sila);
};

