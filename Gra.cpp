#include "Gra.h"

Gra::Gra(){
	wybor = 0; //Og�lny wyb�r gracza z menu
	playing = true; //Czy zacz�� gra� (przej�cie przez logowanie)
	nazwakonta = "";
	plik = "";
	plikmiasto = "./PlikiGry/Miasta.txt";
	AktywnyBohater = 0;
	AktywneMiasto = 1; //Domy�lnie jest 1
	AktywnyPotwor = 0;
	plikpotwor = "./PlikiGry/Potwor.txt";
	bud1 = 0;
	bud2 = 0;
	bud3 = 0;
	ukryj = 0;
}

void Gra::InitGry() {
	SetConsoleTitle("EpicGameOfEpicTreasure");
	int wyborotwarcia = 0;
	int logowanie = 0;
	Kolory kolor;
	string nazwagracza = "";
	string haslogracza = "";
	string nazwagracza2 = "";
	string haslogracza2 = ""; 
	ifstream plik;
	ifstream pliklogowanie;
	PanelAdministratorski root;
	pliklogowanie.open("./PlikiGry/Logowanie.txt");
	if (!pliklogowanie.is_open()) {
		root.Menu();
	}
	kolor.red();
	cout << "||==============================||" << endl;
	cout << "||\t\t\t\t||" << endl;
	cout << "||\t "; kolor.blue(); cout << ">>> "; kolor.green(); cout << "Login"; 
	kolor.blue(); cout << " <<<"; kolor.red(); cout << "\t\t|| " << endl;
	cout << "||\t\t\t\t||" << endl;
	cout << "||==============================||" << endl << endl;
	kolor.gold(); cout << ">>>>>>>>";
	kolor.green();
	cin >> nazwagracza;
	system("cls");
	kolor.red();
	cout << "||==============================||" << endl;
	cout << "||\t\t\t\t||" << endl;
	cout << "||\t "; kolor.blue(); cout << ">>> "; kolor.green(); cout << "Has�o";
	kolor.blue(); cout << " <<<"; kolor.red(); cout << "\t\t|| " << endl;
	cout << "||\t\t\t\t||" << endl;
	cout << "||==============================||" << endl << endl;
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
	cin >> haslogracza;
	cin.clear();
	cin.ignore();
	SetConsoleMode(hStdin, mode);
	while (!pliklogowanie.eof()) {
		pliklogowanie >> nazwagracza2 >> haslogracza2;
		if ((nazwagracza == nazwagracza2) && (haslogracza == haslogracza2)){
			logowanie = 1;
			break;
		}
	}
	if (logowanie == 1) {
		if (nazwagracza == "root") {
			root.Menu();
			exit(0);
		} else {
			this->nazwakonta = nazwagracza;
			this->plik = "./PlikiGry/" + nazwagracza + ".txt";
			plik.open("./PlikiGry/" + nazwagracza + ".txt");
			this->loadBohater();
		}
	}
	else {
		system("cls");
		kolor.blue();
		cout << "Nie ma takiego konta, chcesz stworzy� nowe?" << endl;
		kolor.gold();
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
	Kolory kolor;
	kolor.blue();
	cout << "Nowy login: " << endl;
	kolor.gold();
	cin >> nazwaKonta;
	cin.ignore();
	if (nazwaKonta == "root") {
		system("cls"); 
		kolor.red();
		cout << "Nie mo�esz stworzy� konta root!" << endl;
		system("pause");
		exit(0);
	}
	plik.open("./PlikiGry/" + nazwaKonta + ".txt");
	if (plik.is_open()) {
		kolor.red();
		cout << "Konto juz istnieje o takiej nazwie! (Ponowne logowanie)" << endl;
	} else {
		plik.close();
		plik.open("./PlikiGry/" + nazwaKonta + ".txt", ios::out);
		plikhasla.open("./PlikiGry/logowanie.txt", ios::app);
		//Atrybut do chowania plik�w
		//string temp = nazwaKonta + ".txt";
		//string x = "attrib +H " + temp; // + chowa, -odkrywa
		//system(x.c_str());
		kolor.blue();
		cout << "Podaj haslo do konta: " << endl;
		kolor.gold();
		cin >> hasloKonta;
		cin.clear();
		cin.ignore();
		plikhasla << endl << nazwaKonta << " " << hasloKonta;
		this->nazwakonta = nazwaKonta;
		this->plik = "./PlikiGry/" + nazwaKonta + ".txt";
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
			kolor.green(); 
			cout << "||===============================================||" << endl;
			cout << "||"; kolor.red(); cout << "Posiadasz nie wykorzystane punkty umiej�tno�ci!"; 
			kolor.green(); cout << "||" << endl;
			cout << "||===============================================||" << endl;
			kolor.blue();
		}
		if (this->Bohaterzy[AktywnyBohater].graczexp() >=
			this->Bohaterzy[AktywnyBohater].graczexpnextlvl()){
			this->Bohaterzy[AktywnyBohater].lvlup();
		}
		if (this->ukryj == 1) {
			Czekanie2();
			this->ukryj = 0;
		}
		WyswietlMenu();
		cin >> this->wybor;
		cin.clear();
		cin.ignore();
		while (this->wybor < -2 && this->wybor > 1001) {
			system("cls");
			WyswietlMenu();
			cin >> this->wybor;
			cin.clear();
			cin.ignore();
		}

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
			else {
				kolor.red();
				cout << "Nie jeste� w mie�cie, gdzie jest Gospoda!" << endl << endl;
			}
			break;

		case 8:
			Podroz();
			loadPotwor();
			break;
		
		case 9:
			system("cls");
			if (this->Bohaterzy[this->AktywnyBohater].graczekwipunek() == 0) { kolor.red(); cout << "Tw�j ekwipunek jest pusty!" << endl; break; }
			cout << this->Bohaterzy[this->AktywnyBohater].loadekwipunek();
			Czekanie();
			break;

		case 10:
			ZmianaBroni();
			break;

		case 11:
			system("cls");
			if (Bohaterzy[AktywnyBohater].graczpoziom() > 20) PreKruci();
			else {
				kolor.red();
				cout << "Nie wystarczaj�cy ilo�� poziom�w! \nWymagany jest minimalny 20 poziom, aby z nim walczy�!" << endl << endl;
			}
			break;
			
		case 12:
			system("cls");
			if (Bohaterzy[AktywnyBohater].graczpoziom() > 50) PreBoss(); 
			else {
				kolor.red();
				cout << "Nie wystarczaj�cy ilo�� poziom�w! \nWymagany jest minimalny 50 poziom, aby z nim walczy�!" << endl << endl;
			}
			break;

		case 999:
			UsunKonto();
			break;

		case 1000:
			if (ukryj == 0) ukryj = 1;
			else ukryj = 0;
			break;

		case -1:
			system("cls");
			kolor.red(); cout << "\n\t>>>>> Zapisuje <<<<<" << endl;
			saveBohater();
			loadBohater();
			break;

		case -2:
			system("cls");
			kolor.red(); cout << "\n\t>>>>> Wczytano bohatera <<<<<" << endl;
			loadBohater();
			break;

		case 0:
			playing = false;
			break;

		default:
			system("cls");
			break;
		}
	}
	else {
	kolor.red();
		cout << "Tw�j bohater zgin��" << endl;
		Czekanie();
		this->stworzBohatera();
		this->saveBohater();
		this->loadBohater();
	}
}

void Gra::WyswietlMenu() {
	Kolory kolor;
	kolor.gold(); cout << " ===============================================" << endl;
	kolor.blue(); cout << "//\t\t"; kolor.red(); cout << ">>>>>MENU<<<<<<"; kolor.blue(); cout << "\t\t\t\\\\" << endl;
	kolor.blue(); cout << "||\t\t\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\t1 - "; kolor.green(); cout << "Statystyki postaci"; kolor.blue(); cout << "\t\t\t||" << endl;
	kolor.blue(); cout << "||\t2 - "; kolor.green(); cout << "Dodawanie statystyk"; kolor.blue(); cout << "\t\t\t||" << endl;
	kolor.blue(); cout << "||\t3 - "; kolor.green(); cout << "Wy�wietlenie miasta"; kolor.blue(); cout << "\t\t\t||" << endl;
	kolor.blue(); cout << "||\t4 - "; kolor.green(); cout << "Wyb�r budynku"; kolor.blue(); cout << "\t\t\t||" << endl;
	kolor.blue(); cout << "||\t5 - "; kolor.green(); cout << "Zmiana miasta"; kolor.blue(); cout << "\t\t\t||" << endl;
	kolor.blue(); cout << "||\t6 - "; kolor.green(); cout << "Odpoczynek na dworze"; kolor.blue(); cout << "\t\t||" << endl;
	kolor.blue(); cout << "||\t7 - "; kolor.green(); cout << "Odpoczynek w mie�cie"; kolor.blue(); cout << "\t\t||" << endl;
	kolor.blue(); cout << "||\t8 - "; kolor.green(); cout << "Podr� w poszukiwaniu przyg�d"; kolor.blue(); cout << "\t||" << endl;
	kolor.blue(); cout << "||\t9 - "; kolor.green(); cout << "Poka� ekwipunek"; kolor.blue(); cout << "\t\t\t||" << endl;
	kolor.blue(); cout << "||\t10 - "; kolor.green(); cout << "Zmie� przedmiot"; kolor.blue(); cout << "\t\t\t||" << endl;
	kolor.blue(); cout << "||\t11 - "; kolor.green(); cout << "�wi�ta Krucjata"; kolor.blue(); cout << "\t\t\t||" << endl;
	kolor.blue(); cout << "||\t12 - "; kolor.green(); cout << "Boss ostateczny"; kolor.blue(); cout << "\t\t\t||" << endl;
	kolor.blue(); cout << "||\t99 - "; kolor.green(); cout << "Usu� konto"; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\t\t\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\t-1 - "; kolor.green(); cout << "Zapisz"; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\t-2 - "; kolor.green(); cout << "Wczytaj"; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "||\t0 - "; kolor.green(); cout << "Wyj�cie"; kolor.blue(); cout << "\t\t\t\t||" << endl;
	kolor.blue(); cout << "\\\\\t\t\t\t\t\t//" << endl;
	kolor.gold(); cout << " ===============================================" << endl;
	cout << endl << endl << "Jaki jest tw�j wyb�r??: ";
	return;
}

void Gra::UsunKonto() {
	Kolory kolor;
	fstream plik, temp;
	string nazwa, haslo, plik1="./PlikiGry/Logowanie.txt", plik2="./PlikiGry/Logowanie2.txt";
	plik.open("./PlikiGry/Logowanie.txt", ios::in);
	temp.open("./PlikiGry/Logowanie2.txt", ios::out);
	int kod = rand() % 99999 + 10000;
	system("cls"); kolor.red();
	cout << "\nCzy chcesz na pewno skasowa� konto? Aby zaakceptowa� przepisz wygenerowany kod." << endl << endl;
	cout << "Kod: " << kod << endl << endl;
	cin >> this->wybor;
	cin.clear();
	cin.ignore();
	if (this->wybor == kod) {
		while (!plik.eof()) {
			plik >> nazwa >> haslo;
			if (nazwa != this->nazwakonta) {
				temp << nazwa << " " << haslo << endl;
			}
		}
		string Skas = "./PlikiGry/" + this->nazwakonta + ".txt";
		remove(Skas.c_str());
		plik.close();
		temp.close();
		remove(plik1.c_str());
		rename(plik2.c_str(), plik1.c_str());
		exit(0);
	}
	return;
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
		while (nazwa == this->Bohaterzy[i].gracznazwa()) {
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
			PlikGry << this->Bohaterzy[i].getString() << endl;
			PlikGry << this->Bohaterzy[i].saveekwipunek() << endl;
		}
	}
	Bohaterzy.clear();
	this->Bohaterzy.clear();
	
	PlikGry.close();
}

void Gra::loadBohater() {
	ifstream PlikGry(plik);
	Bohaterzy.clear();
	this->Bohaterzy.clear();

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
			temp.graczbron(bron);

			str.clear();
			line.clear();
			getline(PlikGry, line);
			str.str(line);

			while (str >> nazwa2 >> lvl >> rzadkosc >> cenagora >> cenadol
				>> minsila >> maxsila >> minzre >> maxzre >> minmagia
				>> maxmagia >> minszcz >> maxszcz >> minobr >> maxobr) {
				temp.Dodprzedmiot(Bronie(minsila, maxsila, minzre, maxzre,
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
		string blad = "Brak bohater�w do wczytania";
		cout << "Brak bohater�w do odczytania!" << endl;
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
		string blad = "Brak potwor�w do wczytania";
		cout << "Brak potwor�w!" << endl;
		PlikBledu(blad, 3);
		system("pause");
		exit(3);
	}
	PlikPotwor.close();
}

void Gra::poke() {
	Kolory kolor;
	kolor.gold();
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
	int temp = this->Miasta.size();
	cout << "Wyb�r miasta: " << endl << endl;
	for (size_t i = 0; i < this->Miasta.size(); i++){
		cout << "Numer: " << i << " = " << this->Miasta[i].mnazwa() << endl;
	}
	cout << endl;
	cout << "Wybor: ";
	cin >> this->wybor;
	while (cin.fail() || this->wybor >= temp || this->wybor < 0){
		cout << "B��dny zakres!" << endl;
		cin.clear();
		cin.ignore();
		cout << "Wyb�r miasta: " << endl;
		cin >> this->wybor;
	}
	cin.ignore();
	this->AktywneMiasto = this->wybor;
	this->Bohaterzy[AktywnyBohater].graczzmianamiasta(this->wybor);
	//�adowanie budynk�w
	this->bud1 = Miasta[this->wybor].bud1();
	this->bud2 = Miasta[this->wybor].bud2();
	this->bud3 = Miasta[this->wybor].bud3();

	cout << this->Miasta[this->AktywneMiasto].mnazwa() << " wybrano!" << "\n\n";

	system("cls");
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
		cout << "Statystyki, kt�re mo�esz ulepszy� za darmo: " << endl;
		cout << "0: Si�a " << endl;
		cout << "1: Zr�czno�� " << endl;
		cout << "2: Magia " << endl;
		cout << "3: Szcz�cie " << endl;
		cout << "4: obrona " << endl;
		cin >> this->wybor;

		while (cin.fail() || this->wybor > 4 || this->wybor < 0){
			cout << "Wpisz poprawn� cyfr� z zakresu 0 - 4!" << endl;
			cin.clear();
			cin.ignore();
			cout << "Statystyki, kt�re mo�esz ulepszy� za darmo : " << endl;
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
		cout << "Brak punkt�w umiej�tno�ci, nie mo�na doda� wi�cej statystyk" << endl;
		system("pause");
		system("cls");
	}
}

void Gra::Czekanie() {
	Kolory kolor;
	kolor.green();
	cout << endl << "Czekanie na potwierdzenie..." << endl;
	kolor.blue();
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
		cout << "Co chcesz doda�?" << endl;
		cout << "1 - Si�a, 2 - Zr�czno��, 3 - Magia, 4 - Szcz�cie, 5 - Obrona" << endl;
		cout << "6 - Hp, 7 - HpMax, 8 - Exp, 9 - Kasa, 10 - Pkt Um, 11 - DodPoz" << endl;
		cin >> wybieram;
		cin.clear();
		cin.ignore();
		while (cin.fail() || wybieram >= 12 || wybieram < -1) {
			cout << "B��dny zakres" << endl;
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
	Kolory kolor;
	kolor.red();
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW**WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#+........+#WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWW#+-..................-+#WWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWW:..................................-:WWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWW:......................:*#WWWWWWWWWWWWWWWWW#*:......................WWWWW" << endl;
	cout << "WWWWWW+..................=WWWWWWWWWWWWWWWWWWWWWWWWWWWWW=..................WWWWW" << endl;
	cout << "WWWWWW+.................-WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW-.................-WWWWW" << endl;
	cout << "WWWWWW*......=@=*+++*-..=WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW+..-**++*=@@.....:WWWWW" << endl;
	cout << "WWWWWW#......=WWWWWW@..-WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW@...@WWWWWW@.....+WWWWW" << endl;
	cout << "WWWWWW@......=WW+......=WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW+......-WW#.....=WWWWW" << endl;
	cout << "WWWWWWW-.....*WW+.....-WWWW**WWWWWWWWWWWWWWWWWWWWWWW**WWWW-.....:WW#.....@WWWWW" << endl;
	cout << "WWWWWWW+.....+WW=.....=WWW*.....*WWWWWWWWWWWWWWWW*....#WWW=.....+WW=....-WWWWWW" << endl;
	cout << "WWWWWWW#.....:WW#.....WWWW-.......*WWWWWWWWWWW*.......:WWWW.....*WW+....+WWWWWW" << endl;
	cout << "WWWWWWWW-.....WWW....*WWW=..........*WWWWWWW*..........@WWW*....#WW:....#WWWWWW" << endl;
	cout << "WWWWWWWW*.....#WW:...*WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW*....WW@....-WWWWWWW" << endl;
	cout << "WWWWWWWW@.....+WW=..*WWWWWWWWWWWWWWWWWW=.=WWWWWWWWWWWWWWWWWW*..+WW=....*WWWWWWW" << endl;
	cout << "WWWWWWWWW+.....WWW..*WWWWWWWWWWWWWWWWW-...-WWWWWWWWWWWWWWWWW*..#WW:....WWWWWWWW" << endl;
	cout << "WWWWWWWWW@.....=WW+..........:WWWWWW=...+...@WWWWWW:..........-WW@....*WWWWWWWW" << endl;
	cout << "WWWWWWWWWW+....-WW@..........:WWWWWW*.:WWW--#WWWWWW:..........=WW+....WWWWWWWWW" << endl;
	cout << "WWWWWWWWWWW.....=WW+.........WWWWWWWWWWWWWWWWWWWWWWW.........-WW@....=WWWWWWWWW" << endl;
	cout << "WWWWWWWWWWW#....-WWW.........WWWWWWWWWWWWWWWWWWWWWWW.........#WW+...:WWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWW+....+WW#........:WWW=-WWWWW-WWWWW-=WWW:........+WW#....@WWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWW:....=WW*........WWW-.-WWW-.-WWW-.-WWW........-WWW....#WWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWW-....@WW+.......+W:...=W:...=W+...+W-........@WW:...*WWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWW@.....@WW:.............+.....+..............@WW+...*WWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWW@.....@WW+...............................-@WW+...*WWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWW-....@WW=.....W.....-.....-.....W.....:WWW:...*WWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWW:....WWW*..:WW+...=W....:W=...+WW:..*WWW....#WWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWW*....:W:..WWWW..=WW=...=WW:.:WWWW..:W:...-WWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWW@-......-WWWW==WWWW:::WWWW==WWWW-......=WWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWW=.....-WWWWWWWWWWW:WWWWWWWWWWW-....:WWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWW*....-=WWWWWWWWWWWWWWWWWWW=....:@WWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWW=.......#WWWWWWWWWWW#......+WWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWW@:.........---........-#WWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW@+..............:#WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW@*-....-*@WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
	cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << endl;
}

void Gra::Wolniej(const string& Wiadomosc, unsigned int LiczbaMS) {
	for (const char c : Wiadomosc){
		cout << c << flush;
		Sleep(LiczbaMS);
	}
}

void Gra::PreKruci() {
	system("cls");
	string wiadomosc;
	Kolory kolor;
	kolor.blue(); cout << "==================================================================" << endl << endl; kolor.silver();
	wiadomosc = "Wchodzisz, zwyk�y cz�owieku, do tajemnej komnaty... \n\n";
	Wolniej(wiadomosc, 40);
	kolor.blue(); cout << "==================================================================" << endl;
	Czekanie();
	kolor.blue(); cout << "==================================================================" << endl << endl; kolor.silver();
	wiadomosc = "Przychodzisz po z�oto?...\n\n";
	Wolniej(wiadomosc, 40);
	kolor.blue(); cout << "==================================================================" << endl;
	Czekanie();
	kolor.blue(); cout << "==================================================================" << endl << endl; kolor.silver();
	wiadomosc = "Mo�e przychodzisz, aby z�o�y� ofiary?... \n\n";
	Wolniej(wiadomosc, 40);
	kolor.blue(); cout << "==================================================================" << endl;
	Czekanie();
	kolor.blue(); cout << "==================================================================" << endl << endl; kolor.silver();
	wiadomosc = "Tw�j trud jest tutaj nadaremny s�aba istoto...\n\nNikt st�d nie powraca �ywy...\n\n";
	Wolniej(wiadomosc, 40);
	kolor.blue(); cout << "==================================================================" << endl;
	Czekanie();
	kolor.blue(); cout << "==================================================================" << endl << endl; kolor.red();
	wiadomosc = "A teraz... PO�EGNAJ SI� ZE �WIATEM\n\n...WITAJ W MOIM KR�LESTWIE!\n\n";
	Wolniej(wiadomosc, 40);
	kolor.blue(); cout << "==================================================================" << endl;
	Czekanie();
	Kruci();
	kolor.gold();
	wiadomosc = "Czy chcesz walczy� przeciwko z�owieszczej krucjacie?\n\n";
	Wolniej(wiadomosc, 40);
	cin >> this->wybor;
	cin.ignore();
	while (cin.fail() || wybor > 2 || wybor < 0) {
		system("cls");
		kolor.red();
		cout << "B��dny zakres." << endl;
		Kruci();
		cin.clear();
		cin.ignore();
		kolor.gold();
		cout << "Czy chcesz walczy� przeciwko z�owieszczej krucjacie?" << endl;
		cin >> this->wybor;
	}

	if (this->wybor == 1) {
		this->plikpotwor = "./PlikiGry/kruci.txt";
		loadPotwor();
		Boss();
		this->plikpotwor = "./PlikiGry/Potwor.txt";
		loadPotwor();
		system("cls");
	}
	else {
		kolor.red();
		cout << "||============||" << endl;
		cout << "||Stch�rzy�e�!||" << endl;
		cout << "||============||" << endl;
		return;
	}
}

void Gra::PreBoss() {
	Kolory kolor;
	system("cls");
	string wiadomosc;
	wiadomosc = "Wchodzisz do tajemniczego lasu nie opodal miasta Khorinis... \n\n";
	kolor.blue(); cout << "==================================================================" << endl << endl; kolor.red();
	Wolniej(wiadomosc, 30);
	kolor.blue(); cout << "==================================================================" << endl;
	Czekanie();
	wiadomosc = "Po wej�ciu w g��b lasu, wyczuwasz w pobli�u nie typowe zagro�enie. \n\n";
	kolor.blue(); cout << "==================================================================" << endl << endl; kolor.red();
	Wolniej(wiadomosc, 30);
	kolor.blue(); cout << "==================================================================" << endl;
	Czekanie();
	wiadomosc = "Pogoda zamienia si� w burzliw�, makabryczn� noc \n\n";
	kolor.blue(); cout << "==================================================================" << endl << endl; kolor.red();
	Wolniej(wiadomosc, 40);
	kolor.blue(); cout << "==================================================================" << endl;
	Czekanie();
	wiadomosc = "Nagle s�yszysz za sob� dziwny, znajomy Ci d�wi�k... \n\n";
	kolor.blue(); cout << "==================================================================" << endl << endl; kolor.red();
	Wolniej(wiadomosc, 40);
	kolor.blue(); cout << "==================================================================" << endl; 
	Czekanie();
	wiadomosc = "\t\tP i k a P i k a...\n\n";
	kolor.blue(); cout << "==================================================================" << endl << endl; kolor.gold();
	Wolniej(wiadomosc, 100);
	kolor.blue(); cout << "==================================================================" << endl;
	Czekanie();
	cout << "Boss Ostateczny: " << endl << endl;
	kolor.gold();
	poke();
	kolor.green();
	cout << "Czy chcesz walczy� przeciwko bossowi ostatecznemu?" << endl;
	cin >> this->wybor;
	cin.ignore();
	while (cin.fail() || wybor > 2 || wybor < 0) {
		system("cls");
		kolor.red();  cout << "B��dny zakres." << endl; kolor.gold();
		poke();
		cin.clear();
		cin.ignore();
		kolor.green();
		cout << "Czy chcesz walczy� przeciwko bossowi ostatecznemu?" << endl;
		cin >> this->wybor;
	}

	if (this->wybor == 1) {
		this->plikpotwor = "./PlikiGry/boss.txt";
		loadPotwor();
		Boss();
		this->plikpotwor = "./PlikiGry/Potwor.txt";
		loadPotwor();
		system("cls");
	}
	else {
		system("cls");
		kolor.red();
		cout << "||============||" << endl;
		cout << "||Stch�rzy�e�!||" << endl;
		cout << "||============||" << endl;
	}
}

void Gra::Boss() {
	Event walkaboss;
	walkaboss.Walka(this->Bohaterzy[AktywnyBohater], this->PPotwory[AktywnyPotwor]);
	system("cls");
	string koniec="Brawo! Pokona�e� ostatecznego Bossa! Mo�esz si� pochwali� autorowi gry, �e j� przeszed�e� :)";
	Wolniej(koniec, 40);
	Czekanie();
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

void Gra::ZmianaBroni() {
	system("cls");
	if (this->Bohaterzy[this->AktywnyBohater].graczekwipunek() == 0) {
		cout << "Tw�j ekwipunek jest pusty!" << endl;
		return;
	}

	cout << this->Bohaterzy[this->AktywnyBohater].loadekwipunek();
	cout << "Numer przedmiotu: ";
	cin >> this->wybor;

	while (cin.fail() || this->wybor < 0 || this->wybor >= this->Bohaterzy[this->AktywnyBohater].graczekwipunek()) {
		cout << "B��dny wyb�r!" << endl;
		cin.clear();
		cin.ignore();
		cout << "Numer przedmiotu: ";
		cin >> this->wybor;
	}
	cin.ignore();

	this->Bohaterzy[this->AktywnyBohater].zalozprzedmiot(this->wybor);
	system("cls");
}