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

Bohater::Bohater(string nazwa, int poziom, int exp, int expnextlvl, int hp, int hpmax, int sila, //Pocz¹tkowe statystyki
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
	//G³ówne elementy postaci
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

void Bohater::Wyswietl() {
	Kolory kolor;
	system("cls");
	odczytnazwy();
	kolor.gold(); cout << " ===============================================" << endl;
	kolor.blue(); cout << "//"; kolor.red(); cout<< "\t\tStatystyki Bohatera: "; kolor.blue(); cout <<"\t\t\\\\" << endl;
	kolor.blue(); cout << "||\t\t\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tNazwa: "; kolor.green(); cout<< this->nazwa; kolor.blue(); 
	if (this->nazwa.length()<9) cout << "\t\t\t\t||" << endl;
	if (this->nazwa.length() >= 9 && this->nazwa.length() < 17) cout << "\t\t\t||" << endl;
	if (this->nazwa.length() >= 17 && this->nazwa.length() < 25) cout << "\t\t||" << endl;
	if (this->nazwa.length() >= 25 && this->nazwa.length() < 33) cout << "\t||" << endl;
	if (this->nazwa.length() >= 33) cout << "||" << endl;
	kolor.blue(); cout << "||\tPoziom: "; kolor.green(); cout << this->poziom; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tExp: "; kolor.green(); cout << this->exp; kolor.blue(); cout << "\t\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tExp do kolejnego poziomu: "; kolor.green(); cout << this->expnextlvl; kolor.blue(); cout << "\t\t||" << endl;
	kolor.blue(); cout << "||\tPunkty umiejêtnoœci: "; kolor.green(); cout << this->pktum; kolor.blue(); cout << "\t\t\t||" << endl;
	kolor.blue(); cout << "||\t\t\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tSi³a: "; kolor.green(); cout << this->sila << "/+" << this->bron.bronsilamax(); kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tZrêcznoœæ: "; kolor.green(); cout << this->zrecznosc << "/+" << this->bron.bronzremax(); kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tMagia: "; kolor.green(); cout << this->magia << "/+" << this->bron.bronmagiamax(); kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tSzczêœcie: "; kolor.green(); cout << this->szczescie << "/+" << this->bron.bronszczmax(); kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tObrona: "; kolor.green(); cout << this->obrona << "/+" << this->bron.bronobrmax(); kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\t\t\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tHp: "; kolor.green(); cout << this->hp << " / " << this->hpmax; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\tMiasto: "; kolor.green(); cout << this->nazwamiasta; kolor.blue(); 
	if (this->nazwamiasta.length()<8) cout << "\t\t\t\t||" << endl;
	if (this->nazwamiasta.length() >= 8 && this->nazwamiasta.length() < 16) cout << "\t\t\t||" << endl;
	if (this->nazwamiasta.length() >= 16 && this->nazwamiasta.length() < 24) cout << "\t\t||" << endl;
	if (this->nazwamiasta.length() >= 24 && this->nazwamiasta.length() < 32) cout << "\t||" << endl;
	if (this->nazwamiasta.length() >= 32) cout << "||" << endl;
	kolor.blue(); cout << "||\tKasa: "; kolor.green(); cout << this->kasa; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "\\\\\t" << "\t\t\t\t\t//" << endl;
	kolor.gold(); cout << " ===============================================" << endl;
}

void Bohater::lvlup(){
	this->exp = 0;
	this->expnextlvl = 100 + (100 * (this->poziom + 1));
	this->sila += 1;
	this->zrecznosc += 1;
	this->magia += 1;
	this->szczescie += 1;
	this->obrona += 1;
	this->poziom++;
	this->pktum += 3;
	cout << "Zwiêkszono poziom bohatera " << this->poziom << "!" << endl;
}

string Bohater::getString() const{
	return nazwa + " " + to_string(poziom) + " "+ to_string(exp) + " "
	+ to_string(expnextlvl) + " " + to_string(hp) + " " + to_string(hpmax) + " "
	+ to_string(sila) + " " + to_string(zrecznosc) + " "+ to_string(magia) + " "
	+ to_string(szczescie) + " " + to_string(obrona) + " "+ to_string(pktum)
	+ " " + to_string(miasto) + " " + to_string(kasa) + " " + this->bron.saveString();
}

void Bohater::odczytnazwy() {
	int numermiasta = 0;
	ifstream PlikMiasto("./PlikiGry/Miasta.txt");
	string nazwa = "";
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
		cout << "\n\nTwój bohater zgin¹³" << endl;
		Czekanie();
		exit(0);
	}
}

void Bohater::GraczObrazenia(const int Obrazenia){
	this->hp -= Obrazenia;
	if (this->hp <= 0){
		this->hp = 0;
		cout << "\n\nTwój bohater zgin¹³" << endl;
		Czekanie();
		exit(0);
	}
}

void Bohater::DodawanieStatystyk(int stat, int pkt){
	if (this->pktum < pkt) {
		system("cls");
		cout << "Brak punktów umiejêtnoœci, nie mo¿na dodaæ wiêcej statystyk" << endl;
		system("pause");
		system("cls");
	} else {
		switch (stat){
		case 0:
			this->sila += pkt;
			cout << "Ulepszono poziom si³y!" << endl;
			break;

		case 1:
			this->zrecznosc += pkt;
			cout << "Ulepszono poziom zrêcznoœci!" << endl;
			break;

		case 2:
			this->magia += pkt;
			cout << "Ulepszono poziom magii!" << endl;
			break;

		case 3:
			this->szczescie += pkt;
			cout << "Ulepszono poziom szczêœcia!" << endl;
			break;

		case 4:
			this->obrona += pkt;
			cout << "Ulepszono poziom obrony!" << endl;
			break;

		default:
			cout << "Nie ma takiej umiejêtnoœci" << endl;
			break;
		}
		this->pktum -= pkt;
	}
}

string Bohater::loadekwipunek(bool ladowanie){
	string graczeq;
	for (int i = 0; i < (int)this->ekwipunek.IloscEkw(); i++){
		if (ladowanie){
			graczeq += to_string(i) + ": " + this->ekwipunek[i].toString() + "\n" + " - Cena sprzeda¿y: "
				+ to_string(this->ekwipunek[i].przedmiotCenas()) + "\n";
		} else {
			graczeq += to_string(i) + ": " + this->ekwipunek[i].toString() + "\n";
		}
	}
	return graczeq;
}

string Bohater::saveekwipunek(){
	string graczeq;
	for (int i = 0; i < (int)this->ekwipunek.IloscEkw(); i++){
			graczeq += this->ekwipunek[i].saveString();
	}

	graczeq += "\n";

	return graczeq;
}

void Bohater::zalozprzedmiot(unsigned numer){
	if (numer < 0 || numer >= (unsigned)this->ekwipunek.IloscEkw()){
		cout << "Wybrano nie poprawny przedmiot z zakresu" << endl << endl;
	} else {
		Bronie *w = nullptr;
		w = dynamic_cast<Bronie*>(&this->ekwipunek[numer]);

		if (w != nullptr){
			if (this->bron.przedmiotRzadkosc() >= 0)
				this->ekwipunek.Dodprzedmiot(this->bron);
			this->bron = *w;
			this->ekwipunek.Usunprzedmiot(numer);
		}
		else { cout << "B³¹d z broni¹" << endl; }
	}
}

void Bohater::usunprzedmiot(const int numer){
	if (numer < 0 || numer >= this->ekwipunek.IloscEkw())
		cout << "Nie mo¿na usun¹æ przedmiotu! B³êdny zakres." << endl;
	else{ this->ekwipunek.Usunprzedmiot(numer); }
}

const Przedmiot& Bohater::wybranyprzedmiot(const int numer){
	if (numer < 0 || numer >= this->ekwipunek.IloscEkw()){
		cout << "Nie mo¿na za³o¿yæ przedmiotu!" << endl;
	}
	return this->ekwipunek[numer];
}

void Bohater::Czekanie() {
	Kolory kolor;
	kolor.green();
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
	int koszt = rand() % 50 + 10;
	int fart = 0;
	Ekwipunek sprzedawca;
	string graczeq;
	Kolory kolor;

	if (graczszczescie() > 100) {
		fart = 100;
	}
	else {
		fart = graczszczescie();
	}

	for (int i = 0; i < (int)ilosc; i++){
		sprzedawca.Dodprzedmiot(Bronie(nrbudynku, graczpoziom() + rand() % 5, rand() % 4));
	}

	//Tawerna
	if (nrbudynku == 0) {
		while (graczsklep) {
			system("cls");
			kolor.red(); cout << ">>>>>";
			kolor.gold(); cout << budynki[nrbudynku];
			kolor.red(); cout << " w ";
			kolor.gold(); cout << nazwamiasta;
			kolor.red(); cout << "<<<<<<<" << endl << endl;

			kolor.blue();  cout << "0:";
			kolor.green(); cout << " WyjdŸ ze sklepu" << endl;
			kolor.blue(); cout << "1:";
			kolor.green(); cout << " Zagraj w koœci" << endl;
			kolor.blue(); cout << "2:";
			kolor.green(); cout << " Spróbuj coœ ukraœæ";
			kolor.blue(); cout << "3:";
			kolor.green(); cout << " Napij siê z poszukwiaczami przygód" << endl << endl;
			kolor.gold(); cout << "Wybór: ";
			cin >> wybor;
			cin.ignore();

			while (cin.fail() || wybor > 3 || wybor < 0) {
				system("cls");
				kolor.red(); cout << "B³êdny zakres." << endl;
				cin.clear();
				cin.ignore();
				kolor.red(); cout << ">>>>>";
				kolor.gold(); cout << budynki[nrbudynku];
				kolor.red(); cout << " w ";
				kolor.gold(); cout << nazwamiasta;
				kolor.red(); cout << "<<<<<<<" << endl << endl;

				kolor.blue();  cout << "0:";
				kolor.green(); cout << " WyjdŸ ze sklepu" << endl;
				kolor.blue(); cout << "1:";
				kolor.green(); cout << " Zagraj w koœci" << endl;
				kolor.blue(); cout << "2:";
				kolor.green(); cout << " Spróbuj coœ ukraœæ\n" << endl; //Nie mam pojêcia dlaczego nie dzia³a poprawnie, bug visuala studio??
				kolor.blue(); cout << "\n3:";
				kolor.green(); cout << " Napij siê z poszukwiaczami przygód" << endl << endl;
				kolor.gold(); cout << "Wybór: ";
				cin >> wybor;
			}
			switch (wybor) {
			case 0:
				graczsklep = false;
				break;

			case 1:
				if (graczkasa() == 0) {
					kolor.red();
					system("cls");
					cout << "\n Nie mo¿esz graæ, je¿eli nie masz pieniêdzy!" << endl;
					break;
				}
				else {
					system("cls");
					kolor.gold(); cout << "Podaj jak¹ kwot¹ grasz?" << endl;
					kolor.blue(); cout << "Kwota: ";
					kolor.gold(); cin >> stawka;
					while (cin.fail() || stawka > graczkasa() || stawka < 0) {
						system("cls");
						kolor.red(); cout << "B³êdny zakres." << endl;
						cin.clear();
						cin.ignore();
						kolor.gold(); cout << "Podaj jak¹ kwot¹ grasz?" << endl;
						kolor.blue(); cout << "Kwota: ";
						kolor.gold(); cin >> stawka;
					}
					cin.clear();
					cin.ignore();
					system("cls");
					kolor.blue(); cout << "||==============================================||"<<endl;
					cout << "||\t\t\t\t\t\t||"<<endl;
					cout << "||\t"; kolor.gold(); cout << "Przeciwnik rzuca koœciami\t\t"; kolor.blue(); cout << "||" << endl;
					cout << "||\t\t\t\t\t\t||"<<endl;
					cout << "||==============================================||" << endl << endl;
					Czekanie();
					wynik = rand() % 12 + 1;
					kolor.blue(); cout << "||==============================||" << endl;
					cout << "||"; kolor.gold(); cout << "Przeciwnik wylosowa³: ";
					kolor.gold(); cout << wynik; kolor.blue(); cout << "\t||" << endl;
					cout << "||==============================||" << endl << endl;
					Czekanie();
					kolor.blue(); cout << "||==============================================||" << endl;
					cout << "||\t\t\t\t\t\t||" << endl;
					cout << "||\t"; kolor.gold(); cout << "Przeciwnik rzuca koœciami\t\t"; kolor.blue(); cout << "||" << endl;
					cout << "||\t\t\t\t\t\t||" << endl;
					cout << "||==============================================||" << endl << endl;
					Czekanie();
					kosci = rand() % 12 + 1;
					kolor.blue(); cout << "||======================||" << endl;
					cout << "||"; kolor.gold(); cout << "Wylosowa³eœ/aœ: ";
					kolor.gold(); cout << kosci; kolor.blue(); cout << "\t||" << endl;
					cout << "||======================||" << endl << endl;
					Czekanie();
					if (wynik == kosci) {
						system("cls");
						kolor.gold(); cout << "Mieliœcie tyle samo oczek, nikt nie wygrywa!" << endl << endl;
						Czekanie();
					}
					else {
						if (wynik > kosci) {
							system("cls");
							kolor.red(); cout << "Masz mniejszy wynik, przegrywasz." << endl << endl;
							kolor.blue(); cout << "Tracisz ustawion¹ stawkê: ";
							kolor.green(); cout << stawka << endl;
							graczodekasa(stawka);
							Czekanie();
						} else {
							system("cls");
							kolor.green(); cout << "Masz wiêkszy wynik, wygrywasz!" << endl << endl;
							kolor.blue(); cout << "Wygrywasz ustawion¹ stawkê: ";
							kolor.green(); cout << stawka << endl;
							graczdodkasa(stawka);
							Czekanie();
						}
					}
				}
				break;

			case 2:
				Czekanie();
				kolor.blue(); cout << "Twoje szczêœcie wynosi: ";
				kolor.green(); cout << graczszczescie() << endl;
				Czekanie();
				kolor.blue(); cout << "Przechodzisz przez t³um" << endl;
				Czekanie();
				stawka = rand() % (graczpoziom() + 3 * graczszczescie() + graczzrecznosc() + 5) + 1;
				wynik = rand() % 100 + 1;
				kosci = rand() % 100 + (graczszczescie() + 1);
				if (wynik < kosci) {
					kolor.blue(); cout << "Ukrad³eœ: ";
					kolor.gold(); cout << stawka << endl << endl;
					graczdodkasa(stawka);
					Czekanie();
				} else {
					kolor.red();
					cout << "Nie uda³o Ci siê nic znaleŸæ, \na przy tym ktoœ zauwa¿y³ twoje zamiary (-5hp)" << endl;
					zlespanie();
					Czekanie();
				}
				break;
			case 3:
				if (graczkasa() < koszt) {
					kolor.red();
					cout << "Nie staæ Ciê na alkohol!" << endl;
				} else {
					kolor.silver();
					cout << "Pijesz wraz z poszukiwaczami przygód, mi³o z nimi przebywa czas" << endl << endl;
					kolor.blue(); cout << "Zap³aci³eœ/aœ: "; kolor.green(); cout << koszt << endl << endl;
					graczodekasa(koszt);
					wyspanie();
					GraczObrazenia(20);
					Czekanie();
				}
				break;

			default:
				kolor.silver();
				cout << "Wychodzisz z tawerny" << endl;
				break;
			}
		}
	}

	//Gospoda
	if (nrbudynku == 1) {
		system("cls");
		kolor.gold(); cout << "Chcesz siê wyspaæ w Gospodzie?" << endl;
		kolor.blue(); cout << "Kosztuje to ";
		kolor.gold(); cout << "50";
		kolor.blue(); cout << " z³otych monet" << endl;
		cin >> wybor;
		cin.ignore();
		while (cin.fail() || wybor > 2 || wybor < 0) {
			system("cls");
			kolor.red();
			cout << "B³êdny zakres." << endl;
			cin.clear();
			cin.ignore();
			kolor.gold(); cout << "Chcesz siê wyspaæ w Gospodzie?" << endl;
			kolor.blue(); cout << "Kosztuje to ";
			kolor.gold(); cout << "50";
			kolor.blue(); cout << " z³otych monet" << endl;
			cin >> wybor;
		}
		cin.ignore();
		if (graczkasa() < 50) {
			system("cls");
			kolor.red();
			cout << "Nie staæ Ciê na to!" << endl;
			Czekanie();
		} else {
			if (wybor == 1) {
				system("cls");
				kolor.silver(); cout << "Wyspa³eœ siê rzeœko i bez przeszkód" << endl << endl;
				kolor.blue(); cout << "Zap³aci³eœ za pobyt ";
				kolor.gold(); cout << "50";
				kolor.blue(); cout << " z³otych monet" << endl;
				wyspanie();
				graczodekasa(50);
				Czekanie();
			}
		}
	}

	//Budynki sklepowe
	if (nrbudynku > 1 && nrbudynku<7) {
		while (graczsklep) {
			system("cls");
			kolor.red(); cout << ">>>>>";
			kolor.gold(); cout << budynki[nrbudynku];
			kolor.red(); cout << " w ";
			kolor.gold(); cout << nazwamiasta;
			kolor.red(); cout << "<<<<<<<" << endl << endl;

			kolor.blue();  cout << "0:";
			kolor.green(); cout << " WyjdŸ ze sklepu" << endl;
			kolor.blue(); cout << "1:";
			kolor.green(); cout << " Kup" << endl << endl;
			kolor.gold(); cout << "Wybór: ";
			cin >> wybor;
			cin.ignore();

			while (cin.fail() || wybor > 2 || wybor < 0) {
				system("cls");
				cout << "B³êdny zakres." << endl;
				cin.clear();
				cin.ignore();
				kolor.red(); cout << ">>>>>";
				kolor.gold(); cout << budynki[nrbudynku];
				kolor.red(); cout << " w ";
				kolor.gold(); cout << nazwamiasta;
				kolor.red(); cout << "<<<<<<<" << endl << endl;
				kolor.blue();  cout << "0:";
				kolor.green(); cout << " WyjdŸ ze sklepu" << endl;
				kolor.blue(); cout << "1:";
				kolor.green(); cout << " Kup" << endl << endl;
				kolor.gold(); cout << "Wybór: ";
				cin >> wybor;
			}
			cin.ignore();
			system("cls");
			switch (wybor) {
			case 0:
				graczsklep = false;
				break;

			case 1:
				kolor.red(); cout << ">>>>>";
				kolor.gold(); cout << " Kupujesz ";
				kolor.red(); cout << " w ";
				kolor.gold(); cout << budynki[nrbudynku];
				kolor.red(); cout << " <<<<<<<" << endl << endl;
				kolor.blue(); cout << "Kasa: ";
				kolor.gold(); cout << graczkasa() << endl << endl;

				kolor.silver();
				graczeq.clear();

				for (int i = 0; i < (int)sprzedawca.IloscEkw(); i++) {
					graczeq += to_string(i) + ": " + sprzedawca[i].toString() + "\n - Cena: " + to_string(sprzedawca[i].przedmiotCenak()) + "\n";
				}

				cout << graczeq << endl;

				kolor.blue(); cout << "Kasa: ";
				kolor.gold(); cout << graczkasa() << endl;
				kolor.blue(); cout << "Wybierz przedmiot (-1, aby anulowaæ): ";

				cin >> wybor;

				while (cin.fail() || wybor > sprzedawca.IloscEkw() || wybor < -1) {
					system("cls");
					kolor.red();
					cout << "B³êdny zakres!" << "\n";
					cin.clear();
					cin.ignore();

					kolor.blue(); cout << "Kasa: ";
					kolor.gold(); cout << graczkasa() << endl;
					kolor.blue(); cout << "Wybierz przedmiot (-1, aby anulowaæ): ";
					cin >> wybor;
				}
				cin.ignore();

				if (wybor == -1) {
					kolor.gold(); cout << ">>>Cofniêcie<<<" << endl;
					Czekanie();
				}
				else if (graczkasa() >= sprzedawca[wybor].przedmiotCenak()) {
					graczodekasa(sprzedawca[wybor].przedmiotCenak());
					Dodprzedmiot(sprzedawca[wybor]);
					kolor.blue();
					cout << "Kupi³eœ przedmiot: ";
					kolor.gold(); cout << sprzedawca[wybor].przedmiotNazwa();
					kolor.blue(); cout << " - ";
					kolor.gold(); cout << sprzedawca[wybor].przedmiotCenak() << endl;

					sprzedawca.Usunprzedmiot(wybor);
					Czekanie();
				}
				else {
					kolor.red();
					cout << "Nie staæ Ciê na to!" << endl;
					Czekanie();
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
			kolor.red(); cout << ">>>>>";
			kolor.gold(); cout << budynki[nrbudynku];
			kolor.red(); cout << " w ";
			kolor.gold(); cout << nazwamiasta;
			kolor.red(); cout << "<<<<<<<" << endl << endl;

			kolor.blue();  cout << "0:";
			kolor.green(); cout << " WyjdŸ ze sklepu" << endl;
			kolor.blue(); cout << "1:";
			kolor.green(); cout << " Sprzedaj" << endl << endl;
			kolor.gold(); cout << "Wybór: ";
			cin >> wybor;
			cin.ignore();
			while (cin.fail() || wybor > 2 || wybor < 0) {
				system("cls");
				cout << "B³êdny zakres." << endl;
				cin.clear();
				cin.ignore();
				kolor.blue();  cout << "0:";
				kolor.green(); cout << " WyjdŸ ze sklepu" << endl;
				kolor.blue(); cout << "1:";
				kolor.green(); cout << " Sprzedaj" << endl << endl;
				kolor.gold(); cout << "Wybór: ";
				cin >> wybor;
				cin.ignore();
			}

			switch (wybor) {
			case 0:
				graczsklep = false;
				break;

			case 1:
				kolor.red(); cout << ">>>>>";
				kolor.gold(); cout << " Sprzedajesz ";
				kolor.red(); cout << " w ";
				kolor.gold(); cout << budynki[nrbudynku];
				kolor.red(); cout << " <<<<<<<" << endl << endl;
				system("cls");
				kolor.gold();
				cout << loadekwipunek(true) << endl;
				//kolor.blue(); cout << "Kasa: ";
				//kolor.gold(); cout << graczkasa() << endl << endl;

				if (graczekwipunek() > 0) {
					kolor.blue(); cout << "Kasa: ";
					kolor.gold(); cout << graczkasa() << endl << endl;
					kolor.blue(); cout << "Wybierz przedmiot (-1, aby anulowaæ): ";
					cin >> wybor;

					while (cin.fail() || wybor > graczekwipunek() || wybor < -1) {
						system("cls");
						kolor.red();
						cout << "B³êdny zakres!" << endl;
						cin.clear();
						cin.ignore();

						kolor.blue(); cout << "Kasa: ";
						kolor.gold(); cout << graczkasa() << endl << endl;
						kolor.blue(); cout << "Wybierz przedmiot (-1, aby anulowaæ): ";
						cin >> wybor;
					}

					cin.ignore();
					cout << "\n";

					if (wybor == -1) {
						system("cls");
						kolor.gold(); cout << ">>>Cofniêcie<<<" << endl << endl;
						Czekanie();
					}
					else {
						graczdodkasa(wybranyprzedmiot(wybor).przedmiotCenas());

						kolor.silver(); cout << "Sprzedano przedmiot" << endl << endl;
						kolor.blue(); cout << "Zarobiono: ";
						kolor.gold(); cout << wybranyprzedmiot(wybor).przedmiotCenas();
						kolor.blue(); cout << "!" << endl << endl;
						usunprzedmiot(wybor);
						Czekanie();
					}
				}
				else {
					kolor.blue();
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

	//Pa³ac
	if (nrbudynku == 8) {
		wynik = 1;
		system("cls");
		stawka = rand() % 100 + (100 - fart);
		kolor.blue(); cout << "Czy chcesz kupiæ losowy punkt umiejêtnoœci za " << endl;
		kolor.gold(); cout << stawka;
		kolor.blue(); cout << "?" << endl;

		kolor.green();
		cin >> wybor;
		cin.ignore();
		while (cin.fail() || wybor > 2 || wybor < 0) {
			system("cls");
			kolor.red();
			cout << "B³êdny zakres." << endl;
			cin.clear();
			cin.ignore();
			kolor.blue(); cout << "Czy chcesz kupiæ losowy punkt umiejêtnoœci za " << endl;
			kolor.gold(); cout << stawka;
			kolor.blue(); cout << "?" << endl << endl;
			kolor.green();
			cin >> wybor;
		}
		cin.ignore();
		system("cls");
		kolor.blue(); cout << "Ile chcesz ich kupiæ?" << endl;
		kolor.green(); cin >> wynik;
		cin.ignore();

		while (cin.fail() || wynik < 0) {
			system("cls");
			cout << "B³êdny zakres." << endl;
			cin.clear();
			cin.ignore();
			kolor.blue();  cout << "Ile chcesz ich kupiæ?" << endl;
			kolor.green(); cin >> wynik;
		}
		kolor.blue(); cout << "Ró¿ne czy 1 losow¹?";
		kolor.gold(); cout << " (0 - Ró¿ne, 1 - 1 Losowa)" << endl;
		kolor.green(); cin >> losowosc;
		cin.ignore();
		while (cin.fail() || losowosc < 0 || losowosc > 2) {
			system("cls");
			kolor.red(); cout << "B³êdny zakres." << endl;
			cin.clear();
			cin.ignore();
			cout << "Ró¿ne czy 1 losow¹?" << endl;
			cin >> losowosc;
		}
		switch (wybor) {
		case 0:
			kolor.silver();
			cout << "Wychodzisz z pa³aca" << endl << endl;
			Czekanie();
			break;
		case 1:
			if (stawka*wynik > graczkasa()) {
				kolor.red();
				cout << "Nie staæ Ciê na to!" << endl;
				Czekanie();
			} else {
				kolor.blue(); cout << "Zap³aci³eœ: ";
				kolor.green(); cout << stawka;
				kolor.blue(); cout << " za ";
				kolor.green(); cout << wynik;
				kolor.blue(); cout << " Punktów Umiejêtnoœci!" << endl << endl;

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
			kolor.silver();
			cout << "Wychodzisz z pa³aca" << endl;
			break;
		}
	}
	kolor.silver();
	cout << "\n\nWychodzisz ze sklepu" << endl << endl;
	Czekanie();

}