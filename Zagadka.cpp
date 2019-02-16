#include "Zagadka.h"

Zagadka::Zagadka(string ArgPlik){
	this->Odp = 0;
	int Prawda = 0;
	int LiczbaOdp = 0;
	ifstream Plik(ArgPlik);
	string OdpowiedziZPliku = "";
	
	if (Plik.is_open()){
		getline(Plik, this->Pytanie);
		Plik >> LiczbaOdp;
		Plik.ignore();

		for (int i = 0; i < LiczbaOdp; i++){
			getline(Plik, OdpowiedziZPliku);
			this->MozliweOdpowiedzi.push_back(OdpowiedziZPliku);
		}

		Plik >> Prawda;
		this->Odp = Prawda;
		Plik.ignore();
		getline(Plik, this->Ciekawostka);
		Plik.ignore();
	}
	else cout<<("Brak zagadki!")<<endl;
	Plik.close();
}

string Zagadka::getString(){
	string odp = "";
	for (size_t i = 0; i < this->MozliweOdpowiedzi.size(); i++)
		odp += to_string(i) + ": " + this->MozliweOdpowiedzi[i] + "\n";
	return this->Pytanie + "\n\n" + odp + "\n";
}