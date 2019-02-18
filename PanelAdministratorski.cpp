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
	Miasta << "Spawn 1 1 2 3" << endl << "Grunwald 2 5 4 8" << endl << "Wyzima 3 2 4 6" << endl << "Toru� 4 1 8 1" << endl;
	Miasta << "Rivendell 5 5 3 1" << endl << "Novigrad 6 8 7 9" << endl << "Overworld 7 7 4 1" << endl << "Khorinis 8 2 3 4" << endl;
	Potwory << "Zombie 1 1 50 50 5 20 30 30 50" << endl << "Cie� 2 2 70 70 20 30 30 40 50" << endl << "Zb�j 3 4 120 120 30 40 40 50 50" << endl;
	Potwory << "Tyran 4 6 200 200 40 50 40 60 50" << endl << "Ogr 5 8 350 350 50 65 60 70 50" << endl << "Gnoll 6 12 500 500 70 80 60 80 50" << endl;
	Potwory << "Wampir 7 14 1000 1000 96 106 80 90 50" << endl << "Wilko�ak 8 15 1500 1500 100 104 80 100 50" << endl << "Tytan 9 18 2000 2000 120 150 100 150 50" << endl;
	Potwory << "Goblin 10 1 5 5 2 3 4 2 1";
	Boss << "Pikachu 1 200 10000 10000 50 200 200 5000 50";
	Kruci << "Krucjata 1 50 2000 2000 40 100 100 2000 20";

	//Zagadka1
	Zagadka1 << "Jaki jest najcz�ciej popularny miecz w �wiece fantastyki?" << endl;
	Zagadka1 << "3" << endl;
	Zagadka1 << "Dark Repulser" << endl;
	Zagadka1 << "Durandal" << endl;
	Zagadka1 << "Excalibur" << endl;
	Zagadka1 << "2" << endl;
	Zagadka1 << "Excalibur jest s�ynny z legend arturia�skich, sam Kr�l Artur otrzyma� go wed�ug historii od pani jezior";

	//Zagadka2
	Zagadka2 << "Czym jest krucjata ?"<<endl;
	Zagadka2 << "4" << endl;
	Zagadka2 << "Wypraw� krzy�ow�" << endl;
	Zagadka2 << "Wypraw� po z�ote runo" << endl;
	Zagadka2 << "Wypraw� wojenn�" << endl;
	Zagadka2 << "Wypraw� kolonizacyjn�" <<endl;
	Zagadka2 << "0" << endl;
	Zagadka2 << "By�o 7 g��wnych wypraw liczebnych oraz 2 imienne od cesarza rzymsko-niemieckiego Fryderyka II oraz kr�la anglii Edwarda I" << endl;

	//Zagadka3
	Zagadka3 << "Jaka jest �rednia waga zbroi p�ytowej ze �redniowiecza?" << endl;
	Zagadka3 << "4" << endl;
	Zagadka3 << "10" << endl;
	Zagadka3 << "20" << endl;
	Zagadka3 << "30" << endl;
	Zagadka3 << "50" << endl;
	Zagadka3 << "1" << endl;
	Zagadka3 << "Przeci�ta waga zbroi w �redniowieczu wynosi�a 20kg, i by�a tak samo ci�ka co sama kolczuga" << endl;

	//Zagadka4
	Zagadka4 << "Jakie dwa pa�stwa podpisa�y Traktat z Tordesillas?" << endl;
	Zagadka4 << "3" << endl;
	Zagadka4 << "Holandia i Francja" << endl;
	Zagadka4 << "Anglia i Rosja" << endl;
	Zagadka4 << "Portugalia i Hiszpania" << endl;
	Zagadka4 << "2" << endl;
	Zagadka4 << "Traktat z Tordesillas zapewnia� Portugalczykom tereny Brazylii jeszcze przed ich oficjalnym odkryciem, przypuszcza si�, �e, w przeciwie�stwie do Hiszpan�w, wiedzieli oni o jej istieniu." << endl;

	//Zagadka5
	Zagadka5 << "Z czym zwi�zane by�y dziady ?" << endl;
	Zagadka5 << "5" << endl;
	Zagadka5 << "Z dyniami" << endl;
	Zagadka5 << "Z wiosn�" << endl;
	Zagadka5 << "Ze smokami" << endl;
	Zagadka5 << "Z rad� starszych" << endl;
	Zagadka5 << "Z duszami zmar�ych" << endl;
	Zagadka5 << "4" << endl;
	Zagadka5 << "Celem dziad�w by�o uzyskanie w czasie obrz�d�w przychylno�ci zmar�ych, kt�rych uwa�ano za opiekun�w w sferze p�odnosci i urodzaju" << endl;

	//Zagadka6
	Zagadka6 << "Na czym Wenecja dorobi�a si� swojego bogactwa?" << endl;
	Zagadka6 << "4" << endl;
	Zagadka6 << "Handlem lud�mi" << endl;
	Zagadka6 << "Handlem przyprawami" << endl;
	Zagadka6 << "Handlem wojskami" << endl;
	Zagadka6 << "Handlem szpiegami" << endl;
	Zagadka6 << "1" << endl;
	Zagadka6 << "Wenecja w czasie �redniowiecza mia�a praktyczny monopol na handel przyprawami pomi�dzy Bliskim Wschodem, a Europ� Zachodni�" << endl;

	//Zagadka7
	Zagadka7 << "Kto z wiking�w nosi� he�m w �redniowieczu?" << endl;
	Zagadka7 << "4" << endl;
	Zagadka7 << "Norwegowie" << endl;
	Zagadka7 << "Wodzowie" << endl;
	Zagadka7 << "Wodzowie zas�u�eni w boju" << endl;
	Zagadka7 << "Nikt" << endl;
	Zagadka7 << "3" << endl;
	Zagadka7 << "W czasie �redniowiecza nikt nie nosi� he�mu z rogami, taka moda zaistnia�a dopiero w XIX wieku" << endl;

	//Zagadka8
	Zagadka8 << "Jak d�ugo traw� post w czasie �redniowiecza?" << endl;
	Zagadka8 << "5" << endl;
	Zagadka8 << "2 dni" << endl;
	Zagadka8 << "Tydzie� + �wi�ta" << endl;
	Zagadka8 << "1/3 Roku" << endl;
	Zagadka8 << "P� Roku" << endl;
	Zagadka8 << "Ca�y rok" << endl;
	Zagadka8 << "2" << endl;
	Zagadka8 << "Ko�ci� za starych czas�w narzuca� surowe posty, wstrzemi�liwo�� by�a utrzymywana w �rody, pi�tki, okres Wielkiego Postu i �wi�t, czyli razem ponad jedn� trzeci� roku" << endl;

	//Zagadka9
	Zagadka9 << "Kto odkry� i udowodni�, �e ziemia nie jest p�aska?" << endl;
	Zagadka9 << "3" << endl;
	Zagadka9 << "Miko�aj Kopernik" << endl;
	Zagadka9 << "Miros�a Hermaszewski" << endl;
	Zagadka9 << "Eric Dubay" << endl;
	Zagadka9 << "0" << endl;
	Zagadka9 << "Kopernik jest polskim astronomem, kt�ry urodzi� si� w Toruniu. Jego najs�ynniejsze dzie�o to \"O obrotach sfer niebieskich\"" << endl;

	//Zagadka10
	Zagadka10 << "Kt�ry z polskich kr�l�w \"zasta� Polsk� drewnian�, a zostawi� murowan�\"?" << endl;
	Zagadka10 << "3" << endl;
	Zagadka10 << "Kazimierz III Wielki" << endl;
	Zagadka10 << "W�adys�aw Jagie��o" << endl;
	Zagadka10 << "Kazimierz Krzywousty" << endl;
	Zagadka10 << "0" << endl;
	Zagadka10 << "Jako kr�l, ustanowi� mocn� polityk� wewn�trzn�, a w tym: modernizacja pa�stwa, uporz�dkowanie domeny kr�lewskiej oraz popieranie nauki" << endl;

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
		cout << "Z�y poziom potwora!" << endl;
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
		string blad = "Brak potwor�w do wczytania";
		cout << "Brak potwor�w!" << endl;
		PlikBledu(blad, 3);
		system("pause");
		exit(3);
	}
	PlikPotwor.close();
}

void PanelAdministratorski::Autor() {
	system("cls");
	cout << "Autorem gry jest (Dodaj imi� przed oddaniem projektu XD)" << endl;
	cout << "Kontakt: (Email - o ile chce mi si� go udost�pnia�)" << endl;
	system("pause");
	return;
}

void PanelAdministratorski::Instrukcja() {
	system("cls");
	cout << "Instrukcja do gry: Epic Game Of Epic Treasure" << endl << endl;
	cout << "Gra polega na systemie SUD - Single-User Dungeon. \nJest napisana w trybie tekstowym, co niekt�rym mo�e si� to nie podoba�, \nlecz mam nadziej� na dobry odzew od strony gracza." << endl << endl;
	cout << "Na pocz�tku gry trzeba stworzy� odpowiednie pliki gry.\nMo�na je utworzy� w panelu administratorskim wyborem nr.1." << endl;
	cout << "Po stworzeniu odpowiednich plik�w mo�na doda� swoje dodatkowe miasta, \na przy ich tworzeniu mo�na wybra� odpowiednie dla nich budynki" << endl;
	cout << "Mo�na te� doda� swoje potwory, przydzielaj�c im odpowiednie kryteria \nstatystyk, np. si�a, poziom itd." << endl;
	cout << "Uwaga: Nale�y zapisa� wszystko przed wyj�ciem! Brak zapisu oznacza \nanulowanie zmian zachodz�cych w plikach." << endl << endl;
	cout << "Ka�dy gracz tworzy swoje konto i nim si� loguje do swojej postaci. \nEkwipunek nie jest dzielony pomi�dzy kontami." << endl;
	cout << "Gracz ma za zadanie podr�owanie po �wiecie. \nSpotyka r�ne przygody, zagadki oraz przeciwnik�w." << endl;
	cout << "Za zabicie przeciwnik�w, rozwi�zanie zagadek mo�na zdoby� monety oraz \n odpowiedni� ilo�� do�wiadczenia, dalej zwan� jako exp." << endl;
	cout << "Po zdobyciu odpowiedniej ilo�ci monet mo�na zakupi� odpowiedni sprz�t w mie�cie." << endl << endl;
	cout << "Dla urozmaicenia, ka�de miasto posiada tylko 3 budynki, \nz czego mog� si� powtarza�." << endl;
	cout << "Ka�dy budynek ma przydzielon� swoj� rol�, \ngdzie mo�na znale�� w�r�d nich ciekawe interakcje" << endl << endl;
	cout << "Zadaniem pobocznym jest pokonanie �wi�tej krucjaty, \nkt�ry jest wyznacznikiem po�owy uko�czenia gry" << endl;
	cout << "G��wnym celem gry jest zabicie bossa, kt�ry jest udost�pniony \npo zdobyciu 50 poziomu postaci." << endl << endl;
	cout << "Pokonanie bossa oznacza koniec gry oraz zwyci�stwo gracza. \nPolecam udost�pni� autorowi gry statystyki postaci, \nz jakimi m�g� si� zmierzy� z samym bossem i jego pokonaniem." << endl << endl;
	cout << "�ycz� mi�ej i wytrwa�ej gry" << endl << "Autor gry" << endl << endl;
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