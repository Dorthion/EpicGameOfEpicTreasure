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
	bud1 = 0;
	bud2 = 0;
	bud3 = 0;
	ukryj = 0;
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
		system("cls");
		cout << "Nie ma takiego konta, chcesz stworzyæ nowe?" << endl;
		cout << "1 - tak, 0 - nie" << endl;
		cin >> wyborotwarcia;
		if (wyborotwarcia != 0) {
			stworzKonto();
			this->InitGry();
		} else { exit(999); }
	}
	plik.close();
	this->loadMiasto();
	this->bud1 = Miasta[this->activemiasto].bud1();
	this->bud2 = Miasta[this->activemiasto].bud2();
	this->bud3 = Miasta[this->activemiasto].bud3();
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
	} else {
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
		//cout << this->plik << endl;
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
	//Do cheatu
	
	if (this->Bohaterzy[activeCharacter].graczgra()) {
		if (this->Bohaterzy[activeCharacter].graczpktum() >= 1){
			cout << "Posiadasz nie wykorzystane punkty!"<<endl<<endl;
		}
		if (this->Bohaterzy[activeCharacter].graczexp() >=
			this->Bohaterzy[activeCharacter].graczexpnextlvl()){
			this->Bohaterzy[activeCharacter].lvlup();
		}
		if (this->ukryj == 1) {
			Czekanie2();
			this->ukryj = 0;
		}
			
		kolor.gold();	
		cout << "\t>>>>>MENU<<<<<<" << endl;
		cout << "Podaj swój wybor: \n" << endl;
		cout << "1 - Statystyki postaci" << endl;
		cout << "2 - Dodawanie statystyk" << endl;
		cout << "3 - Wyœwietlenie miasta" << endl;
		cout << "4 - Wybór budynku" << endl;
		cout << "5 - Zmiana miasta" << endl;
		cout << "6 - Odpoczynek na dworze" << endl;
		cout << "7 - Odpoczynek w mieœcie" << endl;
		cout << "8 - Podró¿ w poszukiwaniu przygód" << endl;
		cout << "9 - Poka¿ ekwipunek" << endl;
		cout << "10 - Zmieñ przedmiot" << endl;
		cout << "11 - Œwiêta Krucjata" << endl;
		cout << "12 - Boss ostateczny" << endl;

		cout << "\n-1 - Zapisz" << endl;
		cout << "-2 - Wczytaj" << endl;
		cout << "\n0 - Wyjscie" << endl;

		cout << endl << "Jaki jest twoj wybor??: ";

		cin >> this->wybor;
		cin.clear();
		cin.ignore();

		switch (this->wybor) {
		case 1:
			Bohaterzy[activeCharacter].Wyswietl();
			break;
		case 2:
			DodawanieStat();
			break;
		
		case 4:
			cout << "Poszed³eœ ubijaæ gobliny";
			DodPotwor();
			savePotwor();
			loadPotwor();
			break;
		case 5:
			cout << "Poszed³eœ grabowaæ najbli¿sze miasto";
			savePotwor();
			break;
		case 6:
			Bohaterzy[activeCharacter].odpoczynek();
			break;
		case 7:
			//cout << "To Remek robi grê RPG??" << endl << endl;
			//Bohaterzy[activeCharacter].zranienie();
			//poke();
			NoweMiasto();
			break;

		case 8:
			Podroz();
			loadPotwor();
			break;
		
		case 9:
			system("cls");
			cout << this->Bohaterzy[this->activeCharacter].loadekwipunek();
			Czekanie();
			break;

		case 10:
			system("cls");
			cout << this->Bohaterzy[this->activeCharacter].loadekwipunek();

			cout << "Item index: ";
			cin >> this->wybor;

			while (cin.fail() || this->wybor < 0 || this->wybor >= this->Bohaterzy[this->activeCharacter].getInventorySize() ){
				cout << "B³êdny wybór!" << "\n";
				cin.clear();
				cin.ignore();
				cout << "Item index: ";
				cin >> this->wybor;
			}
			cin.ignore();

			this->Bohaterzy[this->activeCharacter].zalozprzedmiot(this->wybor);
			system("cls");
			break;

		case 11:
			cout << "miasto: " << endl;
			wybormiasta();
			break;
		case 12:
			cout << "zapisz miasto: " << endl;
			saveMiasto();
			break;

		case 13:
			cout << "Wybierz budynek: " << endl;
			cin >> wybor;
			switch (wybor) {
			case 1:
				wybor = this->bud1 - 1;
				break;
			case 2:
				wybor = this->bud2 - 1;
				break;
			case 3:
				wybor = this->bud3 - 1;
				break;
			}
			Bohaterzy[activeCharacter].sklep(wybor);
			break;

		case 14:
			cout << "BUDYNKI: " << endl;
			cout << bud1 << "\t" << bud2 << "\t" << bud3 << "\t" << endl;
			break;

		case 1000:
			if (ukryj == 0) ukryj = 1;
			else ukryj = 0;
			break;

		case -1:
			system("cls");
			cout << "=====Zapisuje====="<<endl;
			saveBohater();
			loadBohater();
			break;

		case -2:
			system("cls");
			cout << "======Wczytano bohatera======";
			loadBohater();
			break;

		case 0:
			playing = false;
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

void Gra::saveBohater(){
	ofstream PlikGry(plik);
	if (PlikGry.is_open()){
		for (size_t i = 0; i < this->Bohaterzy.size(); i++){
			PlikGry << this->Bohaterzy[i].getAsString() << "\n";
			PlikGry << this->Bohaterzy[i].saveekwipunek() << "\n";
		}
	}
	Bohaterzy.clear();
	this->Bohaterzy.clear();		//Nie potrzebne??
	
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

	int numermiasta = 0;
	int nrbudynku1 = 0;
	int nrbudynku2 = 0;
	int nrbudynku3 = 0;

	string nazwa = "";
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
			str.clear();
		}
	}
	if (this->Miasta.size() <= 0){
		string blad = "Brak miast do wczytania";
		cout << "Brak miast do wczytania!" << endl;
		PlikBledu(blad, 2);
		system("pause");
		exit(2);
	}
	PlikMiasto.close();
}

void Gra::loadBohater() {
	ifstream PlikGry(plik);
	Bohaterzy.clear();
	this->Bohaterzy.clear();		//Nie potrzebne??
	
	//Bohater
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

	//Bron
	int minsila = 0;
	int maxsila = 0;
	int minzre = 0;
	int maxzre = 0;
	int minmagia = 0;
	int maxmagia = 0;
	int minszcz = 0;
	int maxszcz = 0;
	int minobr = 0;
	int maxobr = 0;
	int lvl = 0;
	int rzadkosc = 0;
	int cenagora = 0;
	int cenadol = 0;

	string nazwa = "";
	string nazwa2 = "";
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

			str >> nazwa2 >> lvl >> rzadkosc >> cenagora >> cenadol 
				>> minsila >> maxsila >> minzre >> maxzre >> minmagia
				>> maxmagia >> minszcz >> maxszcz >> minobr >> maxobr;

			Bronie bron(minsila, maxsila, minzre, maxzre,
				minmagia, maxmagia, minszcz, maxszcz, minobr, maxobr,
				nazwa2, lvl, cenagora, cenadol, rzadkosc);
			temp.setWeapon(bron);

			str.clear();
			line.clear();
			getline(PlikGry, line);
			str.str(line);

			while (str >> nazwa2 >> lvl >> rzadkosc >> cenagora >> cenadol
				>> minsila >> maxsila >> minzre >> maxzre >> minmagia
				>> maxmagia >> minszcz >> maxszcz >> minobr >> maxobr){
				temp.addItem( Bronie(minsila, maxsila, minzre, maxzre,
					minmagia, maxmagia, minszcz, maxszcz, minobr, maxobr,
					nazwa2, lvl, cenagora, cenadol, rzadkosc));
			}

			str.clear();
			line.clear();
			getline(PlikGry, line);
			str.str(line);

			this->Bohaterzy.push_back(Bohater(temp));
		}
	}
	if (this->Bohaterzy.size() <= 0) {
		string blad = "Brak bohaterów do wczytania";
		cout << "Brak bohaterów do odczytania!" << endl;
		PlikBledu(blad, 1);
		system("pause");
		exit(1);
	}
	PlikGry.close();
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
	cout << "Wybór miasta: " << endl << endl;
	for (size_t i = 0; i < this->Miasta.size(); i++){
		cout << "Index: " << i << " = " << this->Miasta[i].getName() << endl;
	}
	cout << "\n";
	cout << "Wybor: ";
	cin >> this->wybor;
	while (cin.fail() || this->wybor >= this->Miasta.size() || this->wybor < 0){
		cout << "B³êdny zakres" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Wybór miasta: " << "\n";
		cin >> this->wybor;
	}
	cin.ignore();
	cout << "\n";
	this->activemiasto = this->wybor;
	//£adowanie budynków

	this->bud1 = Miasta[this->wybor].bud1();
	this->bud2 = Miasta[this->wybor].bud2();
	this->bud3 = Miasta[this->wybor].bud3();

	cout << this->Miasta[this->activemiasto].getName() << " wybrano!" << "\n\n";
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

	int numerpotwora = 0;
	int poziom = 0;
	int hp = 0;
	int maxhp = 0;
	int mindmg = 0;
	int maxdmg = 0;
	int kasa = 0;
	int obrona = 0;
	int szansa = 0;

	string nazwa = "";
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
			str.clear();
		}
	}
	if (this->PPotwory.size() <= 0) {
		string blad = "Brak potworów do wczytania";
		cout<<"Brak potworów!"<<endl;
		PlikBledu(blad, 3);
		system("pause");
		exit(3);
	}
	PlikPotwor.close();
}

void Gra::PlikBledu(string nazwa, int kod) {
	fstream plik;
	plik.open("KodBledu.txt", ios::app);
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	plik << "Kod bledu: " << kod << endl <<
		"Prawdopodobnie wywolany przez: " << nazwa << endl <<
		"Data: " << asctime(timeinfo) << endl << endl;
}

void Gra::DodawanieStat() {
	if (this->Bohaterzy[activeCharacter].graczpktum() > 0){
		system("cls");
		cout << "Statystyki, które mo¿esz ulepszyæ za darmo: " << endl;
		cout << "0: Si³a " << endl;
		cout << "1: Zrêcznoœæ " << endl;
		cout << "2: Magia " << endl;
		cout << "3: Szczêœcie " << endl;
		cout << "4: obrona " << endl;
		cin >> this->wybor;

		while (cin.fail() || this->wybor > 4){
			cout << "Wpisz poprawn¹ cyfrê z zakresu 0 - 4!" << endl;
			cin.clear();
			cin.ignore();
			cout << "Statystyki, które mo¿esz ulepszyæ za darmo : " << endl;
			cin >> this->wybor;
		}
		cin.ignore();

		switch (this->wybor){
		case 0:
			this->Bohaterzy[activeCharacter].DodawanieStatystyk(0, 1);
			break;

		case 1:
			this->Bohaterzy[activeCharacter].DodawanieStatystyk(1, 1);
			break;

		case 2:
			this->Bohaterzy[activeCharacter].DodawanieStatystyk(2, 1);
			break;

		case 3:
			this->Bohaterzy[activeCharacter].DodawanieStatystyk(3, 1);
			break;

		case 4:
			this->Bohaterzy[activeCharacter].DodawanieStatystyk(4, 1);
			break;

		default:

			break;
		}
	} else {
		system("cls");
		cout << "Brak punktów umiejêtnoœci, nie mo¿na dodaæ wiêcej statystyk" << endl;
		system("pause");
		system("cls");
	}
}

void Gra::Czekanie() {
	cout << endl << "Czekanie na potwierdzenie..." << endl;
	cin.clear();
	cin.ignore();
	system("cls");
}

void Gra::Czekanie2() {
	char key;
	int asc;
	cout << endl << "Czekanie na potwierdzenie..." << endl;
	key = getch();
	asc = key;
	if (asc == 122) cheatengine();
	system("cls");
}

void Gra::cheatengine() {
	bool cheat = true;
	int wybieram = 0;
	system("cls");
	while (cheat == true) {
		system("cls");
		cout << "Co chcesz dodaæ?" << endl;
		cout << "1 - Si³a, 2 - Zrêcznoœæ, 3 - Magia, 4 - Szczêœcie, 5 - Obrona" << endl;
		cout << "6 - Hp, 7 - HpMax, 8 - Exp, 9 - Kasa, 10 - Pkt Um" << endl;
		cin >> wybieram;
		cin.clear();
		cin.ignore();
		while (cin.fail() || wybieram >= 11 || wybieram < -1) {
			cout << "B³êdny zakres" << endl;
			cout << "Wybor cheatu: " << endl;
			cin >> wybieram;
			cin.ignore();
		}
		switch (wybieram) {
		case 0:
			cheat = false;
			break;
		case 1:
			this->Bohaterzy[activeCharacter].cheat1();
			break;
		case 2:
			this->Bohaterzy[activeCharacter].cheat2();
			break;
		case 3:
			this->Bohaterzy[activeCharacter].cheat3();
			break;
		case 4:
			this->Bohaterzy[activeCharacter].cheat4();
			break;
		case 5:
			this->Bohaterzy[activeCharacter].cheat5();
			break;
		case 6:
			this->Bohaterzy[activeCharacter].cheat6();
			break;
		case 7:
			this->Bohaterzy[activeCharacter].cheat7();
			break;
		case 8:
			this->Bohaterzy[activeCharacter].cheat8();
			break;
		case 9:
			this->Bohaterzy[activeCharacter].cheat9();
			break;
		case 10:
			this->Bohaterzy[activeCharacter].cheat10();
			break;
		default:
			cheat = false;
			break;
		}
	}
}