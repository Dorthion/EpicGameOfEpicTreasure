#include "PanelAdministratorski.h"

PanelAdministratorski::PanelAdministratorski(){
	this->wybor = 0;
	Mmenu = true;
	activemiasto = 1;
	activeMonster = 0;
	plikmiasto = "./PlikiGry/Miasta.txt";
	plikpotwor = "./PlikiGry/Potwor.txt";
}

void PanelAdministratorski::Menu() {
	while (this->Mmenu == true) {
		system("cls");
		cout << "\t>>>>> Panel Administracyjny <<<<<<" << endl << endl;

		cout << "1 - Dodaj/Napraw pliki gry" << endl;
		cout << "2 - Dodaj miasto" << endl;
		cout << "3 - Zapisz miasto" << endl;
		cout << "4 - Wczytaj miasto" << endl;
		cout << "5 - Dodaj potwor" << endl;
		cout << "6 - Zapisz potwor" << endl;
		cout << "7 - Wczytaj potwor" << endl;
		cout << "8 - Instrukcja do gry" << endl;
		cout << "9 - Autor gry" << endl;

		cout << "\n-1 - Zapisz wszystko" << endl;
		cout << "-2 - Wczytaj wszystko" << endl;
		cout << "\n0 - Wyjscie (Bez zapisywania)" << endl;

		cout << endl << "Jaki jest twoj wybor??: ";

		cin >> this->wybor;
		cin.clear();
		cin.ignore();

		switch (this->wybor) {
		case 1:
			DodawaniePlikow();
			loadMiasto();
			loadPotwor();
			break;
		case 2:
			NoweMiasto();
			break;

		case 3:
			saveMiasto();
			break;

		case 4:
			loadMiasto();
			break;
		case 5:
			DodPotwor();
			break;
		case 6:
			savePotwor();
			break;
		case 7:
			loadPotwor();
			break;
		case 8:
			Instrukcja();
			break;
		case 9:
			Autor();
			break;

		case -1:
			saveMiasto();
			savePotwor();
			break;

		case -2:
			loadMiasto();
			loadPotwor();
			break;

		case 0:
			this->Mmenu = false;
			exit(0);
			break;

		default:
			this->Mmenu = false;
			exit(0);
			break;
		}
	}
}

void PanelAdministratorski::DodawaniePlikow() {
	string zapisz = "";
	fstream Logowanie;
	fstream Miasta;
	fstream Potwory;
	fstream Kruci;
	fstream Boss;
	fstream Zagadka1;
	fstream Zagadka2;
	fstream Zagadka3;
	fstream Zagadka4;
	fstream Zagadka5;
	fstream Zagadka6;
	fstream Zagadka7;
	fstream Zagadka8;
	fstream Zagadka9;
	fstream Zagadka10;

	CreateDirectory("./PlikiGry", 0);
	CreateDirectory("./PlikiGry/Zagadki", 0);
	Logowanie.open("./PlikiGry/Logowanie.txt", ios::out);
	Miasta.open("./PlikiGry/Miasta.txt", ios::out);
	Potwory.open("./PlikiGry/Potwor.txt", ios::out);
	Kruci.open("./PlikiGry/Kruci.txt", ios::out);
	Boss.open("./PlikiGry/boss.txt", ios::out);
	Zagadka1.open("./PlikiGry/Zagadki/1.txt", ios::out);
	Zagadka2.open("./PlikiGry/Zagadki/2.txt", ios::out);
	Zagadka3.open("./PlikiGry/Zagadki/3.txt", ios::out);
	Zagadka4.open("./PlikiGry/Zagadki/4.txt", ios::out);
	Zagadka5.open("./PlikiGry/Zagadki/5.txt", ios::out);
	Zagadka6.open("./PlikiGry/Zagadki/6.txt", ios::out);
	Zagadka7.open("./PlikiGry/Zagadki/7.txt", ios::out);
	Zagadka8.open("./PlikiGry/Zagadki/8.txt", ios::out);
	Zagadka9.open("./PlikiGry/Zagadki/9.txt", ios::out);
	Zagadka10.open("./PlikiGry/Zagadki/10.txt", ios::out);
	Logowanie << "root admin";
	Miasta << "Spawn 1 1 2 3" << endl << "Grunwald 2 5 4 8" << endl << "Wyzima 3 2 4 6" << endl << "Toruñ 4 1 8 1" << endl;
	Miasta << "Rivendell 5 5 3 1" << endl << "Novigrad 6 8 7 9" << endl << "Overworld 7 7 4 1" << endl << "Khorinis 8 2 3 4" << endl;
	Potwory << "Zombie 1 1 50 50 5 20 30 30 50" << endl << "Cieñ 2 2 70 70 20 30 30 40 50" << endl << "Zbój 3 4 120 120 30 40 40 50 50" << endl;
	Potwory << "Tyran 4 6 200 200 40 50 40 60 50" << endl << "Ogr 5 8 350 350 50 65 60 70 50" << endl << "Gnoll 6 12 500 500 70 80 60 80 50" << endl;
	Potwory << "Wampir 7 14 1000 1000 96 106 80 90 50" << endl << "Wilko³ak 8 15 1500 1500 100 104 80 100 50" << endl << "Tytan 9 18 2000 2000 120 150 100 150 50" << endl;
	Potwory << "Goblin 10 1 5 5 2 3 4 2 1";
	Boss << "Pikachu 1 200 10000 10000 50 200 200 5000 50";
	Kruci << "Krucjata 1 50 2000 2000 40 100 100 2000 20";

	//Zagadka1
	Zagadka1 << "Jaki jest najczêœciej popularny miecz w œwiece fantastyki?" << endl;
	Zagadka1 << "3" << endl;
	Zagadka1 << "Dark Repulser" << endl;
	Zagadka1 << "Durandal" << endl;
	Zagadka1 << "Excalibur" << endl;
	Zagadka1 << "2" << endl;
	Zagadka1 << "Excalibur jest s³ynny z legend arturiañskich, sam Król Artur otrzyma³ go wed³ug historii od pani jezior";

	//Zagadka2
	Zagadka2 << "Czym jest krucjata ?"<<endl;
	Zagadka2 << "4" << endl;
	Zagadka2 << "Wypraw¹ krzy¿ow¹" << endl;
	Zagadka2 << "Wypraw¹ po z³ote runo" << endl;
	Zagadka2 << "Wypraw¹ wojenn¹" << endl;
	Zagadka2 << "Wypraw¹ kolonizacyjn¹" <<endl;
	Zagadka2 << "0" << endl;
	Zagadka2 << "By³o 7 g³ównych wypraw liczebnych oraz 2 imienne od cesarza rzymsko-niemieckiego Fryderyka II oraz króla anglii Edwarda I" << endl;

	//Zagadka3
	Zagadka3 << "Jaka jest œrednia waga zbroi p³ytowej ze œredniowiecza?" << endl;
	Zagadka3 << "4" << endl;
	Zagadka3 << "10" << endl;
	Zagadka3 << "20" << endl;
	Zagadka3 << "30" << endl;
	Zagadka3 << "50" << endl;
	Zagadka3 << "1" << endl;
	Zagadka3 << "Przeciêta waga zbroi w œredniowieczu wynosi³a 20kg, i by³a tak samo ciê¿ka co sama kolczuga" << endl;

	//Zagadka4
	Zagadka4 << "Jakie dwa pañstwa podpisa³y Traktat z Tordesillas?" << endl;
	Zagadka4 << "3" << endl;
	Zagadka4 << "Holandia i Francja" << endl;
	Zagadka4 << "Anglia i Rosja" << endl;
	Zagadka4 << "Portugalia i Hiszpania" << endl;
	Zagadka4 << "2" << endl;
	Zagadka4 << "Traktat z Tordesillas zapewnia³ Portugalczykom tereny Brazylii jeszcze przed ich oficjalnym odkryciem, przypuszcza siê, ¿e, w przeciwieñstwie do Hiszpanów, wiedzieli oni o jej istieniu." << endl;

	//Zagadka5
	Zagadka5 << "Z czym zwi¹zane by³y dziady ?" << endl;
	Zagadka5 << "5" << endl;
	Zagadka5 << "Z dyniami" << endl;
	Zagadka5 << "Z wiosn¹" << endl;
	Zagadka5 << "Ze smokami" << endl;
	Zagadka5 << "Z rad¹ starszych" << endl;
	Zagadka5 << "Z duszami zmar³ych" << endl;
	Zagadka5 << "4" << endl;
	Zagadka5 << "Celem dziadów by³o uzyskanie w czasie obrzêdów przychylnoæci zmar³ych, których uwa¿ano za opiekunów w sferze p³odnosci i urodzaju" << endl;

	//Zagadka6
	Zagadka6 << "Na czym Wenecja dorobi³a siê swojego bogactwa?" << endl;
	Zagadka6 << "4" << endl;
	Zagadka6 << "Handlem ludŸmi" << endl;
	Zagadka6 << "Handlem przyprawami" << endl;
	Zagadka6 << "Handlem wojskami" << endl;
	Zagadka6 << "Handlem szpiegami" << endl;
	Zagadka6 << "1" << endl;
	Zagadka6 << "Wenecja w czasie œredniowiecza mia³a praktyczny monopol na handel przyprawami pomiêdzy Bliskim Wschodem, a Europ¹ Zachodni¹" << endl;

	//Zagadka7
	Zagadka7 << "Kto z wikingów nosi³ he³m w œredniowieczu?" << endl;
	Zagadka7 << "4" << endl;
	Zagadka7 << "Norwegowie" << endl;
	Zagadka7 << "Wodzowie" << endl;
	Zagadka7 << "Wodzowie zas³u¿eni w boju" << endl;
	Zagadka7 << "Nikt" << endl;
	Zagadka7 << "3" << endl;
	Zagadka7 << "W czasie œredniowiecza nikt nie nosi³ he³mu z rogami, taka moda zaistnia³a dopiero w XIX wieku" << endl;

	//Zagadka8
	Zagadka8 << "Jak d³ugo traw³ post w czasie œredniowiecza?" << endl;
	Zagadka8 << "5" << endl;
	Zagadka8 << "2 dni" << endl;
	Zagadka8 << "Tydzieñ + Œwiêta" << endl;
	Zagadka8 << "1/3 Roku" << endl;
	Zagadka8 << "Pó³ Roku" << endl;
	Zagadka8 << "Ca³y rok" << endl;
	Zagadka8 << "2" << endl;
	Zagadka8 << "Koœció³ za starych czasów narzuca³ surowe posty, wstrzemiêŸliwoœæ by³a utrzymywana w œrody, pi¹tki, okres Wielkiego Postu i œwi¹t, czyli razem ponad jedn¹ trzeci¹ roku" << endl;

	//Zagadka9
	Zagadka9 << "Kto odkry³ i udowodni³, ¿e ziemia nie jest p³aska?" << endl;
	Zagadka9 << "3" << endl;
	Zagadka9 << "Miko³aj Kopernik" << endl;
	Zagadka9 << "Miros³a Hermaszewski" << endl;
	Zagadka9 << "Eric Dubay" << endl;
	Zagadka9 << "0" << endl;
	Zagadka9 << "Kopernik jest polskim astronomem, który urodzi³ siê w Toruniu. Jego najs³ynniejsze dzie³o to \"O obrotach sfer niebieskich\"" << endl;

	//Zagadka10
	Zagadka10 << "Który z polskich królów \"zasta³ Polskê drewnian¹, a zostawi³ murowan¹\"?" << endl;
	Zagadka10 << "3" << endl;
	Zagadka10 << "Kazimierz III Wielki" << endl;
	Zagadka10 << "W³adys³aw Jagie³³o" << endl;
	Zagadka10 << "Kazimierz Krzywousty" << endl;
	Zagadka10 << "0" << endl;
	Zagadka10 << "Jako król, ustanowi³ mocn¹ politykê wewnêtrzn¹, a w tym: modernizacja pañstwa, uporz¹dkowanie domeny królewskiej oraz popieranie nauki" << endl;

	Logowanie.close();
	Miasta.close();
	Potwory.close();
	Kruci.close();
	Boss.close();
}

void PanelAdministratorski::NoweMiasto() {
	string nazwa = "";
	int max = 0;
	cout << "Nazwa miasta: ";
	getline(cin, nazwa);
	for (size_t i = 0; i < this->Miasta.size(); i++) {
		while (nazwa == this->Miasta[i].mnazwa()) {
			cout << "Miasto o takiej nazwie istnieje!" << "\n";
			cout << "Nazwa miasta: ";
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

void PanelAdministratorski::saveMiasto() {
	ofstream PlikMiasto(plikmiasto);
	if (PlikMiasto.is_open()) {
		for (size_t i = 0; i < this->Miasta.size(); i++) {
			PlikMiasto << this->Miasta[i].getString() << endl;
		}
	}
	PlikMiasto.close();
}

void PanelAdministratorski::savePotwor() {
	ofstream PlikPotwor(plikpotwor);
	if (PlikPotwor.is_open()) {
		for (size_t i = 0; i < this->PPotwory.size(); i++) {
			PlikPotwor << this->PPotwory[i].getString() << endl;
		}
	}
	PlikPotwor.close();
}

void PanelAdministratorski::DodPotwor() {
	string nazwa = "";
	int max = 0, poziomp = 0;
	cout << "Nazwa potwora: ";
	getline(cin, nazwa);
	for (size_t i = 0; i < this->PPotwory.size(); i++) {
		while (nazwa == this->PPotwory[i].pnazwa()) {
			cout << "Potwor o takiej nazwie istnieje!" << endl;
			cout << "Nazwe potwora: ";
			getline(cin, nazwa);
		}
		if (max <= this->PPotwory[i].nrpotwora()) {
			max = this->PPotwory[i].nrpotwora();
		}
	}
	cout << "Podaj poziom potwora: " << endl;
	cin >> poziomp;
	while (cin.fail() || poziomp >= 0) {
		cout << "Z³y poziom potwora!" << endl;
		cout << "Podaj poziom potwora: ";
		getline(cin, nazwa);
	}
	cin.clear();
	cin.ignore();
	PPotwory.push_back(Potwory());
	activeMonster = PPotwory.size() - 1;
	PPotwory[activeMonster].inicjalizacja(nazwa, max, poziomp);
}

void PanelAdministratorski::loadMiasto() {
	ifstream PlikMiasto(plikmiasto);
	this->Miasta.clear();

	int numermiasta = 0;
	int nrbudynku1 = 0;
	int nrbudynku2 = 0;
	int nrbudynku3 = 0;

	string nazwa = "";
	string line = "";
	stringstream str;

	if (PlikMiasto.is_open()) {
		while (getline(PlikMiasto, line)) {
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
	if (this->Miasta.size() <= 0) {
		string blad = "Brak miast do wczytania";
		cout << "Brak miast do wczytania!" << endl;
		PlikBledu(blad, 2);
		system("pause");
		exit(2);
	}
	PlikMiasto.close();
}

void PanelAdministratorski::loadPotwor() {
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

void PanelAdministratorski::Autor() {
	system("cls");
	cout << "Autorem gry jest (Dodaj imiê przed oddaniem projektu XD)" << endl;
	cout << "Kontakt: (Email - o ile chce mi siê go udostêpniaæ)" << endl;
	system("pause");
	return;
}

void PanelAdministratorski::Instrukcja() {
	system("cls");
	cout << "Instrukcja do gry: Epic Game Of Epic Treasure" << endl << endl;
	cout << "Gra polega na systemie SUD - Single-User Dungeon. \nJest napisana w trybie tekstowym, co niektórym mo¿e siê to nie podobaæ, \nlecz mam nadziejê na dobry odzew od strony gracza." << endl << endl;
	cout << "Na pocz¹tku gry trzeba stworzyæ odpowiednie pliki gry.\nMo¿na je utworzyæ w panelu administratorskim wyborem nr.1." << endl;
	cout << "Po stworzeniu odpowiednich plików mo¿na dodaæ swoje dodatkowe miasta, \na przy ich tworzeniu mo¿na wybraæ odpowiednie dla nich budynki" << endl;
	cout << "Mo¿na te¿ dodaæ swoje potwory, przydzielaj¹c im odpowiednie kryteria \nstatystyk, np. si³a, poziom itd." << endl;
	cout << "Uwaga: Nale¿y zapisaæ wszystko przed wyjœciem! Brak zapisu oznacza \nanulowanie zmian zachodz¹cych w plikach." << endl << endl;
	cout << "Ka¿dy gracz tworzy swoje konto i nim siê loguje do swojej postaci. \nEkwipunek nie jest dzielony pomiêdzy kontami." << endl;
	cout << "Gracz ma za zadanie podró¿owanie po œwiecie. \nSpotyka ró¿ne przygody, zagadki oraz przeciwników." << endl;
	cout << "Za zabicie przeciwników, rozwi¹zanie zagadek mo¿na zdobyæ monety oraz \n odpowiedni¹ iloœæ doœwiadczenia, dalej zwan¹ jako exp." << endl;
	cout << "Po zdobyciu odpowiedniej iloœci monet mo¿na zakupiæ odpowiedni sprzêt w mieœcie." << endl << endl;
	cout << "Dla urozmaicenia, ka¿de miasto posiada tylko 3 budynki, \nz czego mog¹ siê powtarzaæ." << endl;
	cout << "Ka¿dy budynek ma przydzielon¹ swoj¹ rolê, \ngdzie mo¿na znaleŸæ wœród nich ciekawe interakcje" << endl << endl;
	cout << "Zadaniem pobocznym jest pokonanie œwiêtej krucjaty, \nktóry jest wyznacznikiem po³owy ukoñczenia gry" << endl;
	cout << "G³ównym celem gry jest zabicie bossa, który jest udostêpniony \npo zdobyciu 50 poziomu postaci." << endl << endl;
	cout << "Pokonanie bossa oznacza koniec gry oraz zwyciêstwo gracza. \nPolecam udostêpniæ autorowi gry statystyki postaci, \nz jakimi móg³ siê zmierzyæ z samym bossem i jego pokonaniem." << endl << endl;
	cout << "¯yczê mi³ej i wytrwa³ej gry" << endl << "Autor gry" << endl << endl;
	system("pause");
}

void PanelAdministratorski::PlikBledu(string nazwa, int kod) {
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