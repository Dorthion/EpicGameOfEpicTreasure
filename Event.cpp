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
		cout << "Znalaz³eœ po drodzê goblina, lecz uciek³ na Twój widok" << endl << endl;
		break;

	case 2:
		system("cls");
		cout << "Bohater przeszed³ siê bez przygód" << endl << endl;
		break;

	case 3:
		system("cls");
		cout << "Znalaz³eœ le¿¹c¹ na œcie¿ce monetê!" << endl << endl;
		bohater.graczdodkasa(1);
		break;

	case 4:
		system("cls");
		cout << "Podró¿uj¹c, spotka³eœ mêdrca. \n\nAby kontynuowaæ wêdrówkê, musisz odpowiedzieæ na jego pytanie. \n\nJe¿eli odpowiesz Ÿle, bêdziesz musia³ zap³aciæ." << endl << endl;
		Czekanie();
		this->Wydarzenie(bohater);
		break;

	case 5:
		system("cls");
		cout << "Podczas podró¿y znalaz³eœ magiczne, gadaj¹ce drzewo blokuj¹ce Ci drogê. \n\nAby kontynuowaæ wêdrówkê, musisz odpowiedzieæ na jego pytanie. \n\nJe¿eli odpowiesz Ÿle, bêdziesz musia³ zap³aciæ." << endl << endl;
		Czekanie();
		this->Wydarzenie(bohater);
		break;

	case 6:
		system("cls");
		cout << "Znalaz³eœ star¹, magiczn¹ studnie!" << endl << endl;
		bohater.graczdodmagia(1);
		break;

	case 7:
		system("cls");
		cout << "Znalaz³eœ w skrzynce czarnego kota, trafia na Ciebie nieszczêœcie!" << endl;
		bohater.graczodemagia(bohater.graczmagia());
		if (bohater.graczkasa() <= 0) bohater.graczzeromagia();
		break;

	case 8:
		system("cls");
		cout << "Znalaz³eœ sakwê ze z³otymi monetami!" << endl;
		bohater.graczdodkasa(10);
		break;

	case 9:
		system("cls");
		cout << "Napadli na Ciebie zbóje, zadali Ci obra¿enia, ale uciek³eœ" << endl;
		bohater.graczodekasa(bohater.graczkasa());
		if (bohater.graczkasa() <= 0) bohater.graczzerokasa();
		break;

	case 10:
		system("cls");
		cout << "Przechodz¹c przez las, widzisz nadlatuj¹ce komety\n\nNie widzisz s³oñca, wiêc nie trafiaj¹ w Ciebie" << endl;
		break;

	case 11:
		system("cls");
		cout << "Przechodz¹c przez las, widzisz czarnoksiê¿nika rzucaj¹cy czary na króliki\n\nUczysz siê od niego jego techniki rzucania magii" << endl;
		bohater.graczdodmagia(3);
		break;

	case 12:
		system("cls");
		cout << "Znalaz³eœ legion orków atakuj¹cych najbli¿sz¹ wioskê, jest ich zbyt du¿o, wiêc uciekasz" << endl << endl;
		break;
	default:
		break;
	}
}

void Event::LosMalyEventSpanie(Bohater &bohater) {
	int i = rand() % MalyLos;
	switch (i) {
	case 0:
		cout << "Wyspa³eœ siê rzeœko" << endl;
		bohater.wyspanie();
		break;
	case 1:
		cout << "Nie znalaz³eœ dobrego miejsca na spanie: -5hp" << endl;
		bohater.zlespanie();
		break;
	case 2:
		system("cls");
		cout << "Podczas snu ograbiono Ciê, ale zd¹¿y³eœ unikn¹æ pe³nej kradzie¿y" << endl;
		bohater.graczodekasa(5);
		bohater.graczodekasa(bohater.graczpoziom());
		if (bohater.graczkasa() <= 0) bohater.graczzerokasa();
		break;
	case 3:
		system("cls");
		cout << "Tej nocy przelecia³a nad Tob¹ nieszczêœliwa kometa: -5pkt. magii" << endl;
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
				cout << "Z³y wybór, wybierz jeszcze raz!" << endl;
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
					cout << "Zosta³eœ uleczony!" << endl;
					bohater.wyspanie();
					leczenie = 0;
					Czekanie();
				} else {
					system("cls");
					cout << "Iloœæ tur do uleczenia: " << 3 - leczenie << endl << endl;
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
					cout << "Twoja postaæ umar³a!" << endl;
					PorazkaGracza = true;
				}
			} else { cout << "\n\nUnik!"<<endl; }//Unik
			//Koniec tury - Tura gracza
			RuchGracza = true;
			Czekanie();
		}
		//Warunki koñca gry
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
		cout << "Twoje szanse: " << szanse << ", b¹dŸ uwa¿ny!" << endl << endl;
		Czekanie();
		szanse--;
		cout << zagadka.getAsString() << endl;
		cout << "\nTwoja odpowiedŸ to: ";
		cin >> wybor;
		cin.clear();
		cin.ignore();
		cout << endl;
		while (cin.fail()) {
			cout << "Wpisz poprawn¹ cyfrê z zakresu!" << endl;
			cout << "\nTwoja odpowiedŸ to: ";
			cin >> wybor;
			cin.clear();
			cin.ignore();
		}
		cout << endl;
		if (zagadka.PrawOdp() == wybor){
			wygrana = true;
			bohater.graczdodexp(wygranyexp);
			bohater.graczdodkasa(wygranakasa);
			cout << "Zdoby³eœ " << wygranyexp << " doœwiadczenia!" << endl;
			cout << "Zdoby³eœ " << wygranakasa << " kasy!" << endl << endl;
		}
	}
	
	if (wygrana){
		cout << "Czy wiesz, ¿e: " << zagadka.Ciekawosc() << "?" << endl << endl;
		cout << "Gratulacje, zagadka rozwi¹zana!" << endl;
	} else { 
		cout << "Nie uda³o Ci siê rozwi¹zaæ zagadki, skarb ukryto, a sam musia³eœ za to zap³aciæ!" << endl; 
		bohater.graczodekasa(bohater.graczpoziom());
		if (bohater.graczkasa() <= 0) bohater.graczzerokasa();
	}

	cout << endl;
	Czekanie();
}