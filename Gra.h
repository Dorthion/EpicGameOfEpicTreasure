#pragma once
//Pod��czenia
#include "Biblioteki.h"
#include "Funkcje.h"
//Tylko tutaj u�ywamy, wi�c w main nam nie potrzebne

class Gra{
private:
	int wybor;
	bool playing;

public:
	Gra();
	virtual ~Gra();
	//Operatory (B�d� przeci��enia >:D )


	//G��wne funcke
	void Menu();

	//Jakie� dodatki
	inline bool CzyGra() const { return this->playing; }
};

