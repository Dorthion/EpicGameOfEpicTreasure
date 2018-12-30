#include "Event.h"
int Event::nrOfEvents = 3;

Event::Event(){
}

Event::~Event(){
}

void Event::LosEvent(Bohater &character, Potwory &enemy){
	int i = rand() % Event::nrOfEvents;
	//Potwory enemy;
	switch (i){
	case 0:
		//Enemy encounter
		this->enemyEncouter(character, enemy);
		break;
	case 1:
		//Puzzle
		//this->puzzleEncouter(character);
		cout << "Wydarzenie losowe, puzzle ktore omijam" << endl;
		break;
	case 2:
		system("cls");
		cout << "Bohater przeszed³ siê bez przygód" << endl;
		break;
	case 3:
		system("cls");
		cout << "Znalaz³eœ le¿¹c¹ na œcie¿ce monetê!" << endl;


	default:
		break;
	}
}

void Event::LosMalyEvent(Bohater &character) {
	int i = rand() % Event::nrOfEvents;
	switch (i) {
	case 0:
		cout << "Wyspa³eœ siê rzeœko" << endl;
		break;
	case 1:
		cout << "Nie znalaz³eœ dobrego miejsca na spanie: -5hp" << endl;
		character.zlespanie();
		break;
	case 2:
		system("cls");
		cout << "Bohater przeszed³ siê bez przygód" << endl;
		break;
	case 3:
		system("cls");
		cout << "Znalaz³eœ le¿¹c¹ na œcie¿ce monetê!" << endl;


	default:
		break;
	}
}

void Event::enemyEncouter(Bohater &character, Potwory& enemies){
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
	int combatTotal = 0;
	int combatRollPlayer = 0;
	int combatRollEnemy = 0;
	//G£ÓWNA PÊTLA WHILE CO MIA£A DZIA£AÆ
	while (!escape && !playerDefeated && !enemiesDefeated){
		if (playerTurn && !playerDefeated){
			system("cls");
			cout << ">>>>>Tura gracza<<<<<" << endl;
			Czekanie();
			cout << ">>>>>MENU WOJNY<<<<<" << endl << endl;
			cout << "HP: " << character.graczhp() << " / " << character.graczhpmax() << endl << endl;
			cout << "0: Escape" << endl;
			cout << "1: Attack" << endl;
			cout << "2: Defend" << endl << endl;
			cout << "Wybor: ";
			cin >> wybor;
			while (cin.fail() || wybor > 2 || wybor < 0){
				cout << "Faulty input!" << endl;
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
				break;

			case 1://Atak
				cout << "Nazwa: " << enemies.getName() << " - " <<
					"Poziom: " << enemies.plvl() << " - " <<
					"HP: " << enemies.php() << "/" << enemies.pmaxhp() << " - " <<
					"Obrona: " << enemies.pobrona() << " - " <<
					"Kasa: " << enemies.pkasa() << " - " <<
					"Damage: " << enemies.pmindmg() << " - " << enemies.pmaxdmg() << endl;
				//Attack roll
				combatTotal = enemies.pobrona();
				enemyTotal =( enemies.pobrona() + enemies.pmaxdmg() + enemies.plvl()) / (int)combatTotal;
				playerTotal = (character.graczdmg() + character.graczmagia()) / (int)combatTotal;
				combatRollPlayer = rand() % playerTotal + 1;
				combatRollEnemy = rand() % enemyTotal + 1;
				
				cout << "Combat total: " << combatTotal << "\n";
				cout << "Enemy percent: " << enemyTotal << "\n";
				cout << "Player percent: " << playerTotal << "\n\n";
				cout << "Player roll: " << combatRollPlayer << "\n";
				cout << "Enemy roll: " << combatRollEnemy << "\n\n";

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
						cout << "EXP GAINED: " << gainExp << "\n";
						cout << "GOLD GAINED: " << gainGold << "\n\n";
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
			combatTotal = enemies.pmaxdmg();
			enemyTotal = (int)dmgpotwora;
			playerTotal = (int)((character.graczobrona() + character.graczszczescie()) / combatTotal);
			combatRollPlayer = rand() % playerTotal + 1;
			combatRollEnemy = rand() % enemyTotal + 1;

			cout << "Combat total: " << combatTotal << "\n";
			cout << "Enemy percent: " << enemyTotal << "\n";
			cout << "Player percent: " << playerTotal << "\n\n";
			cout << "Player roll: " << combatRollPlayer << "\n";
			cout << "Enemy roll: " << combatRollEnemy << "\n\n";

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