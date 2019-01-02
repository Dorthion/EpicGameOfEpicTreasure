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
	this->update();
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
	this->update();
	cout << "Zwiêkszono poziom bohatera " << this->poziom << "!" << endl;
}

void Bohater::update(){
}

string Bohater::getAsString() const{
	return nazwa + " " + to_string(poziom) + " "+ to_string(exp) + " "
	+ to_string(expnextlvl) + " " + to_string(hp) + " " + to_string(hpmax) + " "
	+ to_string(sila) + " " + to_string(zrecznosc) + " "+ to_string(magia) + " "
	+ to_string(szczescie) + " " + to_string(obrona) + " "+ to_string(pktum)
	+ " " + to_string(miasto) + " " + to_string(kasa) + " " + this->bron.toStringSave();
}

void Bohater::odpoczynek() {
	cout << "W³aœnie odpoczywasz w "<<endl;
	this->hp = this->hpmax;
}

void Bohater::zranienie() {
	cout << "Zostales zraniony" << endl;
	this->exp += 50;
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
		cout << "Twój bohater zgin¹³" << endl;
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

string Bohater::loadekwipunek(bool shop){
	string inv;
	for (size_t i = 0; i < this->ekwipunek.size(); i++){
		if (shop){
			inv += to_string(i) + ": " + this->ekwipunek[i].toString() + "\n" + " - Cena sprzeda¿y: "
				+ std::to_string(this->ekwipunek[i].getSellValue()) + "\n";
		} else {
			inv += to_string(i) + ": " + this->ekwipunek[i].toString() + "\n";
		}
	}
	return inv;
}

string Bohater::saveekwipunek(){
	string inv;
	for (size_t i = 0; i < this->ekwipunek.size(); i++){
			inv += this->ekwipunek[i].toStringSave();
	}

	inv += "\n";

	return inv;
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
	int choice = 0;
	bool shopping = true;
	Ekwipunek merchantInv;
	string inv;

	int nrOfItems = rand() % 10 + 3;

	for (size_t i = 0; i < nrOfItems; i++){
		merchantInv.addItem(Bronie(nrbudynku, graczpoziom() + rand() % 5, rand() % 4));
	}
	if (nrbudynku > 1 && nrbudynku<7) {
		while (shopping) {
			system("cls");
			cout << ">>>>>" << budynki[nrbudynku] << " w " << nazwamiasta << " <<<<<<<" << endl << endl;
			cout << "0: WyjdŸ ze sklepu" << endl << "1: Kup" << endl << endl << "Wybór: ";
			cin >> choice;
			cin.ignore();
			while (cin.fail() || choice > 3 || choice < 0) {
				system("cls");
				cout << "B³êdny zakres." << endl;
				cin.clear();
				cin.ignore();
				cout << ">>>>>" << budynki[nrbudynku] << " w " << nazwamiasta << " <<<<<<<" << endl << endl;
				cout << "0: WyjdŸ ze sklepu" << endl << "1: Kup" << endl << endl << "Wybór: ";
				cin >> choice;
			}

			//cin.ignore();
			switch (choice) {
			case 0:
				shopping = false;
				break;

			case 1:
				cout << ">>>>> Kupujesz" << " w " << budynki[nrbudynku] << " <<<<<<<" << endl << endl;
				cout << " - Kasa: " << graczkasa() << "\n\n";
				inv.clear();

				for (size_t i = 0; i < merchantInv.size(); i++) {
					inv += to_string(i) + ": " + merchantInv[i].toString() + "\n - Cena: " + to_string(merchantInv[i].getBuyValue()) + "\n";
				}

				cout << inv << "\n";

				cout << "Kasa: " << graczkasa() << "\n";
				cout << "Wybierz przedmiot (-1, aby anulowaæ): ";

				cin >> choice;

				while (cin.fail() || choice > merchantInv.size() || choice < -1) {
					system("cls");

					cout << "B³êdny zakres!" << "\n";
					cin.clear();
					cin.ignore();

					cout << "Kasa: " << graczkasa() << "\n";
					cout << "Wybierz przedmiot (-1, aby wyjœæ): ";
					cin >> choice;
				}
				cin.ignore();

				if (choice == -1) {
					cout << ">>>Cofaniecie<<<" << endl;
				}
				else if (graczkasa() >= merchantInv[choice].getBuyValue()) {
					graczodekasa(merchantInv[choice].getBuyValue());
					addItem(merchantInv[choice]);

					cout << "Kupi³eœ przedmiot: " << merchantInv[choice].getName() << " -" << merchantInv[choice].getBuyValue() << "\n";

					merchantInv.removeItem(choice);
				}
				else {
					cout << "Nie staæ Ciê na to!" << endl;
				}

				break;
			default:
				break;
			}
			Czekanie();
		}
	}

	if (nrbudynku == 7) {
		cout << loadekwipunek(true) << endl;

		cout << "= SELL MENU =" << endl << endl;
		cout << " - Kasa: " << graczkasa() << endl << endl;

		if (getInventorySize() > 0) {
			cout << "Kasa: " << graczkasa() << endl;
			cout << "Choice of item (-1 to cancel): ";

			cin >> choice;

			while (cin.fail() || choice > getInventorySize() || choice < -1)
			{
				system("cls");

				cout << "B³êdny zakres!" << endl;
				cin.clear();
				cin.ignore();

				cout << "Kasa: " << graczkasa() << "\n";
				cout << "Wybierz przedmiot (-1, aby anulowaæ): ";
				cin >> choice;
			}

			cin.ignore(100, '\n');
			cout << "\n";

			if (choice == -1) {
				cout << ">>>Cofaniecie<<<" << endl;
			}
			else {
				graczdodkasa(getItem(choice).getSellValue());

				cout << "Sprzedano przedmiot" << endl;
				cout << "Zarobiono: " << getItem(choice).getSellValue() << "!" << endl << endl;
				usunprzedmiot(choice);
			}
		}
		else {
			cout << "Pusty ekwipunek" << endl;
		}
	}
	cout << "Wychodzisz ze sklepu" << endl << endl;
}