#include "Gra.h"

Gra::Gra(){
	wybor = 0;
	playing = true;
	nazwakonta = "";
	plik = "";
	plikmiasto = "Miasta.txt";
	activeCharacter = 0;
	activemiasto = 1;
	activeMonster = 0;
	plikpotwor = "Potwor.txt";
}

Gra::~Gra(){
}

//G��wne funkcje gry
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
		cout << "Nie ma takiego konta, chcesz stworzy� nowe?" << endl;
		cin >> wyborotwarcia;
		if (wyborotwarcia != 0) {
			stworzKonto();
			this->InitGry();
		}
	}
	plik.close();
	this->loadMiasto();
	this->loadPotwor();
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
		cout << "Podaj sw�j wybor: \n" << endl;
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
			cout << "Poszed�e� na przygod�"<<endl;
			Podroz();
			break;
		case 4:
			cout << "Poszed�e� ubija� gobliny";
			DodPotwor();
			savePotwor();
			loadPotwor();
			break;
		case 5:
			cout << "Poszed�e� grabowa� najbli�sze miasto";
			savePotwor();
			break;
		case 6:
			Bohaterzy[activeCharacter].odpoczynek();
			break;
		case 7:
			//cout << "To Remek robi gr� RPG??" << endl << endl;
			//Bohaterzy[activeCharacter].zranienie();
			//poke();
			NoweMiasto();
			break;
		case 8:
			cout << "Odczytuje";
			loadBohater();
			break;
		case 9:
			cout << "Zapisuje";
			saveBohater();
			break;
		case 10:
			cout << "miasto: " << endl;
			//PPotwory[activeMonster].Wyswietl();
			break;
		case 11:
			cout << "miasto: " << endl;
			wybormiasta();
			break;
		case 12:
			cout << "zapisz miasto: " << endl;
			saveMiasto();
			break;
		default:
			break;
		}
	}
	else {
		cout << "Tw�j bohater zgin�� XD" << endl;
		this->stworzBohatera();
		this->saveBohater();
		this->loadBohater();
	}
}

void Gra::saveBohater(){
	ofstream PlikGry(plik);
	if (PlikGry.is_open()){
		for (size_t i = 0; i < this->Bohaterzy.size(); i++){
			PlikGry << this->Bohaterzy[i].getAsString() << "\n";
		}
	}
	PlikGry.close();
}

void Gra::saveMiasto() {
	ofstream PlikMiasto(plikmiasto);
	if (PlikMiasto.is_open()) {
		for (size_t i = 0; i < this->Miasta.size(); i++) {
			PlikMiasto << this->Miasta[i].getAsString() << endl;
		}
	}
	PlikMiasto.close();
}

void Gra::loadMiasto(){
	ifstream PlikMiasto(plikmiasto);
	this->Miasta.clear();

	string nazwa = "";
	int numermiasta = 0;
	int nrbudynku1 = 0;
	int nrbudynku2 = 0;
	int nrbudynku3 = 0;

	string line = "";
	stringstream str;

	if (PlikMiasto.is_open()){
		while (getline(PlikMiasto, line)){
			str.str(line);
			str >> nazwa;
			str >> numermiasta;
			str >> nrbudynku1;
			str >> nrbudynku2;
			str >> nrbudynku3;
			Miasto temp(numermiasta, nazwa, nrbudynku1, nrbudynku2, nrbudynku3);
			this->Miasta.push_back(Miasto(temp));
			cout << "Miast " << temp.getName() << " zaladowano!" << endl;
			str.clear();
		}
	}
	PlikMiasto.close();
	if (this->Miasta.size() <= 0){
		throw "Brak miast";
	}
}

void Gra::loadBohater() {
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
	int miasto = 0;
	int kasa = 0;

	string line = "";
	stringstream str;

	if (PlikGry.is_open()){
		while (getline(PlikGry, line)){
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
			str >> miasto;
			str >> kasa;

			Bohater temp(nazwa, poziom, exp, expnextlvl, hp, hpmax,
				sila, zrecznosc, magia, szczescie, obrona, pktum, miasto, kasa);

			this->Bohaterzy.push_back(Bohater(temp));
			cout << "Bohater " << temp.getName() << " zaladowano!" << endl;
		}
	}
	PlikGry.close();
	if (this->Bohaterzy.size() <= 0) {
		throw "Nie za�adowano bohatera";
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

void Gra::poke() {
cout << "##############@@@@@@@@########################===========#@@@@@@@@@@@@@@@@@@@@@" << endl;
cout << "#############@@@@@@@@@@#######################===========#@@@@@@@@@@@@@@@@@@@@@" << endl;
cout << "############@@@@@@@@@@@@#####################============#@@@@@@@@@@@@@@@@@@@@@" << endl;
cout << "############@@@@@@@@@@@@#####################=============@@@@@@@@@@@@@@@@@@@@@" << endl;
cout << "###########@@@@@@@@@@@@@@###################==============#@@@@@@@@@@@@@@@@@@@@" << endl;
cout << "##########@@@##=#@@@@@@@@##################==========###==#@@@@@@@@@@@@@@@@@@@@" << endl;
cout << "#########@@@@@@###==#@@@@##################========########@@@@@@@@@@@@@@@@@@@@" << endl;
cout << "#########@@@@@@@@=+:::+#@@##################################@@@@@@@@@@@@@@@=**=" << endl;
cout << "########@@@@@@@@#*+++:::::=#################################@@@@@@@@@@@=:-::::*" << endl;
cout << "#######@@@@@@@@@=***++++:::::=@@@#@#########################@@@@@@#+:--::::::++" << endl;
cout << "######@@@@@@@@@@#=****++++:::::+#@@@@@@@###@@@@@@@@@@@@@@###@#+:--::::::::++++*" << endl;
cout << "######@@@@@@@@@@@===****+++++::::*@@@@@@@@@@@@@@@@@@@@@@@#+--::::::::::+++++***" << endl;
cout << "#####@@@@@@@@@@@@@====*****+++++:::::::::::::::::::::::::::::::::::++++++*****#" << endl;
cout << "#####@@@@@@@@@@@@@@#=====*****++++::::::::::::::::::::::::::::+++++++*******=@@" << endl;
cout << "####@@@@@@@@@@@@@@@@@#=====***+++++:::::::::::::::::::::::::+++++*********#@@@@" << endl;
cout << "####@@@@@@@@@@@@@@@@@@@#===****++++++:::::::::::::::::::::::+++********=#@@@@@@" << endl;
cout << "######@@@@@@@@@@@@@@@@@@@==****++++++++++++++::::::::::::::::++****==#@@@@@@@@@" << endl;
cout << "######@@@@@@@@@@@@@@@@@@==*******++++++++++++++++++:::::::::::+++***+=@@@@@@@@@" << endl;
cout << "#####@@@@@@@@@@@@@@@@@@====****=###******++++++++++++*==##@=+++++++++:=@@@@@@@@" << endl;
cout << "#####@@@@@@@@@@@@@@@@@#=====*=@@@@@#*********+++++++*#@@@@@@#++++++++++#@@@@@@@" << endl;
cout << "####@@@@@@@@@@@@@@@@@@=======#@@@@@#***********+++++*@@@@@@@@*+++++++++*@@@@@@@" << endl;
cout << "####@@@@@@@@@@@@@@@@@========#@@@@=***********+**++++*#@###@=+++++++++++#@@@@@@" << endl;
cout << "###@@@@@@@@@@@@@@@@@###==========*******=@@@=+++++++++++*******+++++++**=@@@@@@" << endl;
cout << "###@@@@@@@@@@@@@@@@###=================**********************************#@@@@@" << endl;
cout << "##@@@@@@@@@@@@@@@@@######================******************=*************=#@@@@" << endl;
cout << "##@@@@@@@@@@@@@@@@@#######===============@@@@@@#====******========********#@@@@" << endl;
cout << "#@@@@@@@@@@@@@@@@@@#######==============@WWWWWW@#==================*******#@@@@" << endl;
cout << "#@@@@@@@@@@@@@@@@@@@##########==========#@@@@@@@#==================*******=@@@@" << endl;
cout << "@@@@@@@@@@@@@@@@@@@@@@==#################==#####==================********=@@@@" << endl;
cout << "@@@@@@@@@@@@@@@@@@@@@@@########################===================********=#@@@" << endl;
cout << "@@@@@@@@@@@@@@@@@@@@@#==#############################=======================@@@" << endl;
cout << "@@@@@@@@@@@@@@@@@@#=====###############################=====================#@@" << endl;
cout << "@@@@@@@@@@@@@@@@#=============#######################========================@@" << endl;
}

void Gra::NoweMiasto() {
	string nazwa = "";
	int max = 0;
	cout << "Nazwa miasta: ";
	getline(cin, nazwa);
	for (size_t i = 0; i < this->Miasta.size(); i++) {
		while (nazwa == this->Miasta[i].getName()) {
			cout << "Miasto o takiej nazwie istnieje!" << "\n";
			cout << "Nazwa name: ";
			getline(cin, nazwa);
		}
		if (max <= this->Miasta[i].gracznrmiasta()) {
			max = this->Miasta[i].gracznrmiasta();
		}
	}
	Miasta.push_back(Miasto());
	activemiasto = Miasta.size() - 1;
	Miasta[activemiasto].inicjalizacja(nazwa, max);
}

void Gra::wybormiasta(){
	cout << "Wyb�r miasta: " << endl << endl;
	for (size_t i = 0; i < this->Miasta.size(); i++){
		cout << "Index: " << i << " = " << this->Miasta[i].getName() << "\n";
	}
	cout << "\n";
	cout << "Choice: ";
	cin >> this->wybor;
	while (cin.fail() || this->wybor >= this->Miasta.size() || this->wybor < 0){
		cout << "Faulty input!" << "\n";
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Wyb�r miasta: " << "\n";
		cin >> this->wybor;
	}
	cin.ignore(100, '\n');
	cout << "\n";
	this->activemiasto = this->wybor;
	cout << this->Miasta[this->activemiasto].getName() << " is SELECTED!" << "\n\n";
}

void Gra::Podroz() {
	Event ev;
	ev.LosEvent(this->Bohaterzy[activeCharacter], this->PPotwory[activeMonster]);
}

void Gra::DodPotwor() {
	string nazwa = "";
	int max = 0, poziomp = 0;
	cout << "Nazwa potwora: ";
	getline(cin, nazwa);
	for (size_t i = 0; i < this->PPotwory.size(); i++) {
		while (nazwa == this->PPotwory[i].getName()) {
			cout << "Potwor o takiej nazwie istnieje!" << "\n";
			cout << "Podaj nazwe potwora: ";
			getline(cin, nazwa);
		}
		if (max <= this->PPotwory[i].nrpotwora()) {
			max = this->PPotwory[i].nrpotwora();
		}
	}
	cout << "Podaj poziom potwora" << endl;
	cin >> poziomp;
	cin.clear();
	cin.ignore();
	PPotwory.push_back(Potwory());
	activeMonster = PPotwory.size() - 1;
	PPotwory[activeMonster].inicjalizacja(nazwa, max, poziomp);
}

void Gra::savePotwor() {
	ofstream PlikPotwor(plikpotwor);
	if (PlikPotwor.is_open()) {
		for (size_t i = 0; i < this->PPotwory.size(); i++) {
			PlikPotwor << this->PPotwory[i].GetAsString() << endl;
		}
	}
	PlikPotwor.close();
}

void Gra::loadPotwor() {
	ifstream PlikPotwor(plikpotwor);
	this->PPotwory.clear();

	string nazwa = "";
	int numerpotwora = 0;
	int poziom = 0;
	int hp = 0;
	int maxhp = 0;
	int mindmg = 0;
	int maxdmg = 0;
	int kasa = 0;
	int obrona = 0;
	int szansa = 0;

	string line = "";
	stringstream str;

	if (PlikPotwor.is_open()) {
		while (getline(PlikPotwor, line)) {
			str.str(line);
			str >> nazwa;
			str >> numerpotwora;
			str >> poziom;
			str >> hp;
			str >> maxhp;
			str >> mindmg;
			str >> maxdmg;
			str >> kasa;
			str >> obrona;
			str >> szansa;

			Potwory temp(nazwa, numerpotwora, poziom, hp, maxhp, mindmg, maxdmg, kasa, obrona, szansa);
			this->PPotwory.push_back(Potwory(temp));
			cout << "Potw�r " << temp.getName() << " zaladowano!" << endl;
			str.clear();
		}
	}
	PlikPotwor.close();
	if (this->PPotwory.size() <= 0) {
		throw "Brak potwor�w!";
	}
}