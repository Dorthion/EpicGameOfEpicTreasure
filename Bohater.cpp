#include "Bohater.h"

Bohater::Bohater(){//Wyzerowanie statystyk
	this->nazwa = "";
	this->poziom = 0;
	this->exp = 0;
	this->expnextlvl = 0;
	this->hp = 0;
	this->hpmax = 0;
	this->sila = 0;
	this->zrecznosc = 0;
	this->magia = 0;
	this->szczescie = 0;
	this->obrona = 0;
	this->pktum = 0;
	this->miasto = 1;
	this->kasa = 0;

	this->nazwamiasta = "";
}

Bohater::~Bohater(){
}

Bohater::Bohater(string nazwa, int poziom, int exp, int expnextlvl, int hp, int hpmax, int sila, //Pocz�tkowe statystyki
	int zrecznosc, int magia, int szczescie, int obrona, int pktum, int miasto, int kasa){
	this->nazwa = nazwa;
	this->poziom = poziom;
	this->exp = exp;
	this->expnextlvl = expnextlvl;
	this->hp = hp;
	this->hpmax = hpmax;
	this->sila = sila;
	this->zrecznosc = zrecznosc;
	this->magia = magia;
	this->szczescie = szczescie;
	this->obrona = obrona;
	this->pktum = pktum;
	this->miasto = miasto;
	this->kasa = kasa;
	odczytnazwy();
}

void Bohater::inicjalizacja(const string nazwa){
	//G��wne elementy postaci
	this->nazwa = nazwa;
	this->poziom = 1;
	this->exp = 0;
	this->expnextlvl = 100;
	this->hp = 100;
	this->hpmax = 100;

	//Statystyki gracza
	this->sila = 10;
	this->zrecznosc = 5;
	this->magia = 5;
	this->szczescie = 5;
	this->obrona = 5;

	//Dodatki
	this->pktum = 0;
	this->miasto = 1;
	this->kasa = 20;

	//Update
	odczytnazwy();
}

void Bohater::Wyswietl() const{
	Kolory kolor;
	system("cls");
	kolor.gold(); cout << " ===============================================" << endl;
	kolor.blue(); cout << "//"; kolor.red(); cout<< "\t\tStatystyki Bohatera : "; kolor.blue(); cout <<"\t\t\\\\" << endl;
	kolor.blue(); cout << "||\t\t\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tNazwa: "; kolor.green(); cout<< this->nazwa; kolor.blue(); cout << "\t\t\t||" << endl;
	kolor.blue(); cout << "||\tPoziom: "; kolor.green(); cout << this->poziom; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tExp: "; kolor.green(); cout << this->exp; kolor.blue(); cout << "\t\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tExp do kolejnego poziomu: "; kolor.green(); cout << this->expnextlvl; kolor.blue(); cout << "\t\t||" << endl;
	kolor.blue(); cout << "||\tPunkty umiejetnosci: "; kolor.green(); cout << this->pktum; kolor.blue(); cout << "\t\t\t||" << endl;
	kolor.blue(); cout << "||\t\t\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tSila: "; kolor.green(); cout << this->sila; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tZrecznosc: "; kolor.green(); cout << this->zrecznosc; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tMagia: "; kolor.green(); cout << this->magia; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tSzczescie: "; kolor.green(); cout << this->szczescie; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tObrona: "; kolor.green(); cout << this->obrona; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\t\t\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tHp "; kolor.green(); cout << this->hp << " / " << this->hpmax; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tMiasto "; kolor.green(); cout << this->nazwamiasta; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tKasa "; kolor.green(); cout << this->kasa; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "\\\\\t" << "\t\t\t\t\t//" << endl;
	kolor.gold(); cout << " ===============================================" << endl;
}

void Bohater::lvlup(){
	this->exp = 0;
	this->expnextlvl = 100 + (100 * (this->poziom + 1));
	this->poziom++;
	this->pktum += 3;
	cout << "Zwi�kszono poziom bohatera " << this->poziom << "!" << endl;
}

string Bohater::getAsString() const{
	return nazwa + " " + to_string(poziom) + " "+ to_string(exp) + " "
	+ to_string(expnextlvl) + " " + to_string(hp) + " " + to_string(hpmax) + " "
	+ to_string(sila) + " " + to_string(zrecznosc) + " "+ to_string(magia) + " "
	+ to_string(szczescie) + " " + to_string(obrona) + " "+ to_string(pktum)
	+ " " + to_string(miasto) + " " + to_string(kasa) + " " + this->bron.toStringSave();
}

void Bohater::odczytnazwy() {
	ifstream PlikMiasto("Miasta.txt");
	string nazwa = "";
	int numermiasta = 0;
	string line = "";
	stringstream str;
	if (PlikMiasto.is_open()) {
		while (getline(PlikMiasto, line)) {
			str.str(line);
			str >> nazwa;
			str >> numermiasta; 
			if (miasto == numermiasta) {
				this->nazwamiasta = nazwa;
			}
			str.clear();
		}
	}
	PlikMiasto.close();
}

void Bohater::zlespanie() {
	if ((hp - 5) >= 0) 
		this->hp -= 5;
	else {
		system("cls");
		cout << "Tw�j bohater zgin��" << endl;
		Czekanie();
	}
}

void Bohater::GraczObrazenia(const int Obrazenia){
	this->hp -= Obrazenia;
	if (this->hp <= 0){
		this->hp = 0;
	}
}

void Bohater::DodawanieStatystyk(int stat, int pkt){
	if (this->pktum < pkt) {
		system("cls");
		cout << "Brak punkt�w umiej�tno�ci, nie mo�na doda� wi�cej statystyk" << endl;
		system("pause");
		system("cls");
	} else {
		switch (stat){
		case 0:
			this->sila += pkt;
			cout << "Ulepszono poziom si�y!" << endl;
			break;

		case 1:
			this->zrecznosc += pkt;
			cout << "Ulepszono poziom zr�czno�ci!" << endl;
			break;

		case 2:
			this->magia += pkt;
			cout << "Ulepszono poziom magii!" << endl;
			break;

		case 3:
			this->szczescie += pkt;
			cout << "Ulepszono poziom szcz�cia!" << endl;
			break;

		case 4:
			this->obrona += pkt;
			cout << "Ulepszono poziom obrony!" << endl;
			break;

		default:
			cout << "Nie ma takiej umiej�tno�ci" << endl;
			break;
		}
		this->pktum -= pkt;
	}
}

string Bohater::loadekwipunek(bool shop){
	string graczeq;
	for (size_t i = 0; i < this->ekwipunek.size(); i++){
		if (shop){
			graczeq += to_string(i) + ": " + this->ekwipunek[i].toString() + "\n" + " - Cena sprzeda�y: "
				+ std::to_string(this->ekwipunek[i].getSellValue()) + "\n";
		} else {
			graczeq += to_string(i) + ": " + this->ekwipunek[i].toString() + "\n";
		}
	}
	return graczeq;
}

string Bohater::saveekwipunek(){
	string graczeq;
	for (size_t i = 0; i < this->ekwipunek.size(); i++){
			graczeq += this->ekwipunek[i].toStringSave();
	}

	graczeq += "\n";

	return graczeq;
}

void Bohater::zalozprzedmiot(unsigned index){
	if (index < 0 || index >= this->ekwipunek.size()){
		cout << "No valid item selected!" << "\n\n";
	} else {
		Bronie *w = nullptr;
		w = dynamic_cast<Bronie*>(&this->ekwipunek[index]);

		if (w != nullptr){
			if (this->bron.getRarity() >= 0)
				this->ekwipunek.addItem(this->bron);
			this->bron = *w;
			this->ekwipunek.removeItem(index);
		} else {
			cout << "ERROR EQUIP ITEM, ITEM IS NOT ARMOR OR WEAPON!";
		}
	}
}

void Bohater::usunprzedmiot(const int index){
	if (index < 0 || index >= this->ekwipunek.size())
		cout << "ERROR, NOT POSSIBLE TO REMOVE ITEM, removeItem Character" << "\n\n";
	else{ this->ekwipunek.removeItem(index); }
}

const Przedmiot& Bohater::getItem(const int index){
	if (index < 0 || index >= this->ekwipunek.size()){
		cout << "ERROR, NOT POSSIBLE TO REMOVE ITEM, getItem Character" << "\n\n";
		throw("ERROR OUT OF BOUNDS, GETITEM CHARACTER");
	}

	return this->ekwipunek[index];
}

void Bohater::Czekanie() {
	cout << endl << "Czekanie na potwierdzenie..." << endl;
	cin.clear();
	cin.ignore();
	system("cls");
}

void Bohater::sklep(int nrbudynku){
	bool graczsklep = true;
	int wybor = 0;
	int kosci = 0;
	int wynik = 0;
	int stawka = 0;
	int losowosc = 0;
	int ilosc = rand() % 10 + 3;
	Ekwipunek sprzedawca;
	string graczeq;

	for (size_t i = 0; i < ilosc; i++){
		sprzedawca.addItem(Bronie(nrbudynku, graczpoziom() + rand() % 5, rand() % 4));
	}

	//Tawerna
	if (nrbudynku == 0) {
		while (graczsklep) {
			cout << ">>>>>" << budynki[nrbudynku] << " w " << nazwamiasta << " <<<<<<<" << endl << endl;
			cout << "0: Wyjd� ze sklepu" << endl << "1: Zagraj w ko�ci" << "2: Spr�buj co� ukra��" << 
				"3: Napij si� z poszukwiaczami przyg�d" << endl << endl << "Wyb�r: ";
			cin >> wybor;
			cin.ignore();
			while (cin.fail() || wybor > 3 || wybor < 0) {
				system("cls");
				cout << "B��dny zakres." << endl;
				cin.clear();
				cin.ignore();
				cout << ">>>>>" << budynki[nrbudynku] << " w " << nazwamiasta << " <<<<<<<" << endl << endl;
				cout << "0: Wyjd� ze sklepu" << endl << "1: Kup" << endl << endl << "Wyb�r: ";
				cin >> wybor;
			}
			switch (wybor) {
			case 0:
				graczsklep = false;
				break;

			case 1:
				if (graczkasa() == 0) {
					cout << "\n Nie mo�esz gra�, je�eli nie masz pieni�dzy!" << endl;
					break;
				}
				else {
					cout << "Podaj jak� kwot� grasz?" << endl << "Kwota: ";
					cin >> stawka;
					cin.ignore();
					while (cin.fail() || stawka > graczkasa() || stawka < 0) {
						system("cls");
						cout << "B��dny zakres." << endl;
						cin.clear();
						cin.ignore();
						cout << "Podaj jak� kwot� grasz?" << endl << "Kwota: ";
						cin >> stawka;
					}
					cout << "Przeciwnik rzuca ko�ciami" << endl;
					Czekanie();
					wynik = rand() % 12 + 1;
					cout << "Wylosowa�: " << wynik << endl;
					Czekanie();
					cout << "Rzucasz ko�ciami" << endl;
					Czekanie();
					kosci = rand() % 12 + 1;
					cout << "Wylosowa�e�/a�: " << kosci << endl;
					Czekanie();
					if (wynik == kosci) {
						cout << "Mieli�cie tyle samo oczek, nikt nie wygrywa!" << endl;
					}
					else {
						if (wynik > kosci) {
							cout << "Masz mniejszy wynik, przegrywasz." << endl;
							cout << "Tracisz ustawion� stawk�: " << stawka << endl;
							graczodekasa(stawka);
						} else {
							cout << "Masz wi�kszy wynik, wygrywasz!" << endl;
							cout << "Wygrywasz ustawion� stawk�" << stawka << endl;
							graczdodkasa(stawka);
						}
					}
				}
				break;

			case 2:
				Czekanie();
				cout << "Twoje szcz�cie wynosi: " << graczszczescie() << endl;
				Czekanie();
				cout << "Przechodzisz przez t�um" << endl;
				Czekanie();
				stawka = rand() % (graczpoziom() + 3 * graczszczescie() + graczzrecznosc() + 5) + 1;
				wynik = rand() % 100 + 1;
				kosci = rand() % 100 + (graczszczescie() + 1);
				if (wynik < kosci) {
					cout << "Ukrad�e�: " << stawka << endl;
					graczdodkasa(stawka);
				} else {
					cout << "Nie uda�o Ci si� nic znale��, \na przy tym kto� zauwa�y� twoje zamiary (-5hp)" << endl;
					zlespanie();
				}
				break;
			case 3:
				if (graczkasa() < 5) {
					cout << "Nie sta� Ci� na alkohol" << endl;
				} else {
					cout << "Pijesz wraz z poszukiwaczami przyg�d, mi�o z nimi przebywa czas" << endl;
					graczodekasa(5);
					wyspanie();
					GraczObrazenia(20);
				}
				break;

			default:
				cout << "Wychodzisz z tawerny" << endl;
				break;
			}
		}
	}

	//Gospoda
	if (nrbudynku == 1) {
		system("cls");
		cout << "Chcesz si� wyspa� w Gospodzie?\nKosztuje to 50 gold" << endl;
		cin >> wybor;
		cin.ignore();
		while (cin.fail() || wybor > 2 || wybor < 0) {
			system("cls");
			cout << "B��dny zakres." << endl;
			cin.clear();
			cin.ignore();
			cout << "Chcesz si� wyspa� w Gospodzie?" << endl;
			cin >> wybor;
		}
		if (graczkasa() < 50) {
			system("cls");
			cout << "Nie sta� Ci� na to!" << endl;
		} else {
			cout << "Wyspa�e� si� rze�ko i bez przeszk�d" << endl;
			cout << "Zap�aci�e� za pobyt 50 z�ota" << endl;
			wyspanie();
			graczodekasa(50);
		}
	}

	//Budynki sklepowe
	if (nrbudynku > 1 && nrbudynku<7) {
		while (graczsklep) {
			system("cls");
			cout << ">>>>>" << budynki[nrbudynku] << " w " << nazwamiasta << " <<<<<<<" << endl << endl;
			cout << "0: Wyjd� ze sklepu" << endl << "1: Kup" << endl << endl << "Wyb�r: ";
			cin >> wybor;
			cin.ignore();
			while (cin.fail() || wybor > 2 || wybor < 0) {
				system("cls");
				cout << "B��dny zakres." << endl;
				cin.clear();
				cin.ignore();
				cout << ">>>>>" << budynki[nrbudynku] << " w " << nazwamiasta << " <<<<<<<" << endl << endl;
				cout << "0: Wyjd� ze sklepu" << endl << "1: Kup" << endl << endl << "Wyb�r: ";
				cin >> wybor;
			}
			system("cls");
			switch (wybor) {
			case 0:
				graczsklep = false;
				break;

			case 1:
				cout << ">>>>> Kupujesz" << " w " << budynki[nrbudynku] << " <<<<<<<" << endl << endl;
				cout << " - Kasa: " << graczkasa() << "\n\n";
				graczeq.clear();

				for (size_t i = 0; i < sprzedawca.size(); i++) {
					graczeq += to_string(i) + ": " + sprzedawca[i].toString() + "\n - Cena: " + to_string(sprzedawca[i].getBuyValue()) + "\n";
				}

				cout << graczeq << "\n";

				cout << "Kasa: " << graczkasa() << "\n";
				cout << "Wybierz przedmiot (-1, aby anulowa�): ";

				cin >> wybor;

				while (cin.fail() || wybor > sprzedawca.size() || wybor < -1) {
					system("cls");

					cout << "B��dny zakres!" << "\n";
					cin.clear();
					cin.ignore();

					cout << "Kasa: " << graczkasa() << "\n";
					cout << "Wybierz przedmiot (-1, aby wyj��): ";
					cin >> wybor;
				}
				cin.ignore();

				if (wybor == -1) {
					cout << ">>>Cofaniecie<<<" << endl;
				}
				else if (graczkasa() >= sprzedawca[wybor].getBuyValue()) {
					graczodekasa(sprzedawca[wybor].getBuyValue());
					addItem(sprzedawca[wybor]);

					cout << "Kupi�e� przedmiot: " << sprzedawca[wybor].getName() << " -" << sprzedawca[wybor].getBuyValue() << "\n";

					sprzedawca.removeItem(wybor);
				}
				else {
					cout << "Nie sta� Ci� na to!" << endl;
				}

				break;
			default:
				break;
			}
		}
	}

	//Rynek
	if (nrbudynku == 7) {
		while (graczsklep) {
			system("cls");
			cout << ">>>>>" << budynki[nrbudynku] << " w " << nazwamiasta << " <<<<<<<" << endl << endl;
			cout << "0: Wyjd� ze sklepu" << endl << "1: Sprzedaj" << endl << endl << "Wyb�r: ";
			cin >> wybor;
			cin.ignore();
			while (cin.fail() || wybor > 2 || wybor < 0) {
				system("cls");
				cout << "B��dny zakres." << endl;
				cin.clear();
				cin.ignore();
				cout << ">>>>>" << budynki[nrbudynku] << " w " << nazwamiasta << " <<<<<<<" << endl << endl;
				cout << "0: Wyjd� ze sklepu" << endl << "1: Sprzedaj" << endl << endl << "Wyb�r: ";
				cin >> wybor;
			}

			switch (wybor) {
			case 0:
				graczsklep = false;
				break;

			case 1:
				cout << loadekwipunek(true) << endl;
				cout << ">>>>> Sprzedajesz" << " w " << budynki[nrbudynku] << " <<<<<<<" << endl << endl;
				cout << " - Kasa: " << graczkasa() << endl << endl;

				if (getInventorySize() > 0) {
					cout << "Kasa: " << graczkasa() << endl;
					cout << "wybor of item (-1 to cancel): ";
					cin >> wybor;

					while (cin.fail() || wybor > getInventorySize() || wybor < -1) {
						system("cls");

						cout << "B��dny zakres!" << endl;
						cin.clear();
						cin.ignore();

						cout << "Kasa: " << graczkasa() << "\n";
						cout << "Wybierz przedmiot (-1, aby anulowa�): ";
						cin >> wybor;
					}

					cin.ignore();
					cout << "\n";

					if (wybor == -1) {
						cout << ">>>Cofaniecie<<<" << endl;
					}
					else {
						graczdodkasa(getItem(wybor).getSellValue());

						cout << "Sprzedano przedmiot" << endl;
						cout << "Zarobiono: " << getItem(wybor).getSellValue() << "!" << endl << endl;
						usunprzedmiot(wybor);
					}
				}
				else {
					cout << "Pusty ekwipunek" << endl;
					Czekanie();
				}
				break;
			default:
				graczsklep = false;
				break;
			}
		}
	}

	//Pa�ac
	if (nrbudynku == 8) {
		wynik = 1;
		system("cls");
		stawka = rand() % 100 + (100 - graczszczescie());
		cout << "Czy chcesz kupi� losowy punkt umiej�tno�ci za " << stawka << "?" << endl;
		cin >> wybor;
		cin.ignore();
		while (cin.fail() || wybor > 2 || wybor < 0) {
			system("cls");
			cout << "B��dny zakres." << endl;
			cin.clear();
			cin.ignore();
			cout << "Czy chcesz kupi� losowy punkt umiej�tno�ci?" << endl;
			cin >> wybor;
		}
		cout << "Ile chcesz ich kupi�?" << endl;
		cin >> wynik;
		cin.ignore();
		while (cin.fail() || wynik < 0) {
			system("cls");
			cout << "B��dny zakres." << endl;
			cin.clear();
			cin.ignore();
			cout << "Ile chcesz ich kupi�?" << endl;
			cin >> wynik;
		}
		cout << "R�ne czy 1 losow�? (0 - R�ne, 1 - 1 Losowa)" << endl;
		cin >> losowosc;
		cin.ignore();
		while (cin.fail() || losowosc < 0 || losowosc > 2) {
			system("cls");
			cout << "B��dny zakres." << endl;
			cin.clear();
			cin.ignore();
			cout << "R�ne czy 1 losow�?" << endl;
			cin >> losowosc;
		}
		switch (wybor) {
		case 0:
			cout << "Wychodzisz z pa�aca" << endl;
			break;
		case 1:
			if (stawka*wynik > graczkasa()) {
				cout << "Nie sta� Ci� na to!" << endl;
			} else {
				cout << "Zap�aci�e�: " << stawka << " za " << wynik << " Punkt�w Umiej�tno�ci!" << endl << endl;
				if (losowosc == 1) {
					this->pktum += wynik;
					kosci = rand() % 4 + 1;
					DodawanieStatystyk(kosci, wynik);
				} else {
					this->pktum += wynik;
					while (wynik > 0) {
						kosci = rand() % 4 + 1;
						DodawanieStatystyk(kosci, 1);
						wynik--;
					}
				}
			}
			break;
		default:
			cout << "Wychodzisz z pa�aca" << endl;
			break;
		}
	}

	cout << "\n\nWychodzisz ze sklepu" << endl << endl;
	Czekanie();

}