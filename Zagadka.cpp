#include "Zagadka.h"

Zagadka::Zagadka(string fileName){
	this->Odp = 0;
	int Prawda = 0;
	int LiczbaOdp = 0;
	ifstream plik(fileName);
	string OdpowiedziZPliku = "";
	string ciekawosc = "";
	
	if (plik.is_open()){
		std::getline(plik, this->pytanie);
		plik >> LiczbaOdp;
		plik.ignore();

		for (size_t i = 0; i < LiczbaOdp; i++){
			std::getline(plik, OdpowiedziZPliku);
			this->MozliweOdpowiedzi.push_back(OdpowiedziZPliku);
		}

		plik >> Prawda;
		this->Odp = Prawda;
		plik.ignore();
		std::getline(plik, this->ciekawostka);
		plik.ignore();
	}
	else cout<<("Brak zagadki!")<<endl;
	plik.close();
}

Zagadka::~Zagadka(){
}

string Zagadka::getAsString(){
	string odp = "";
	for (size_t i = 0; i < this->MozliweOdpowiedzi.size(); i++){
		odp += to_string(i) + ": " + this->MozliweOdpowiedzi[i] + "\n";
	}
	return this->pytanie + "\n" + "\n" + odp + "\n";
}