#include "Gra.h"

Gra::Gra(){
	wybor = 0;
	playing = true;
	nazwakonta = "";
	plik = "";
	activeCharacter = 0;
}

Gra::~Gra(){
}

//G³ówne funkcje gry
void Gra::InitGry() {
	int wyborotwarcia = 0;
	int logowanie = 0;
	string nazwagracza = "";
	string haslogracza = "";
	string nazwagracza2 = "";
	string haslogracza2 = ""; 
	ifstream plik;
	ifstream pliklogowanie;
	cout << "Login: " << endl;
	cin >> nazwagracza;
	cout << "Haslo: " << endl;
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
	cin >> haslogracza;
	cin.clear();
	cin.ignore();
	SetConsoleMode(hStdin, mode);
	//tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	pliklogowanie.open("Logowanie.txt");
	while (!pliklogowanie.eof()) {
		pliklogowanie >> nazwagracza2 >> haslogracza2;
		if ((nazwagracza == nazwagracza2) && (haslogracza == haslogracza2)){
			logowanie = 1;
			break;
		}
	}
	if (logowanie == 1) {
		this->nazwakonta = nazwagracza;
		this->plik = nazwagracza + ".txt";
		plik.open(nazwagracza + ".txt");
		this->loadBohater();
	}
	else {
		cout << "Nie ma takiego konta, chcesz stworzyæ nowe?" << endl;
		cin >> wyborotwarcia;
		if (wyborotwarcia != 0) {
			stworzKonto();
			this->InitGry();
		}
	}
	plik.close();
}

//Tworzenie Konta
void Gra::stworzKonto() {
	fstream plik;
	fstream plikhasla;
	string nazwaKonta = "";
	string hasloKonta = "";
	cout << "Nowy login: " << endl;
	cin >> nazwaKonta;
	//cout << nazwaKonta;
	plik.open(nazwaKonta + ".txt");
	if (plik.is_open()) {
		cout << "Konto juz istnieje o takiej nazwie! (Ponowne logowanie)" << endl;
	}
	else {
		plik.close();
		//cout << "Nowe konto zostanie stworzone" << endl;
		plik.open(nazwaKonta + ".txt", ios::out);
		plikhasla.open("logowanie.txt", ios::app);
		cout << "Podaj haslo do konta: " << endl;
		cin >> hasloKonta;
		cin.clear();
		cin.ignore();
		plikhasla << endl << nazwaKonta << " " << hasloKonta;
		this->nazwakonta = nazwaKonta;
		this->plik = nazwaKonta + ".txt";
		cout << this->plik << endl;
		stworzBohatera();
		this->saveBohater();
		//DWORD attributes = GetFileAttributes(nazwaKonta);
		//SetFileAttributes("MyFile.txt", attributes + FILE_ATTRIBUTE_HIDDEN);
	}
	plik.close();
}

void Gra::Menu(){
	Kolory kolor;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (this->Bohaterzy[activeCharacter].graczgra()) {
		if (this->Bohaterzy[activeCharacter].graczpktum() >= 1){
			cout << "Posiadasz nie wykorzystane punkty!"<<endl<<endl;
		}
		if (this->Bohaterzy[activeCharacter].graczexp() >=
			this->Bohaterzy[activeCharacter].graczexpnextlvl()){
			this->Bohaterzy[activeCharacter].lvlup();
		}
		kolor.gold();
		cout << "\t>>>>>MENU<<<<<<" << endl;
		cout << "Podaj swój wybor: \n" << endl;
		cout << "1 - Postac" << endl;
		cout << "2 - Miasto" << endl;
		cout << "3 - Podroz" << endl;
		cout << "4 - Dungeon" << endl;
		cout << "5 - Krucjata" << endl;
		cout << "6 - Odpoczynek" << endl;
		cout << "7 - Stworz" << endl;
		cout << "8 - Wczytaj" << endl;
		cout << "9 - Zapisz" << endl;
		cout << "\n0 - Wyjscie" << endl;

		cout << endl << "Jaki jest twoj wybor??: ";

		cin >> this->wybor;
		cin.clear();
		cin.ignore();

		switch (this->wybor) {
		case 0:
			playing = false;
			break;
		case 1:
			Bohaterzy[activeCharacter].Wyswietl();
			break;
		case 2:
			cout << "Wchodzisz na tereny Podlasia";
			break;
		case 3:
			cout << "Poszed³eœ na przygodê";
			break;
		case 4:
			cout << "Poszed³eœ ubijaæ gobliny";
			break;
		case 5:
			cout << "Poszed³eœ grabowaæ najbli¿sze miasto";
			break;
		case 6:
			Bohaterzy[activeCharacter].odpoczynek();
			break;
		case 7:
			cout << "Zraniono" << endl;
			Bohaterzy[activeCharacter].zranienie();
			break;
		case 8:
			cout << "Odczytuje";
			loadBohater();
			break;
		case 9:
			cout << "Zapisuje";
			saveBohater();
			break;
		default:
			break;
		}
	}
	else {
		cout << "Twój bohater zgin¹³ XD" << endl;
		this->stworzBohatera();
		this->saveBohater();
		this->loadBohater();
	}
}

void Gra::saveBohater()
{
	ofstream PlikGry(plik);

	if (PlikGry.is_open())
	{
		for (size_t i = 0; i < this->Bohaterzy.size(); i++)
		{
			PlikGry << this->Bohaterzy[i].getAsString() << "\n";
			//PlikGry << this->Bohaterzy[i].getInvAsStringSave() << "\n";
		}
	}

	PlikGry.close();
}

void Gra::loadBohater(){
	ifstream PlikGry(plik);

	this->Bohaterzy.clear();

	string nazwa = "";
	int poziom = 0;
	int exp = 0;
	int expnextlvl = 0;
	int hp = 0;
	int hpmax = 0;
	int sila = 0;
	int zrecznosc = 0;
	int magia = 0;
	int szczescie = 0;
	int obrona = 0;
	int pktum = 0;

	string line = "";
	stringstream str;

	if (PlikGry.is_open())
	{
		while (getline(PlikGry, line))
		{
			str.str(line);
			str >> nazwa;
			str >> poziom;
			str >> exp;
			str >> expnextlvl;
			str >> hp;
			str >> hpmax;
			str >> sila;
			str >> zrecznosc;
			str >> magia;
			str >> szczescie;
			str >> obrona;
			str >> pktum;

			Bohater temp(nazwa, poziom, exp, expnextlvl, hp, hpmax,
				sila, zrecznosc, magia, szczescie,
				obrona, pktum);

			this->Bohaterzy.push_back(Bohater(temp));
			cout << "Bohater " << temp.getName() << " zaladowano!" << endl;
		}
	}
	PlikGry.close();
	if (this->Bohaterzy.size() <= 0){
		throw "Nie za³adowano bohatera";
	}
}

void Gra::stworzBohatera(){
	string nazwa = "";
	cout << "Nazwa bohatera: ";
	getline(cin, nazwa);

	for (size_t i = 0; i < this->Bohaterzy.size(); i++){
		while (nazwa == this->Bohaterzy[i].getName()){
			cout << "Bohater juz istnieje!" << endl;
			cout << "Nazwa bohatera: ";
			getline(cin, nazwa);
		}
	}

	Bohaterzy.push_back(Bohater());
	activeCharacter = Bohaterzy.size() - 1;
	Bohaterzy[activeCharacter].inicjalizacja(nazwa);
}


