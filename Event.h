#pragma once
#include "Biblioteki.h"
#include "Bohater.h"
#include "Potwory.h"
#include "Zagadka.h"

class Event{
public:

	//Zmienne
	static int DuzyLos;
	static int MalyLos;

	//Podstawa
	Event();
	virtual ~Event();

	//Funkcje
	void Czekanie();
	void LosEvent(Bohater &bohater, Potwory &przeciwnik);
	void LosMalyEventSpanie(Bohater &bohater);
	void Wydarzenie(Bohater &bohater);
	void Walka(Bohater &bohater, Potwory& przeciwnik);
};