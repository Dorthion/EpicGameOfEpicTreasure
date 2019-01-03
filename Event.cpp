#include "Event.h"
int Event::DuzyLos = 13;
int Event::MalyLos = 3;
Event::Event(){
}

Event::~Event(){
}

void Event::LosEvent(Bohater &bohater, Potwory &przeciwnik){
	int i = rand() % DuzyLos;
	switch (i){
	case 0:
		this->Walka(bohater, przeciwnik);
		break;
	case 1:
		system("cls");
		cout << "Znalaz�e� po drodz� goblina, lecz uciek� na Tw�j widok" << endl << endl;
		break;

	case 2:
		system("cls");
		cout << "Bohater przeszed� si� bez przyg�d" << endl << endl;
		break;

	case 3:
		system("cls");
		cout << "Znalaz�e� le��c� na �cie�ce monet�!" << endl << endl;
		bohater.graczdodkasa(1);
		break;

	case 4:
		system("cls");
		cout << "Podr�uj�c, spotka�e� m�drca. \n\nAby kontynuowa� w�dr�wk�, musisz odpowiedzie� na jego pytanie. \n\nJe�eli odpowiesz �le, b�dziesz musia� zap�aci�." << endl << endl;
		Czekanie();
		this->Wydarzenie(bohater);
		break;

	case 5:
		system("cls");
		cout << "Podczas podr�y znalaz�e� magiczne, gadaj�ce drzewo blokuj�ce Ci drog�. \n\nAby kontynuowa� w�dr�wk�, musisz odpowiedzie� na jego pytanie. \n\nJe�eli odpowiesz �le, b�dziesz musia� zap�aci�." << endl << endl;
		Czekanie();
		this->Wydarzenie(bohater);
		break;

	case 6:
		system("cls");
		cout << "Znalaz�e� star�, magiczn� studnie!" << endl << endl;
		bohater.graczdodmagia(1);
		break;

	case 7:
		system("cls");
		cout << "Znalaz�e� w skrzynce czarnego kota, trafia na Ciebie nieszcz�cie!" << endl;
		bohater.graczodemagia(bohater.graczmagia());
		if (bohater.graczkasa() <= 0) bohater.graczzeromagia();
		break;

	case 8:
		system("cls");
		cout << "Znalaz�e� sakw� ze z�otymi monetami!" << endl;
		bohater.graczdodkasa(10);
		break;

	case 9:
		system("cls");
		cout << "Napadli na Ciebie zb�je, zadali Ci obra�enia, ale uciek�e�" << endl;
		bohater.graczodekasa(bohater.graczkasa());
		if (bohater.graczkasa() <= 0) bohater.graczzerokasa();
		break;

	case 10:
		system("cls");
		cout << "Przechodz�c przez las, widzisz nadlatuj�ce komety\n\nNie widzisz s�o�ca, wi�c nie trafiaj� w Ciebie" << endl;
		break;

	case 11:
		system("cls");
		cout << "Przechodz�c przez las, widzisz czarnoksi�nika rzucaj�cy czary na kr�liki\n\nUczysz si� od niego jego techniki rzucania magii" << endl;
		bohater.graczdodmagia(3);
		break;

	case 12:
		system("cls");
		cout << "Znalaz�e� legion ork�w atakuj�cych najbli�sz� wiosk�, jest ich zbyt du�o, wi�c uciekasz" << endl << endl;
		break;
	default:
		break;
	}
}

void Event::LosMalyEventSpanie(Bohater &bohater) {
	int i = rand() % MalyLos;
	switch (i) {
	case 0:
		cout << "Wyspa�e� si� rze�ko" << endl;
		bohater.wyspanie();
		break;
	case 1:
		cout << "Nie znalaz�e� dobrego miejsca na spanie: -5hp" << endl;
		bohater.zlespanie();
		break;
	case 2:
		system("cls");
		cout << "Podczas snu ograbiono Ci�, ale zd��y�e� unikn�� pe�nej kradzie�y" << endl;
		bohater.graczodekasa(5);
		bohater.graczodekasa(bohater.graczpoziom());
		if (bohater.graczkasa() <= 0) bohater.graczzerokasa();
		break;
	case 3:
		system("cls");
		cout << "Tej nocy przelecia�a nad Tob� nieszcz�liwa kometa: -5pkt. magii" << endl;
		bohater.graczodemagia(5);
		if (bohater.graczkasa() <= 0) bohater.graczzeromagia();
		break;

	default:
		break;
	}
}

void Event::Walka(Bohater &bohater, Potwory& przeciwnik){
	cout << endl << "Spotykasz potwora po twojej drodze!" << endl;
	cout << "Nazwa: " << przeciwnik.getName() << " - " <<
		"Poziom: " << przeciwnik.plvl() << " - " <<
		"HP: " << przeciwnik.php() << "/" << przeciwnik.pmaxhp() << " - " <<
		"Obrona: " << przeciwnik.pobrona() << " - " <<
		"Kasa: " << przeciwnik.pkasa() << " - " <<
		"Damage: " << przeciwnik.pmindmg() << " - " << przeciwnik.pmaxdmg() << endl;

	//Zmienne
	bool RuchGracza = false;
	bool ucieczka = false;
	bool PorazkaGracza = false;
	bool PorazkaPrzeciwnika = false;
	int wybor = 0;
	int moneta = rand() % 2 + 1;
	int damage = 0;
	int ZdobExp = 0;
	int ZdobKasa = 0;
	int SzansaGracza = 0;
	int SzansaPrzeciwnika = 0;
	int leczenie = 0;
	int LosGracza = 0;
	int LosPrzeciwnika = 0;

	//Losuj ture
	if (moneta == 1)
		RuchGracza = true;
	else
		RuchGracza = false;

	while (!ucieczka && !PorazkaGracza && !PorazkaPrzeciwnika){
		if (RuchGracza && !PorazkaGracza){
			system("cls");
			cout << ">>>>>Tura gracza<<<<<" << endl;
			Czekanie();
			cout << ">>>>>MENU WOJNY<<<<<" << endl << endl;
			cout << "HP: " << bohater.graczhp() << " / " << bohater.graczhpmax() << endl << endl;
			cout << "0: Ucieczka" << endl;
			cout << "1: Atak" << endl;
			cout << "2: Obrona" << endl << endl;
			cout << "Wybor: ";
			cin >> wybor;
			while (cin.fail() || wybor > 2 || wybor < 0){
				cout << "Z�y wyb�r, wybierz jeszcze raz!" << endl;
				Czekanie();
				cout << ">>>>>MENU WOJNY<<<<<" << endl << endl;
				cout << "0: Ucieczka" << endl;
				cout << "1: Atak" << endl;
				cout << "2: Obrona" << endl << endl;
				cout << "Wybor: ";
				cin >> wybor;
			}
			Czekanie();

			switch (wybor){
			case 0: //Ucieczka
				ucieczka = true;
				bohater.graczodekasa(przeciwnik.pmaxdmg());
				if (bohater.graczkasa() <= 0) bohater.graczzerokasa();
				break;

			case 1://Atak
				cout << "Nazwa: " << przeciwnik.getName() << " - " <<
					"Poziom: " << przeciwnik.plvl() << " - " <<
					"HP: " << przeciwnik.php() << "/" << przeciwnik.pmaxhp() << " - " <<
					"Obrona: " << przeciwnik.pobrona() << " - " <<
					"Kasa: " << przeciwnik.pkasa() << " - " <<
					"Damage: " << przeciwnik.pmindmg() << " - " << przeciwnik.pmaxdmg() << endl;
				//Attack roll
				SzansaPrzeciwnika = (int)( przeciwnik.pobrona() + przeciwnik.pmaxdmg() + przeciwnik.plvl());
				SzansaGracza = (int)(bohater.graczdmg() + bohater.graczzrecznosc() * 2 + bohater.graczmagia() * 2);
				LosGracza = rand() % SzansaGracza + 1;
				LosPrzeciwnika = rand() % SzansaPrzeciwnika + 1;

				cout << "\nSzansa gracza: " << SzansaGracza <<"\nLos Gracza : " << LosGracza << endl << endl;
				cout << "Szansa przeciwnika: " << SzansaPrzeciwnika << "\nLos Przeciwnika: " << LosPrzeciwnika;
				
				if (LosGracza > LosPrzeciwnika) { //Hit
					cout << "Trafiono! " << endl;
					damage = bohater.graczdmg();
					cout << damage;
					przeciwnik.Obrazenia(damage);
					cout << "Zadano: " << damage << "!" << endl;
					if (!przeciwnik.pzyje()){
						cout << "Przeciwnik pokonany!" << endl;
						ZdobExp = przeciwnik.pexp();
						bohater.graczdodexp(ZdobExp);
						ZdobKasa = rand() % przeciwnik.plvl() * 10 + 1;
						bohater.graczdodkasa(ZdobKasa);
						cout << "Zdobyto exp: " << ZdobExp << "\n";
						cout << "Zdobyto kasy: " << ZdobKasa << "\n\n";
						PorazkaPrzeciwnika = true;
					}
				} else { cout << "\n\nTrafienie nie udane!" << endl << endl; } //Unik
				break;

			case 2: //Obrona
				if (leczenie == 3) {
					system("cls");
					cout << "Zosta�e� uleczony!" << endl;
					bohater.wyspanie();
					leczenie = 0;
					Czekanie();
				} else {
					system("cls");
					cout << "Ilo�� tur do uleczenia: " << 3 - leczenie << endl << endl;
					leczenie++;
					Czekanie();
				}
				break;

			default:
				break;
			}

			//Koniec tury - Tura przeciwnika
			RuchGracza = false;
		} 
		if (!RuchGracza && !PorazkaGracza && !ucieczka && !PorazkaPrzeciwnika){
			int dmgpotwora = rand() % przeciwnik.pmaxdmg() + przeciwnik.pmindmg();
			cout << ">>>>>Tura przeciwnika<<<<<" << endl;
			Czekanie();
			
			SzansaPrzeciwnika = (int)dmgpotwora;
			SzansaGracza = (int)(bohater.graczobrona() + bohater.graczszczescie()*3);
			LosGracza = rand() % SzansaGracza + 1;
			LosPrzeciwnika = rand() % SzansaPrzeciwnika + 1;

			cout << "\nSzansa gracza: " << SzansaGracza << "\nLos Gracza : " << LosGracza << endl << endl;
			cout << "Szansa przeciwnika: " << SzansaPrzeciwnika << "\nLos Przeciwnika: " << LosPrzeciwnika << endl << endl;

			if (LosGracza < LosPrzeciwnika) { //Trafienie
				cout << "Trafienie! " << "\n\n";

				damage = dmgpotwora;
				bohater.GraczObrazenia(damage);

				cout << "Damage: " << damage << "!" << endl;
				cout << "HP: " << bohater.graczhp() << " / " << bohater.graczhpmax() << endl << endl;
				if (!bohater.graczgra()){
					cout << "Twoja posta� umar�a!" << endl;
					PorazkaGracza = true;
				}
			} else { cout << "\n\nUnik!"<<endl; }//Unik
			//Koniec tury - Tura gracza
			RuchGracza = true;
			Czekanie();
		}
		//Warunki ko�ca gry
		if (!bohater.graczgra()){
			PorazkaGracza = true;
		}
		if (przeciwnik.pzyje()){
			PorazkaPrzeciwnika = false;
		}
	}
	Czekanie();
}

void Event::Czekanie() {
	cout << endl << "Czekanie na potwierdzenie..."<<endl;
	cin.clear();
	cin.ignore();
	system("cls");
}

void Event::Wydarzenie(Bohater &bohater){
	bool wygrana = false;
	int wybor = 0;
	int szanse = (int)(rand() % 3 + 1);
	int wygranyexp = (bohater.graczpoziom() * (rand() % 5 + 1));
	int wygranakasa = (bohater.graczpoziom() * (rand() % 5 + 1));
	int randomizer = rand() % 10 + 1;
	string what = to_string(randomizer) + ".txt";
	string temp= "Zagadki/" + what;
	Zagadka zagadka(temp);

	while (!wygrana && szanse > 0){
		cout << "Twoje szanse: " << szanse << ", b�d� uwa�ny!" << endl << endl;
		Czekanie();
		szanse--;
		cout << zagadka.getAsString() << endl;
		cout << "\nTwoja odpowied� to: ";
		cin >> wybor;
		cin.clear();
		cin.ignore();
		cout << endl;
		while (cin.fail()) {
			cout << "Wpisz poprawn� cyfr� z zakresu!" << endl;
			cout << "\nTwoja odpowied� to: ";
			cin >> wybor;
			cin.clear();
			cin.ignore();
		}
		cout << endl;
		if (zagadka.PrawOdp() == wybor){
			wygrana = true;
			bohater.graczdodexp(wygranyexp);
			bohater.graczdodkasa(wygranakasa);
			cout << "Zdoby�e� " << wygranyexp << " do�wiadczenia!" << endl;
			cout << "Zdoby�e� " << wygranakasa << " kasy!" << endl << endl;
		}
	}
	
	if (wygrana){
		cout << "Czy wiesz, �e: " << zagadka.Ciekawosc() << "?" << endl << endl;
		cout << "Gratulacje, zagadka rozwi�zana!" << endl;
	} else { 
		cout << "Nie uda�o Ci si� rozwi�za� zagadki, skarb ukryto, a sam musia�e� za to zap�aci�!" << endl; 
		bohater.graczodekasa(bohater.graczpoziom());
		if (bohater.graczkasa() <= 0) bohater.graczzerokasa();
	}

	cout << endl;
	Czekanie();
}