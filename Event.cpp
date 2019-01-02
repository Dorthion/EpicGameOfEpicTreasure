#include "Event.h"
int Event::nrOfEvents = 5;

Event::Event(){
}

Event::~Event(){
}

void Event::LosEvent(Bohater &bohater, Potwory &przeciwnik){
	int i = rand() % Event::nrOfEvents;
	//Potwory - enemy;
	switch (i){
	case 0:
		//Enemy encounter
		this->Walka(bohater, przeciwnik);
		break;
	case 1:
		//Puzzle
		//this->puzzleEncouter(character);
		system("cls");
		cout << "Wydarzenie losowe, puzzle ktore omijam" << endl;
		break;

	case 2:
		system("cls");
		cout << "Bohater przeszed³ siê bez przygód" << endl;
		break;

	case 3:
		system("cls");
		cout << "Znalaz³eœ le¿¹c¹ na œcie¿ce monetê!" << endl;
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
		cout << "Podczas podró¿y znalaz³eœ magiczne, gadaj¹ce drzewo blokuj¹ce Ci drogê. \n\nAby kontynuowaæ wêdrówkê, musisz odpowiedzieæ na jego pytanie. \n\nJe¿eli odpowiesz Ÿle, bêdziesz musia³ zap³aciæ." << endl;
		Czekanie();
		this->Wydarzenie(bohater);
		break;

	case 6:
		system("cls");
		cout << "Znalaz³eœ star¹, magiczn¹ studnie!" << endl;
		bohater.graczdodmagia(1);
		break;

	case 7:
		system("cls");
		cout << "Znalaz³eœ star¹, magiczn¹ studnie!" << endl;
		bohater.graczdodmagia(1);
		break;

	case 8:
		system("cls");
		cout << "Znalaz³eœ star¹, magiczn¹ studnie!" << endl;
		bohater.graczdodmagia(1);
		break;

	case 9:
		system("cls");
		cout << "Znalaz³eœ star¹, magiczn¹ studnie!" << endl;
		bohater.graczdodmagia(1);
		break;

	case 10:
		system("cls");
		cout << "Znalaz³eœ star¹, magiczn¹ studnie!" << endl;
		bohater.graczdodmagia(1);
		break;

	case 11:
		system("cls");
		cout << "Znalaz³eœ star¹, magiczn¹ studnie!" << endl;
		bohater.graczdodmagia(1);

	case 12:
		system("cls");
		cout << "Znalaz³eœ star¹, magiczn¹ studnie!" << endl;
		bohater.graczdodmagia(1);
		break;
	default:
		break;
	}
}

void Event::LosMalyEventSpanie(Bohater &bohater) {
	int i = rand() % Event::nrOfEvents;
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
		cout << "Podczas snu ograbiono Ciê, ale zd¹¿y³eœ unikn¹æ pe³nej kradzie¿y: -5 monet" << endl;
		bohater.graczodekasa(5);
		bohater.graczodekasa(bohater.graczpoziom());
		if (bohater.graczkasa() <= 0) bohater.graczzerokasa();
		break;
	case 3:
		system("cls");
		cout << "Tej nocy przelecia³a nad Tob¹ nieszczêœliwa kometa: -5pkt. magii" << endl;
		bohater.graczodemagia(5);
		bohater.graczodemagia(bohater.graczmagia());
		if (bohater.graczkasa() <= 0) bohater.graczzeromagia();
		break;

	default:
		break;
	}
}

void Event::Walka(Bohater &character, Potwory& enemies){
	cout << endl << "Spotykasz potwora po twojej drodze!" << endl;
	cout << "Nazwa: " << enemies.getName() << " - " <<
		"Poziom: " << enemies.plvl() << " - " <<
		"HP: " << enemies.php() << "/" << enemies.pmaxhp() << " - " <<
		"Obrona: " << enemies.pobrona() << " - " <<
		"Kasa: " << enemies.pkasa() << " - " <<
		"Damage: " << enemies.pmindmg() << " - " << enemies.pmaxdmg() << endl;
	//Zmienne 1
	bool playerTurn = false;
	int wybor = 0;
	int coinToss = rand() % 2 + 1;
	//Losuj ture
	if (coinToss == 1)
		playerTurn = true;
	else
		playerTurn = false;
	//Zmienne 2
	bool escape = false;
	bool playerDefeated = false;
	bool enemiesDefeated = false;
	//Zmienne 3
	int damage = 0;
	int gainExp = 0;
	int gainGold = 0;
	int playerTotal = 0;
	int enemyTotal = 0;
	//int combatTotal = 0;
	int combatRollPlayer = 0;
	int combatRollEnemy = 0;
	int tymczasowypancerz = 0;
	//G£ÓWNA PÊTLA WHILE CO MIA£A DZIA£AÆ
	while (!escape && !playerDefeated && !enemiesDefeated){
		if (playerTurn && !playerDefeated){
			system("cls");
			cout << ">>>>>Tura gracza<<<<<" << endl;
			Czekanie();
			cout << ">>>>>MENU WOJNY<<<<<" << endl << endl;
			cout << "HP: " << character.graczhp() << " / " << character.graczhpmax() << endl << endl;
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
				escape = true;
				character.graczodekasa(enemies.pmaxdmg());
				if (character.graczkasa() <= 0) character.graczzerokasa();
				break;

			case 1://Atak
				cout << "Nazwa: " << enemies.getName() << " - " <<
					"Poziom: " << enemies.plvl() << " - " <<
					"HP: " << enemies.php() << "/" << enemies.pmaxhp() << " - " <<
					"Obrona: " << enemies.pobrona() << " - " <<
					"Kasa: " << enemies.pkasa() << " - " <<
					"Damage: " << enemies.pmindmg() << " - " << enemies.pmaxdmg() << endl;
				//Attack roll
				enemyTotal = (int)( enemies.pobrona() + enemies.pmaxdmg() + enemies.plvl());
				playerTotal = (int)(character.graczdmg() + character.graczzrecznosc() * 2 + character.graczmagia() * 2);
				combatRollPlayer = rand() % playerTotal + 1;
				combatRollEnemy = rand() % enemyTotal + 1;

				cout << "\nSzansa gracza: " << playerTotal <<"\nLos Gracza : " << combatRollPlayer << endl << endl;
				cout << "Szansa przeciwnika: " << enemyTotal << "\nLos Przeciwnika: " << combatRollEnemy;
				
				if (combatRollPlayer > combatRollEnemy) { //Hit
					cout << "Trafiono! " << endl;
					damage = character.graczdmg();
					cout << damage;
					enemies.Obrazenia(damage);
					cout << "Zadano: " << damage << "!" << endl;
					if (!enemies.isAlive()){
						cout << "Przeciwnik pokonany!" << endl;
						gainExp = enemies.pexp();
						character.graczdodexp(gainExp);
						gainGold = rand() % enemies.plvl() * 10 + 1;
						character.graczdodkasa(gainGold);
						cout << "Zdobyto exp: " << gainExp << "\n";
						cout << "Zdobyto kasy: " << gainGold << "\n\n";
						enemiesDefeated = true;
					}
				}
				else { cout << "Trafienie nie udane!" << endl << endl; } //Unik
				break;

			case 2: //Obrona
				
				break;

			default:
				break;
			}

			//Koniec tury - Tura przeciwnika
			playerTurn = false;
		} 
		if (!playerTurn && !playerDefeated && !escape && !enemiesDefeated){
			int dmgpotwora = rand() % enemies.pmaxdmg() + enemies.pmindmg();
			cout << ">>>>>Tura przeciwnika<<<<<" << endl;//Enemy attack
			Czekanie();
			//Attack roll
			enemyTotal = (int)dmgpotwora;
			playerTotal = (int)(character.graczobrona() + character.graczszczescie()*3);
			combatRollPlayer = rand() % playerTotal + 1;
			combatRollEnemy = rand() % enemyTotal + 1;

			cout << "\nSzansa gracza: " << playerTotal << "\nLos Gracza : " << combatRollPlayer << endl << endl;
			cout << "Szansa przeciwnika: " << enemyTotal << "\nLos Przeciwnika: " << combatRollEnemy << endl << endl;

			if (combatRollPlayer < combatRollEnemy) { //Hit
				cout << "Trafienie! " << "\n\n";

				damage = dmgpotwora;
				character.GraczObrazenia(damage);

				cout << "Damage: " << damage << "!" << endl;
				cout << "HP: " << character.graczhp() << " / " << character.graczhpmax() << endl << endl;
				if (!character.graczgra()){
					cout << "Twoja postaæ umar³a!" << endl;
					playerDefeated = true;
				}
			} else { cout << "Unik!"<<endl; }//Unik
			//Koniec tury - Tura gracza
			playerTurn = true;
			Czekanie();
		}
		//Warunki koñca gry
		if (!character.graczgra()){
			playerDefeated = true;
		}
		if (enemies.isAlive()){
			enemiesDefeated = false;
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