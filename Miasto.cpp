#include "Miasto.h"

Miasto::Miasto(){
	numermiasta = 0;
	iloscbudynkow = 9;
	nrbudynku1 = 0;
	nrbudynku2 = 0;
	nrbudynku3 = 0;
	nazwa = "";
	activemiasto = 0;
	plik = "Miasta.txt";
}

Miasto::Miasto(int numermiasta, string nazwa, int nrbudynku1, int nrbudynku2, int nrbudynku3) {
	this->numermiasta = numermiasta;
	this->nazwa = nazwa;
	this->nrbudynku1 = nrbudynku1;
	this->nrbudynku2 = nrbudynku2;
	this->nrbudynku3 = nrbudynku3;
}

void Miasto::inicjalizacja(string nazwa, int max) {
	system("cls");
	int wybor, i=1;
	this->nazwa = nazwa;
	this->numermiasta = max + 1;
	cout << "Chcesz losowo czy recznie dodac budynki do miasta?" << endl;
	cout << "1 - losowo" << endl <<"2 - recznie" << endl;
	cin >> wybor;
	cin.clear();
	cin.ignore();
	if (wybor == 1) {
		this->nrbudynku1 = rand() % 9;
		this->nrbudynku2 = rand() % 9;
		this->nrbudynku3 = rand() % 9;
	} else {
		while (i < 4) {
			system("cls");
			cout << "Wybór budynku" << i << ": \n" << endl;
			cout << "1 - Tawerna" << endl;
			cout << "2 - Gospoda" << endl;
			cout << "3 - Kowal" << endl;
			cout << "4 - KuŸnia" << endl;
			cout << "5 - Koszary" << endl;
			cout << "6 - Magiczna Wie¿a" << endl;
			cout << "7 - Gildia Z³odzeji" << endl;
			cout << "8 - Rynek" << endl;
			cout << "9 - Pa³ac" << endl;

			cout << endl << "Jaki jest twoj wybor??: ";
			cin >> wybor;
			cin.clear();
			cin.ignore();
			switch (i) {
			case 1:
				this->nrbudynku1 = wybor;
				break;
			case 2:
				this->nrbudynku2 = wybor;
				break;
			case 3:
				this->nrbudynku3 = wybor;
				break;
			default:
				break;
			}
			i++;
		}
	}
}

string Miasto::getString() const {
	return nazwa + " " + to_string(numermiasta) + " " + to_string(nrbudynku1) + " " +
	to_string(nrbudynku2) + " " + to_string(nrbudynku3);
}

void Miasto::Wyswietl() const {
	Kolory kolor;
	system("cls");
	string nazwbud1 = budynki[nrbudynku1 - 1];
	string nazwbud2 = budynki[nrbudynku2 - 1];
	string nazwbud3 = budynki[nrbudynku3 - 1];
	kolor.gold(); cout << " ========================================" << endl;
	kolor.blue(); cout << "//"; kolor.red(); cout << "\t\tMiasto : "; kolor.blue(); cout << "\t\t\\\\" << endl;
	kolor.blue(); cout << "||\t\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tNazwa: "; kolor.green(); cout << this->nazwa; kolor.blue(); cout << endl;
	kolor.blue(); cout << "||\tBudynek1: "; kolor.green(); cout << nazwbud1; kolor.blue(); cout << endl;
	kolor.blue(); cout << "||\tBudynek2: "; kolor.green(); cout << nazwbud2; kolor.blue(); cout << endl;
	kolor.blue(); cout << "||\tBudynek3: "; kolor.green(); cout << nazwbud3; kolor.blue(); cout << endl;
	kolor.blue(); cout << "\\\\\t" << "\t\t\t\t//" << endl;
	kolor.gold(); cout << " ========================================" << endl;
}