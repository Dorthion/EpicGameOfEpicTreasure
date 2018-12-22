#pragma once
//Pod³¹czenia
#include "Biblioteki.h"
#include "Funkcje.h"
//Tylko tutaj u¿ywamy, wiêc w main nam nie potrzebne

class Gra{
private:
	int wybor;
	bool playing;

public:
	Gra();
	virtual ~Gra();
	//Operatory (Bêd¹ przeci¹¿enia >:D )


	//G³ówne funcke
	void Menu();

	//Jakieœ dodatki
	inline bool CzyGra() const { return this->playing; }
};

