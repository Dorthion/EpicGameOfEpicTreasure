#pragma once
#include "Biblioteki.h"
#include "Bohater.h"
#include "Potwory.h"
//#include "Wydarzenie.h"

class Event{
public:
	static int nrOfEvents;
	Event();
	virtual ~Event();
	void LosEvent(Bohater &character, Potwory &enemy);
	void LosMalyEvent(Bohater &character);
	void enemyEncouter(Bohater &character, Potwory& enemies);
	//void puzzleEncouter(Bohater &character);
};