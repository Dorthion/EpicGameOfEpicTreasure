#include "Gra.h"

Gra::Gra(){
	wybor = 0;
	playing = true;
	nazwakonta = "";
	plik = "";
	plikmiasto = "Miasta.txt";
	AktywnyBohater = 0;
	AktywneMiasto = 1;
	AktywnyPotwor = 0;
	plikpotwor = "Potwor.txt";
	bud1 = 0;
	bud2 = 0;
	bud3 = 0;
	ukryj = 0;
}

Gra::~Gra(){
}

void Gra::InitGry() {
	SetConsoleTitle("EpicGameOfEpicTreasure");
	int wyborotwarcia = 0;
	int logowanie = 0;
	string nazwagracza = "";
	string haslogracza = "";
	string nazwagracza2 = "";
	string haslogracza2 = ""; 
	ifstream plik;
	ifstream pliklogowanie;
	PanelAdministratorski root;
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
	pliklogowanie.open("Logowanie.txt");
	if (!pliklogowanie.is_open()) {
		root.Menu();
	}
	while (!pliklogowanie.eof()) {
		pliklogowanie >> nazwagracza2 >> haslogracza2;
		if ((nazwagracza == nazwagracza2) && (haslogracza == haslogracza2)){
			logowanie = 1;
			break;
		}
	}
	if (logowanie == 1) {
		if (this->nazwakonta == "root") {
			root.Menu();
			exit(0);
		} else {
			this->nazwakonta = nazwagracza;
			this->plik = nazwagracza + ".txt";
			plik.open(nazwagracza + ".txt");
			this->loadBohater();
		}
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
	this->bud1 = Miasta[this->AktywneMiasto].bud1();
	this->bud2 = Miasta[this->AktywneMiasto].bud2();
	this->bud3 = Miasta[this->AktywneMiasto].bud3();
	this->loadPotwor();
	system("cls");
}

void Gra::stworzKonto() {
	fstream plik;
	fstream plikhasla;
	string nazwaKonta = "";
	string hasloKonta = "";
	cout << "Nowy login: " << endl;
	cin >> nazwaKonta;
	cin.ignore();
	plik.open(nazwaKonta + ".txt");
	if (plik.is_open()) {
		cout << "Konto juz istnieje o takiej nazwie! (Ponowne logowanie)" << endl;
	} else {
		plik.close();
		plik.open(nazwaKonta + ".txt", ios::out);
		plikhasla.open("logowanie.txt", ios::app);
		//Atrybut do chowania plików
		//string temp = nazwaKonta + ".txt";
		//string x = "attrib +H " + temp; // + chowa, -odkrywa
		//system(x.c_str());
		cout << "Podaj haslo do konta: " << endl;
		cin >> hasloKonta;
		cin.clear();
		cin.ignore();
		plikhasla << endl << nazwaKonta << " " << hasloKonta;
		this->nazwakonta = nazwaKonta;
		this->plik = nazwaKonta + ".txt";
		stworzBohatera();
		this->saveBohater();
	}
	plik.close();
}

void Gra::Menu(){
	Kolory kolor;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if (this->Bohaterzy[AktywnyBohater].graczgra()) {
		if (this->Bohaterzy[AktywnyBohater].graczpktum() >= 1){
			cout << "Posiadasz nie wykorzystane punkty!"<<endl<<endl;
		}
		if (this->Bohaterzy[AktywnyBohater].graczexp() >=
			this->Bohaterzy[AktywnyBohater].graczexpnextlvl()){
			this->Bohaterzy[AktywnyBohater].lvlup();
		}
		if (this->ukryj == 1) {
			Czekanie2();
			this->ukryj = 0;
		}
			
		kolor.gold();	
		cout << "\t>>>>>MENU<<<<<<" << endl << endl;

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
			Bohaterzy[AktywnyBohater].Wyswietl();
			break;
		case 2:
			DodawanieStat();
			break;

		case 3:
			Miasta[AktywneMiasto].Wyswietl();
			break;
		
		case 4:
			SklepWejscie();
			break;
		case 5:
			wybormiasta();
			break;
		case 6:
			odpoczynek();
			break;

		case 7:
			if (bud1 == 2 || bud2 == 2 || bud3 == 2) Bohaterzy[AktywnyBohater].sklep(1);
			else cout << "Nie jesteœ w mieœcie, gdzie jest Gospoda!" << endl << endl;
			break;

		case 8:
			Podroz();
			loadPotwor();
			break;
		
		case 9:
			system("cls");
			cout << this->Bohaterzy[this->AktywnyBohater].loadekwipunek();
			Czekanie();
			break;

		case 10:
			system("cls");
			cout << this->Bohaterzy[this->AktywnyBohater].loadekwipunek();

			cout << "Item index: ";
			cin >> this->wybor;

			while (cin.fail() || this->wybor < 0 || this->wybor >= this->Bohaterzy[this->AktywnyBohater].getInventorySize() ){
				cout << "B³êdny wybór!" << "\n";
				cin.clear();
				cin.ignore();
				cout << "Item index: ";
				cin >> this->wybor;
			}
			cin.ignore();

			this->Bohaterzy[this->AktywnyBohater].zalozprzedmiot(this->wybor);
			system("cls");
			break;

		case 11:
			system("cls");
			if (Bohaterzy[AktywnyBohater].graczpoziom() > 20) PreKruci();
			else cout << "Nie wystarczaj¹cy iloœæ poziomów! \nWymagany jest minimalny 20 poziom, aby z nim walczyæ!" << endl << endl;
			break;
			
		case 12:
			system("cls");
			if (Bohaterzy[AktywnyBohater].graczpoziom() > 50) PreBoss(); 
			else cout << "Nie wystarczaj¹cy iloœæ poziomów! \nWymagany jest minimalny 50 poziom, aby z nim walczyæ!" << endl << endl;
			break;

		case 1000:
			if (ukryj == 0) ukryj = 1;
			else ukryj = 0;
			break;

		case -1:
			system("cls");
			cout << ">>>>> Zapisuje <<<<<"<<endl;
			saveBohater();
			loadBohater();
			break;

		case -2:
			system("cls");
			cout << ">>>>> Wczytano bohatera <<<<<" << endl;
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
		cout << "Twój bohater zgin¹³" << endl;
		this->stworzBohatera();
		this->saveBohater();
		this->loadBohater();
	}
}

void Gra::odpoczynek() {
	Event spanie;
	spanie.LosMalyEventSpanie(this->Bohaterzy[AktywnyBohater]);
}

void Gra::stworzBohatera() {
	string nazwa = "";
	cout << "Nazwa bohatera: ";
	getline(cin, nazwa);

	for (size_t i = 0; i < this->Bohaterzy.size(); i++) {
		while (nazwa == this->Bohaterzy[i].getName()) {
			cout << "Bohater juz istnieje!" << endl;
			cout << "Nazwa bohatera: ";
			getline(cin, nazwa);
		}
	}

	Bohaterzy.push_back(Bohater());
	AktywnyBohater = Bohaterzy.size() - 1;
	Bohaterzy[AktywnyBohater].inicjalizacja(nazwa);
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

	if (PlikGry.is_open()) {
		while (getline(PlikGry, line)) {
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
				>> maxmagia >> minszcz >> maxszcz >> minobr >> maxobr) {
				temp.addItem(Bronie(minsila, maxsila, minzre, maxzre,
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
		cout << "Brak potworów!" << endl;
		PlikBledu(blad, 3);
		system("pause");
		exit(3);
	}
	PlikPotwor.close();
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
		cin.ignore();
		cout << "Wybór miasta: " << "\n";
		cin >> this->wybor;
	}
	cin.ignore();
	this->AktywneMiasto = this->wybor;
	//£adowanie budynków
	this->bud1 = Miasta[this->wybor].bud1();
	this->bud2 = Miasta[this->wybor].bud2();
	this->bud3 = Miasta[this->wybor].bud3();

	cout << this->Miasta[this->AktywneMiasto].getName() << " wybrano!" << "\n\n";
}

void Gra::Podroz() {
	Event ev;
	ev.LosEvent(this->Bohaterzy[AktywnyBohater], this->PPotwory[AktywnyPotwor]);
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
	if (this->Bohaterzy[AktywnyBohater].graczpktum() > 0){
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
			this->Bohaterzy[AktywnyBohater].DodawanieStatystyk(0, 1);
			break;

		case 1:
			this->Bohaterzy[AktywnyBohater].DodawanieStatystyk(1, 1);
			break;

		case 2:
			this->Bohaterzy[AktywnyBohater].DodawanieStatystyk(2, 1);
			break;

		case 3:
			this->Bohaterzy[AktywnyBohater].DodawanieStatystyk(3, 1);
			break;

		case 4:
			this->Bohaterzy[AktywnyBohater].DodawanieStatystyk(4, 1);
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
		cout << "6 - Hp, 7 - HpMax, 8 - Exp, 9 - Kasa, 10 - Pkt Um, 11 - DodPoz" << endl;
		cin >> wybieram;
		cin.clear();
		cin.ignore();
		while (cin.fail() || wybieram >= 12 || wybieram < -1) {
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
			this->Bohaterzy[AktywnyBohater].cheat1();
			break;
		case 2:
			this->Bohaterzy[AktywnyBohater].cheat2();
			break;
		case 3:
			this->Bohaterzy[AktywnyBohater].cheat3();
			break;
		case 4:
			this->Bohaterzy[AktywnyBohater].cheat4();
			break;
		case 5:
			this->Bohaterzy[AktywnyBohater].cheat5();
			break;
		case 6:
			this->Bohaterzy[AktywnyBohater].cheat6();
			break;
		case 7:
			this->Bohaterzy[AktywnyBohater].cheat7();
			break;
		case 8:
			this->Bohaterzy[AktywnyBohater].cheat8();
			break;
		case 9:
			this->Bohaterzy[AktywnyBohater].cheat9();
			break;
		case 10:
			this->Bohaterzy[AktywnyBohater].cheat10();
			break;
		case 11:
			this->Bohaterzy[AktywnyBohater].cheat11();
			break;
		default:
			cheat = false;
			break;
		}
	}
}

void Gra::Kruci() {
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW**WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#+........+#WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWW#+-..................-+#WWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWW@#*+:..................................-:+*=#@WWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWW:......................:*#@WWWWWWWWWWWWWWWW#*:......................WWWWW" << endl;
	cout << "WWWWWW+..................=WWWWWWWWWWWWWWWWWWWWWWWWWWWWW+..................WWWWW" << endl;
	cout << "WWWWWW+.................-WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW@.................-WWWWW" << endl;
	cout << "WWWWWW*......=@=*+++*-..=WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW+..-**++*=@@.....:WWWWW" << endl;
	cout << "WWWWWW#......=WWWWWW@..-WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW@...@WWWWWW@.....+WWWWW" << endl;
	cout << "WWWWWW@......=WW+......=WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW+......-WW#.....=WWWWW" << endl;
	cout << "WWWWWWW-.....*WW+.....-WWW@**WWWWWWWWWWWWWWWWWWWWWWW**WWW#......:WW#.....@WWWWW" << endl;
	cout << "WWWWWWW+.....+WW=.....=WWW*.....*WWWWWWWWWWWWWWWW*....#WWW:.....+WW=....-WWWWWW" << endl;
	cout << "WWWWWWW#.....:WW#.....WWWW-.......*WWWWWWWWWWW*.......:WWW#.....*WW+....+WWWWWW" << endl;
	cout << "WWWWWWWW-.....WWW....*WWW=..........*WWWWWWW*..........@WWW:....#WW:....#WWWWWW" << endl;
	cout << "WWWWWWWW*.....#WW:...WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#....WW@....-WWWWWWW" << endl;
	cout << "WWWWWWWW@.....+WW=..*WWWWWWWWWWWWWWWWWW=.=WWWWWWWWWWWWWWWWWW:..+WW=....*WWWWWWW" << endl;
	cout << "WWWWWWWWW+.....WWW..#@@@@@@@@@WWWWWWWW-...-WWWWWWWW@@@@@@@@@*..#WW:....WWWWWWWW" << endl;
	cout << "WWWWWWWWW@.....=WW+..........*WWWWWW=...+...@WWWWWW:..........-WW@....*WWWWWWWW" << endl;
	cout << "WWWWWWWWWW+....-WW@..........@WWWWWW*.:WWW--#WWWWWW*..........=WW+....WWWWWWWWW" << endl;
	cout << "WWWWWWWWWWW.....=WW+.........WWWWWWWWWWWWWWWWWWWWWW=.........-WW@....=WWWWWWWWW" << endl;
	cout << "WWWWWWWWWWW#....-WWW.........WWWWWWWWWWWWWWWWWWWWWW*.........#WW+...:WWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWW+....+WW#........=WWW=-WWWWW-WWWWW.=WWW:........+WW#....@WWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWW:....=WW*.......-WWW..+WWW-.-WWW-.-WWW........-WWW....#WWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWW-....@WW+.......+W:...=W:...=W+...+W-........@WW:...*WWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWW@.....@WW:.............+.....+.....-........@WW+...*WWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWW@.....@WW+...............................-@WW+...*WWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWW-....@WW=....*W.....-.....-....-W:....:WWW:...*WWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWW:....=WW*..*WW+...=W....:W=...#WW:..*WW@....#WWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWW*....:W:..@WW@..=WW=...@WW:.:WWW@..+W*...-WWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWW@-......-WWWW+=WWWW:.=WWWW-@WWWW-......=WWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWW=.....-WWWWWWWWWW@:WWWWWWWWWWW-....:WWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWW*....-=WWWWWWWWWWWWWWWWWWW=....:@WWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWW=......*@WWWWWWWWWWW#+.....+WWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWW@:.........---........-#WWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW@+..............:#WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW@*-....-*@WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
}

void Gra::PreKruci() {
	system("cls");
	cout << "Przychodzisz zwyk³y cz³owieku na krucjate... " << endl << endl;
	Czekanie();
	cout << "Przychodzisz po z³oto?..." << endl;
	Czekanie();
	cout << "Mo¿e przychodzisz, aby zabiæ?... " << endl;
	Czekanie();
	cout << "ZnajdŸ swoje œwiat³o w sercu...\n\nNa pewno je odnajdziesz..." << endl;
	Czekanie();
	cout << "A teraz... PO¯EGNAJ SIÊ ZE ŒWIATEM\n\n...WITAJ W MOIM KRÓLESTWIE!" << endl;
	Czekanie();
	Kruci();
	cout << "Czy chcesz walczyæ przeciwko z³owieszczej, hordziej, kruciacie?" << endl;
	cin >> this->wybor;
	cin.ignore();
	while (cin.fail() || wybor > 2 || wybor < 0) {
		system("cls");
		cout << "B³êdny zakres." << endl;
		Kruci();
		cin.clear();
		cin.ignore();
		cout << "Czy chcesz walczyæ przeciwko z³owieszczej, hordziej, kruciacie?" << endl;
		cin >> this->wybor;
	}

	if (this->wybor == 1) {
		this->plikpotwor = "kruci.txt";
		loadPotwor();
		Boss();
		this->plikpotwor = "Potwor.txt";
		loadPotwor();
		system("cls");
	}
	else {
		cout << "Stchórzy³eœ!" << endl;
		return;
	}
}

void Gra::PreBoss() {
	cout << "Boss Ostateczny: " << endl << endl;
	poke();
	cout << "Czy chcesz walczyæ przeciwko bossowi ostatecznemu?" << endl;
	cin >> this->wybor;
	cin.ignore();
	while (cin.fail() || wybor > 2 || wybor < 0) {
		system("cls");
		cout << "B³êdny zakres." << endl;
		poke();
		cin.clear();
		cin.ignore();
		cout << "Czy chcesz walczyæ przeciwko bossowi ostatecznemu?" << endl;
		cin >> this->wybor;
	}

	if (this->wybor == 1) {
		this->plikpotwor = "boss.txt";
		loadPotwor();
		Boss();
		this->plikpotwor = "Potwor.txt";
		loadPotwor();
		system("cls");
		cout << "Brawo! Pokona³eœ ostatecznego Bossa!" << endl;
	}
	else {
		cout << "Stchórzy³eœ!" << endl;
	}
}

void Gra::Boss() {
	Event walkaboss;
	walkaboss.Walka(this->Bohaterzy[AktywnyBohater], this->PPotwory[AktywnyPotwor]);
}

void Gra::SklepWejscie() {
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
	default:
		break;
	}
	Bohaterzy[AktywnyBohater].sklep(wybor);
}