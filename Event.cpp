#include "Event.h"
int Event::DuzyLos = 18;
int Event::MalyLos = 4;

void Event::LosEvent(Bohater &bohater, Potwory &przeciwnik){
	int i = rand() % DuzyLos + 1;
	switch (i){
	case 1:
		system("cls");
		cout << "Znalaz�e� po drodz� goblina, lecz uciek� na Tw�j widok" << endl << endl;
		break;

	case 2:
		system("cls");
		cout << "Bohater przeszed� si� bez przyg�d" << endl << endl;
		break;

	case 3:
		this->Walka(bohater, przeciwnik);
		break;

	case 4:
		system("cls");
		cout << "Znalaz�e� le��c� na �cie�ce monet�!" << endl << endl;
		bohater.graczdodkasa(1);
		break;

	case 5:
		system("cls");
		cout << "Podr�uj�c, spotka�e� m�drca. \n\nAby kontynuowa� w�dr�wk�, musisz odpowiedzie� na jego pytanie. \n\nJe�eli odpowiesz �le, b�dziesz musia� zap�aci�." << endl << endl;
		Czekanie();
		this->Wydarzenie(bohater);
		break;

	case 6:
		this->Walka(bohater, przeciwnik);
		break;

	case 7:
		system("cls");
		cout << "Podczas podr�y znalaz�e� magiczne, gadaj�ce drzewo blokuj�ce Ci drog�. \n\nAby kontynuowa� w�dr�wk�, musisz odpowiedzie� na jego pytanie. \n\nJe�eli odpowiesz �le, b�dziesz musia� zap�aci�." << endl << endl;
		Czekanie();
		this->Wydarzenie(bohater);
		break;

	case 8:
		system("cls");
		cout << "Znalaz�e� star�, magiczn� studnie!" << endl << endl;
		bohater.graczdodmagia(1);
		break;

	case 9:
		this->Walka(bohater, przeciwnik);
		break;

	case 10:
		system("cls");
		cout << "Znalaz�e� w skrzynce czarnego kota, trafia na Ciebie nieszcz�cie!" << endl;
		bohater.graczodemagia(bohater.graczmagia());
		if (bohater.graczkasa() <= 0) bohater.graczzeromagia();
		break;

	case 11:
		system("cls");
		cout << "Znalaz�e� sakw� ze z�otymi monetami!" << endl;
		bohater.graczdodkasa(10);
		break;

	case 12:
		this->Walka(bohater, przeciwnik);
		break;

	case 13:
		system("cls");
		cout << "Napadli na Ciebie zb�je, zadali Ci obra�enia, ale uciek�e�" << endl;
		bohater.graczodekasa(bohater.graczkasa());
		if (bohater.graczkasa() <= 0) bohater.graczzerokasa();
		break;

	case 14:
		system("cls");
		cout << "Przechodz�c przez las, widzisz nadlatuj�ce komety\n\nNie widzisz s�o�ca, wi�c nie trafiaj� w Ciebie" << endl;
		break;

	case 15:
		this->Walka(bohater, przeciwnik);
		break;

	case 16:
		system("cls");
		cout << "Przechodz�c przez las, widzisz czarnoksi�nika rzucaj�cy czary na kr�liki\n\nUczysz si� od niego jego techniki rzucania magii" << endl;
		bohater.graczdodmagia(3);
		break;

	case 17:
		system("cls");
		cout << "Znalaz�e� legion ork�w atakuj�cych najbli�sz� wiosk�, jest ich zbyt du�o, wi�c uciekasz" << endl << endl;
		break;

	case 18:
		this->Walka(bohater, przeciwnik);
		break;

	default:
		break;
	}
}

void Event::LosMalyEventSpanie(Bohater &bohater) {
	int i = rand() % MalyLos + 1;
	switch (i) {
	case 1:
		cout << "Wyspa�e� si� rze�ko" << endl;
		bohater.wyspanie();
		break;
	case 2:
		cout << "Nie znalaz�e� dobrego miejsca na spanie: -5hp" << endl;
		bohater.zlespanie();
		break;
	case 3:
		system("cls");
		cout << "Podczas snu ograbiono Ci�, ale zd��y�e� unikn�� pe�nej kradzie�y" << endl;
		bohater.graczodekasa(5);
		bohater.graczodekasa(bohater.graczpoziom());
		if (bohater.graczkasa() <= 0) bohater.graczzerokasa();
		break;
	case 4:
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
	Kolory kolor;
	system("cls");
	kolor.red();
	cout << "||======================================================||" << endl;
	cout << "||\t\t\t\t\t\t\t||" << endl;
	cout << "||\t "; kolor.blue(); cout << "Spotykasz potwora po swojej drodze!"; kolor.red(); cout << "\t\t|| " << endl;
	cout << "||\t\t\t\t\t\t\t||" << endl;
	cout << "||======================================================||" << endl << endl;
	cout << endl << "" << endl;
	InfoPrze(przeciwnik);
	Czekanie();

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
			kolor.blue();  cout << ">>>>>"; kolor.gold(); cout << "Tura gracza"; kolor.blue(); cout << "<<<<< " << endl;
			Czekanie();
			MenuWojny(bohater);
			cin >> wybor;
			while (cin.fail() || wybor > 2 || wybor < 0){
				kolor.red();  cout << "Z�y wyb�r, wybierz jeszcze raz!" << endl << endl;
				Czekanie();
				MenuWojny(bohater);
				cin >> wybor;
			}
			Czekanie();

			switch (wybor){
			case 0: //Ucieczka
				ucieczka = true;
				bohater.graczodekasa(przeciwnik.pmaxdmg());
				if (bohater.graczkasa() <= 0) bohater.graczzerokasa();
				break;

			case 1: //Atak
				InfoPrze(przeciwnik);

				SzansaPrzeciwnika = (int)( przeciwnik.pobrona() + przeciwnik.pmaxdmg() + przeciwnik.plvl());
				SzansaGracza = (int)(bohater.graczdmg() + (int)(bohater.graczzrecznosc() * 1.5) + bohater.graczmagia() * 2);
				LosGracza = rand() % SzansaGracza + 1;
				LosPrzeciwnika = rand() % SzansaPrzeciwnika + 1;

				kolor.blue(); cout << "\nSzansa gracza: ";
				kolor.green(); cout << SzansaGracza;
				kolor.blue();  cout << "\nLos Gracza : ";
				kolor.green(); cout << LosGracza << endl << endl;
				kolor.blue(); cout << "Szansa przeciwnika: ";
				kolor.green(); cout << SzansaPrzeciwnika;
				kolor.blue(); cout << "\nLos Przeciwnika: ";
				kolor.green(); cout << LosPrzeciwnika << endl << endl;
				
				if (LosGracza > LosPrzeciwnika) { //Trafienie w przeciwnika
					kolor.gold(); cout << "Trafiono! " << endl << endl;
					damage = bohater.graczdmg();
					kolor.blue(); cout << "Zadano: ";
					kolor.green(); cout << damage;
					kolor.blue(); cout << "!" << endl;
					przeciwnik.Obrazenia(damage);
					if (!przeciwnik.pzyje()){
						cout << "Przeciwnik pokonany!" << endl << endl;
						ZdobExp = przeciwnik.pexp() + 30;
						bohater.graczdodexp(ZdobExp);
						ZdobKasa = (rand() % przeciwnik.plvl() * 10 + 1) + 20;
						bohater.graczdodkasa(ZdobKasa);
						kolor.blue(); cout << "Zdobyto exp: ";
						kolor.green(); cout << ZdobExp;
						kolor.blue(); cout << "!" << endl;
						kolor.blue(); cout << "Zdobyto kasy: ";
						kolor.green(); cout << ZdobKasa;
						kolor.blue(); cout << "!" << endl << endl;
						PorazkaPrzeciwnika = true;
					}
				}
				else { kolor.gold(); cout << "\n\nTrafienie nie udane!" << endl << endl; } //Unik
				break;

			case 2: //Obrona
				if (leczenie == 3) {
					system("cls");
					kolor.green();
					cout << "Zosta�e� uleczony!" << endl;
					bohater.wyspanie();
					leczenie = 0;
					Czekanie();
				} else {
					system("cls");
					kolor.blue();
					cout << "Ilo�� tur do uleczenia: ";
					kolor.gold(); cout << 3 - leczenie << endl << endl;
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
			int dmgpotwora = rand() % (przeciwnik.pmaxdmg() * 3) + przeciwnik.pmindmg();
			kolor.blue();  cout << ">>>>>"; kolor.gold(); cout << "Tura przeciwnika"; kolor.blue(); cout << "<<<<< " << endl;
			Czekanie();
			
			SzansaPrzeciwnika = (int)dmgpotwora;
			SzansaGracza = (int)(bohater.graczobrona() + (int)(bohater.graczszczescie()*3));
			LosGracza = rand() % SzansaGracza + 1;
			LosPrzeciwnika = rand() % SzansaPrzeciwnika + 1;

			kolor.blue(); cout << "\nSzansa gracza: ";
			kolor.green(); cout << SzansaGracza;
			kolor.blue();  cout << "\nLos Gracza : ";
			kolor.green(); cout << LosGracza << endl << endl;
			kolor.blue(); cout << "Szansa przeciwnika: ";
			kolor.green(); cout << SzansaPrzeciwnika;
			kolor.blue(); cout << "\nLos Przeciwnika: ";
			kolor.green(); cout << LosPrzeciwnika << endl << endl;

			if (LosGracza < LosPrzeciwnika) { //Trafienie
				kolor.gold();
				cout << "Trafienie! " << endl << endl;

				damage = dmgpotwora;
				bohater.GraczObrazenia(damage);
				kolor.blue();cout << "Zadano: ";
				kolor.green(); cout << damage;
				kolor.blue(); cout << "!" << endl;

				kolor.blue(); cout << "HP: ";
				kolor.green(); cout << bohater.graczhp() << " / " << bohater.graczhpmax() << endl << endl;

				if (!bohater.graczgra()){
					kolor.red();
					cout << "Twoja posta� umar�a!" << endl;
					PorazkaGracza = true;
					Czekanie();
				}
			}
			else { kolor.gold();  cout << "\n\nUnik!" << endl; }//Unik
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
	Kolory kolor;
	kolor.green();
	cout << endl << "Czekanie na potwierdzenie..."<<endl;
	cin.clear();
	cin.ignore();
	system("cls");
}

void Event::InfoPrze(Potwory& przeciwnik) {
	Kolory kolor;
	kolor.blue(); cout << "Nazwa: ";
	kolor.green(); cout << przeciwnik.pnazwa();
	kolor.red(); cout << " - ";
	kolor.blue(); cout << "Poziom: ";
	kolor.green(); cout << przeciwnik.plvl();
	kolor.red(); cout << " - ";
	kolor.blue(); cout << "HP: ";
	kolor.green(); cout << przeciwnik.php() << " - " << przeciwnik.pmaxhp();
	kolor.red(); cout << " - ";
	kolor.blue(); cout << "Obrona: ";
	kolor.green(); cout << przeciwnik.pobrona();
	kolor.red(); cout << " - ";
	kolor.blue(); cout << "Kasa: ";
	kolor.green(); cout << przeciwnik.pkasa();
	kolor.red(); cout << " - ";
	kolor.blue(); cout << "Si�a przeciwnika: ";
	kolor.green(); cout << przeciwnik.pmindmg() << " - " << przeciwnik.pmaxdmg() << endl;
	return;
}

void Event::MenuWojny(Bohater &bohater) {
	Kolory kolor;
	kolor.gold(); cout << ">>>>>";
	kolor.red(); cout << "MENU WOJNY";
	kolor.gold(); cout << "<<<<<" << endl << endl;
	kolor.blue(); cout << "HP: ";
	kolor.green(); cout << bohater.graczhp() << " / " << bohater.graczhpmax() << endl << endl;
	kolor.blue();  cout << "0:";
	kolor.green(); cout <<" Ucieczka" << endl;
	kolor.blue(); cout << "1: ";
	kolor.green(); cout<<"Atak" << endl;
	kolor.blue(); cout << "2:";
	kolor.green(); cout << " Obrona" << endl << endl;
	kolor.gold(); cout << "Wybor: ";
	return;
}

void Event::Wydarzenie(Bohater &bohater){
	Kolory kolor;
	bool wygrana = false;
	int wybor = 0;
	int szanse = (int)(rand() % 3 + 1);
	int wygranyexp = (bohater.graczpoziom() * (rand() % 6 + 1)) + 80;
	int wygranakasa = (bohater.graczpoziom() * (rand() % 6 + 1)) + 40;
	int randomizer = rand() % 10 + 1;
	string temps = to_string(randomizer) + ".txt";
	string temp= "./PlikiGry/Zagadki/" + temps;
	Zagadka zagadka(temp);

	while (!wygrana && szanse > 0){
		kolor.blue(); cout << "Twoje szanse: ";
		kolor.green(); cout << szanse;
		kolor.blue(); cout << ", b�d� uwa�ny!" << endl << endl;
		Czekanie();
		szanse--;
		cout << zagadka.getString() << endl;
		kolor.gold(); cout << "\nTwoja odpowied� to: ";
		cin >> wybor;
		cin.clear();
		cin.ignore();
		cout << endl;
		while (cin.fail()) {
			kolor.red(); cout << "Wpisz poprawn� cyfr� z zakresu!" << endl;
			kolor.green(); cout << "\nTwoja odpowied� to: ";
			cin >> wybor;
			cin.clear();
			cin.ignore();
		}
		cout << endl;
		if (zagadka.PrawOdp() == wybor){
			wygrana = true;
			bohater.graczdodexp(wygranyexp);
			bohater.graczdodkasa(wygranakasa);
			kolor.blue(); cout << "Zdobyto exp: ";
			kolor.green(); cout << wygranyexp;
			kolor.blue(); cout << "!" << endl;
			kolor.blue(); cout << "Zdobyto kasy: ";
			kolor.green(); cout << wygranakasa;
			kolor.blue(); cout << "!" << endl << endl;
		}
	}
	
	if (wygrana){
		kolor.blue(); cout << "Czy wiesz, �e: ";
		kolor.green(); cout << zagadka.Ciekawosc();
		kolor.blue(); cout << "?" << endl << endl;
		kolor.gold(); cout << "Gratulacje, zagadka rozwi�zana!" << endl;
	} else { 
		kolor.red(); cout << "Nie uda�o Ci si� rozwi�za� zagadki, skarb ukryto, a sam musia�e� za to zap�aci�!" << endl; 
		bohater.graczodekasa(bohater.graczpoziom());
		if (bohater.graczkasa() <= 0) bohater.graczzerokasa();
	}

	cout << endl;
	Czekanie();
}