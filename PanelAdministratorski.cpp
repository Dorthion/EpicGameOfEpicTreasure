#include "PanelAdministratorski.h"

PanelAdministratorski::PanelAdministratorski(){
	this->wybor = 0;
	Mmenu = true;
	activemiasto = 1;
	activeMonster = 0;
	plikmiasto = "Miasta.txt";
	plikpotwor = "Potwor.txt";
}

PanelAdministratorski::~PanelAdministratorski(){
}

void PanelAdministratorski::Menu() {
	while (this->Mmenu == true) {
		system("cls");
		cout << "\t>>>>> Panel Administracyjny <<<<<<" << endl << endl;

		cout << "1 - Dodaj pliki gry" << endl;
		cout << "2 - Dodaj miasto" << endl;
		cout << "3 - Zapisz miasto" << endl;
		cout << "4 - Wczytaj miasto" << endl;
		cout << "5 - Dodaj potwor" << endl;
		cout << "6 - Zapisz potwor" << endl;
		cout << "7 - Wczytaj potwor" << endl;

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

	CreateDirectory("./Zagadki", 0);
	Logowanie.open("Logowanie.txt", ios::out);
	Miasta.open("Miasta.txt", ios::out);
	Potwory.open("Potwor.txt", ios::out);
	Kruci.open("Kruci.txt", ios::out);
	Boss.open("boss.txt", ios::out);
	Zagadka1.open("./Zagadki/1.txt", ios::out);
	Zagadka2.open("./Zagadki/2.txt", ios::out);
	Zagadka3.open("./Zagadki/3.txt", ios::out);
	Zagadka4.open("./Zagadki/4.txt", ios::out);
	Zagadka5.open("./Zagadki/5.txt", ios::out);
	Zagadka6.open("./Zagadki/6.txt", ios::out);
	Zagadka7.open("./Zagadki/7.txt", ios::out);
	Zagadka8.open("./Zagadki/8.txt", ios::out);
	Zagadka9.open("./Zagadki/9.txt", ios::out);
	Zagadka10.open("./Zagadki/10.txt", ios::out);
	Logowanie << "root admin";
	Miasta << "Spawn 1 1 2 3" << endl <<"Grunwald 2 7 8 9";
	Potwory << "Goblin 1 1 5 5 2 3 4 2 1";
	Boss << "Pikachu 1 200 10000 10000 50 200 200 5000 50";
	Kruci << "Krucjata 1 50 2000 2000 40 100 100 2000 20";

	//Zagadka1
	Zagadka1 << "Jaki jest najczêœciej popularny miecz w œwiece fantastyki?" << endl;
	Zagadka1 << "3" << endl;
	Zagadka1 << "Dark Repulser" << endl;
	Zagadka1 << "Durandal" << endl;
	Zagadka1 << "Excalibur" << endl;
	Zagadka1 << "2" << endl;
	Zagadka1 << "Excalibur jest s³ynny z legend arturiañskich, sam król(Artur) otrzyma³ go wed³ug historii od pani jezior";

	//Zagadka2
	Zagadka2 << "Czym jest krucjata ?"<<endl;
	Zagadka2 << "4" << endl;
	Zagadka2 << "Wypraw¹ krzy¿ow¹" << endl;
	Zagadka2 << "Wypraw¹ po z³ote runo" << endl;
	Zagadka2 << "Wypraw¹ wojenn¹" << endl;
	Zagadka2 << "Wypraw¹ kolonizacyjn¹" <<endl;
	Zagadka2 << "0" << endl;
	Zagadka2 << "By³o 7, g³ównych wypraw liczebnych oraz 2 imienne od cesarza rzymsko - niemieckiego FryderykaII oraz króla anglii EdwardaI" << endl;

	//Zagadka3
	Zagadka3 << "Jaka jest œrednia waga zbroi p³ytowej ze œredniowiecza ?" << endl;
	Zagadka3 << "4" << endl;
	Zagadka3 << "10" << endl;
	Zagadka3 << "20" << endl;
	Zagadka3 << "30" << endl;
	Zagadka3 << "50" << endl;
	Zagadka3 << "1" << endl;
	Zagadka3 << "Przeciêta waga w œredniowieczu wynosi³a 20kg, w porównaniu wagi by³a tak samo ciê¿ka co sama kolczuga" << endl;

	//Zagadka4
	Zagadka4 << "Które para mocarstw jako pierwsze by³y wyniesione w œredniowieczu poprzez odkrycia geograficzne(kolonie) ?" << endl;
	Zagadka4 << "3" << endl;
	Zagadka4 << "Holandia i Francja" << endl;
	Zagadka4 << "Anglia i Rosja" << endl;
	Zagadka4 << "Portugalia i Hiszpania" << endl;
	Zagadka4 << "2" << endl;
	Zagadka4 << "Poprzez te odkrycia wywo³ano 3 du¿e wojny : Wojna Siedmioletnia, Wojna Rosyjsko - Japonska, I Wojna Swiatowa" << endl;

	//Zagadka5
	Zagadka5 << "Z czym zwi¹zane by³y dziady ?" << endl;
	Zagadka5 << "5" << endl;
	Zagadka5 << "Z dyniami" << endl;
	Zagadka5 << "Z wiosn¹" << endl;
	Zagadka5 << "Ze smokami" << endl;
	Zagadka5 << "Z rada starszych" << endl;
	Zagadka5 << "Z duszami zmarlych" << endl;
	Zagadka5 << "4" << endl;
	Zagadka5 << "Celem dziadow bylo uzyskanie w czasie obrzedow przychylnosci zmarlych, ktorych uwazano za opiekunow w sferze plodnosci i urodzaju" << endl;

	//Zagadka6
	Zagadka6 << "Na czym miasto : Wenecja, dorobi³o swojego bogactwa ?" << endl;
	Zagadka6 << "4" << endl;
	Zagadka6 << "Handlem ludŸmi" << endl;
	Zagadka6 << "Handlem przyprawami" << endl;
	Zagadka6 << "Handlem wojskami" << endl;
	Zagadka6 << "Handlem szpiegami" << endl;
	Zagadka6 << "1" << endl;
	Zagadka6 << "Wenecja w czasie sredniowiecza miala praktyczny monopol na handel przyprawami pomiedzy Bliskim Wschodem, a Europa Zachodnia" << endl;

	//Zagadka7
	Zagadka7 << "Kto z wikingów nosi³ he³m w œredniowieczu ?" << endl;
	Zagadka7 << "4" << endl;
	Zagadka7 << "Norwegowie" << endl;
	Zagadka7 << "Wodzowie" << endl;
	Zagadka7 << "Wodzowie zas³u¿eni w boju" << endl;
	Zagadka7 << "Nikt(Takze powyzsi)" << endl;
	Zagadka7 << "3" << endl;
	Zagadka7 << "W czasie œredniowiecza nikt nie nosi³ he³mu z rogami, taka moda zaistnia³a dopiero w XIX wieku" << endl;

	//Zagadka8
	Zagadka8 << "Jak d³ugo traw³ post w czasie œredniowiecza ?" << endl;
	Zagadka8 << "5" << endl;
	Zagadka8 << "2 dni" << endl;
	Zagadka8 << "Tydzieñ + Œwiêta" << endl;
	Zagadka8 << "1 / 3 Roku" << endl;
	Zagadka8 << "Pó³ Roku" << endl;
	Zagadka8 << "Ca³y rok" << endl;
	Zagadka8 << "2" << endl;
	Zagadka8 << "Koœció³ za starych czasów narzuca³ surowe posty, wstrzemiêŸliwoœæ by³a utrzymywana w œrody, pi¹tki, okresy wielkiego postu i œwi¹t, czyli razem ponad jedn¹ trzeci¹ roku" << endl;

	//Zagadka9
	Zagadka9 << "Kto odkry³ i udowodni³, ¿e ziemia nie jest p³aska ?" << endl;
	Zagadka9 << "3" << endl;
	Zagadka9 << "Miko³aj Kopernik" << endl;
	Zagadka9 << "Miros³a Hermaszewski" << endl;
	Zagadka9 << "Eric Dubay" << endl;
	Zagadka9 << "0" << endl;
	Zagadka9 << "Kopernik jest polskim astronomem, który urodzi³ siê w Toruniu.Jego najs³ynniejsze dzie³o to O obrotach sfer niebieskich" << endl;

	//Zagadka10
	Zagadka10 << "Który z polskich królów zasta³ Polskê drewnian¹, a zostawi³ murowan¹ ?" << endl;
	Zagadka10 << "3" << endl;
	Zagadka10 << "Kazimierz III Wielki" << endl;
	Zagadka10 << "W³adys³aw Jagie³³o" << endl;
	Zagadka10 << "Kazimierz Krzywousty" << endl;
	Zagadka10 << "0" << endl;
	Zagadka10 << "Jako król, ustanowi³ mocn¹ politykê wewnêtrzn¹, a w tym : modernizacja pañstwa, uporz¹dkowanie domeny królewsjkiej oraz popieranie nauki" << endl;

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

void PanelAdministratorski::saveMiasto() {
	ofstream PlikMiasto(plikmiasto);
	if (PlikMiasto.is_open()) {
		for (size_t i = 0; i < this->Miasta.size(); i++) {
			PlikMiasto << this->Miasta[i].getAsString() << endl;
		}
	}
	PlikMiasto.close();
}

void PanelAdministratorski::savePotwor() {
	ofstream PlikPotwor(plikpotwor);
	if (PlikPotwor.is_open()) {
		for (size_t i = 0; i < this->PPotwory.size(); i++) {
			PlikPotwor << this->PPotwory[i].GetAsString() << endl;
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