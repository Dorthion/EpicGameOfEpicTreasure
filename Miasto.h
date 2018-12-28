#pragma once
#include "Biblioteki.h"
#include "Kolory.h"
class Miasto{
private:
	std::string nazwa;
	std::string plik;
	int numermiasta;
	int iloscbudynkow;
	int nrbudynku1;
	int nrbudynku2;
	int nrbudynku3;
	int activemiasto;
	std::string budynki[9] = { "Tawerna","Gospoda", "Kowal", "KuŸnia",
	"Koszary", "Magiczna Wie¿a", "Gildia Zlodzieji", "Rynek", "Palac" };
	

public:
	Miasto();
	Miasto(int numermiasta, string nazwa, int nrbudynku1, int nrbudynku2, int nrbudynku3);
	virtual ~Miasto();
	void inicjalizacja(string nazwa);
	void Wyswietl() const;
	string getAsString() const;

	inline const std::string& getName() const { return this->nazwa; }
};

