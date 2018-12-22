#include "Gra.h"

Gra::Gra(){
	wybor = 0;
	playing = true;
}


Gra::~Gra(){

}

void Gra::Menu(){
	system("cls");
	cout << "\t>>>>>MENU<<<<<<" << endl;
	cout << "Podaj swój wybor: \n" << endl;
	cout << "1 - Postac" << endl;
	cout << "2 - Miasto" << endl;
	cout << "3 - Podroz" << endl;
	cout << "4 - Dungeon" << endl;
	cout << "5 - Krucjata" << endl;
	cout << "6 - Odpoczynek" << endl;
	cout << "\n0 - Wyjscie" << endl;

	cout << endl << "Jaki jest twoj wybor??: ";

	cin >> wybor;

	switch (wybor) {
		case 0:
			playing = false;
			break;
		case 1:
			cout << "Wszedles do postaci";
			break;
		default:
			break;
	}
}
