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
	//Zmienne 1
	bool playerTurn = false;
	int choice = 0;
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
			cout << "= PLAYER TURN =" << "\n\n";
			cout << "Continue..." << "\n\n";
			cin.get();
			system("CLS");

			cout << "= BATTLE MENU =" << "\n\n";
			cout << "HP: " << character.graczhp() << " / " << character.graczhpmax() << "\n\n";

			cout << "0: Escape" << "\n";
			cout << "1: Attack" << "\n";
			cout << "2: Defend" << "\n";
			cout << "\n";

			cout << "Choice: ";
			cin >> choice;

			while (cin.fail() || choice > 2 || choice < 0){
				system("CLS");
				cout << "Faulty input!" << "\n";
				cin.clear();
				cin.ignore(100, '\n');

				cout << "= BATTLE MENU =" << "\n\n";

				cout << "0: Escape" << "\n";
				cout << "1: Attack" << "\n";
				cout << "2: Defend" << "\n";
				cout << "\n";

				cout << "Choice: ";
				cin >> choice;
			}
			cin.ignore(100, '\n');
			cout << "\n";

			switch (choice){
			case 0: //ESCAPE
				escape = true;
				break;

			case 1: //ATTACK
				cout << "Wybierz potwora: " << "\n\n";
				
				cout << "Poziom: " << enemies.plvl() << " - " <<
					"HP: " << enemies.php() << "/" << enemies.pmaxhp() << " - " <<
					"Obrona: " << enemies.pobrona() << " - " <<
					"Kasa: " << enemies.pkasa() << " - " <<
					"Damage: " << enemies.pmindmg() << " - " << enemies.pmaxdmg() <<
					"\n";

				cout << "\n";
				cout << "Choice: ";
				cin >> choice;

				while (cin.fail() || choice < 0)
				{
					cout << "Faulty input!" << "\n";
					cin.clear();
					cin.ignore(100, '\n');

					cout << "Select enemy: " << "\n\n";
					cout << "Choice: ";
					cin >> choice;
				}

				cin.ignore(100, '\n');
				cout << "\n";

				//Attack roll
				combatTotal = enemies.pobrona();
				enemyTotal = enemies.pobrona() / (int)combatTotal * 100;
				playerTotal = character.graczsila() / (int)combatTotal * 100;
				combatRollPlayer = rand() % playerTotal + 1;
				combatRollEnemy = rand() % enemyTotal + 1;

				cout << "Combat total: " << combatTotal << "\n";
				cout << "Enemy percent: " << enemyTotal << "\n";
				cout << "Player percent: " << playerTotal << "\n\n";
				cout << "Player roll: " << combatRollPlayer << "\n";
				cout << "Enemy roll: " << combatRollEnemy << "\n\n";

				if (combatRollPlayer > combatRollEnemy) { //Hit
					cout << "HIT! " << "\n\n";

					damage = character.graczdmg();
					enemies.Obrazenia(damage);

					cout << "Damage: " << damage << "!" << "\n\n";

					if (!enemies.isAlive()){
						cout << "ENEMY DEFEATED!" << "\n\n";
						gainExp = enemies.pexp();
						character.graczdodexp(gainExp);
						gainGold = rand() % enemies.plvl() * 10 + 1;
						character.graczdodkasa(gainGold);
						cout << "EXP GAINED: " << gainExp << "\n";
						cout << "GOLD GAINED: " << gainGold << "\n\n";
						enemiesDefeated = true;
					}
				}
				else { //Miss
					cout << "Trafienie nie udane! \n\n";
				}
				break;

			case 2: //DEFEND
				break;

			default:
				break;
			}

			//End turn
			playerTurn = false;
		} 
		if (!playerTurn && !playerDefeated && !escape && !enemiesDefeated){
			cout << "= ENEMY TURN =" << "\n";

			cout << "Continue..." << "\n\n";
			cin.get();
			system("CLS");

			//Enemy attack
				cout << "Continue..." << "\n\n";
				cin.get();
				system("CLS");

				//cout << "Enemy: " << i << "\n\n";
				int unik = character.graczobrona() - character.graczszczescie();
				//Attack roll
				combatTotal = enemies.pobrona() + unik;
				enemyTotal = enemies.pmindmg() / (int)combatTotal * 100;
				playerTotal = (character.graczobrona() + unik) / (int)combatTotal * 100;
				combatRollPlayer = rand() % playerTotal + 1;
				combatRollEnemy = rand() % enemyTotal + 1;

				cout << "Combat total: " << combatTotal << "\n";
				cout << "Enemy percent: " << enemyTotal << "\n";
				cout << "Player percent: " << playerTotal << "\n\n";
				cout << "Player roll: " << combatRollPlayer << "\n";
				cout << "Enemy roll: " << combatRollEnemy << "\n\n";

				if (combatRollPlayer < combatRollEnemy) { //Hit
					cout << "HIT! " << "\n\n";

					damage = enemies.pdmg();
					character.GraczObrazenia(damage);

					cout << "Damage: " << damage << "!" << "\n";
					cout << "HP: " << character.graczhp() << " / " << character.graczhpmax() << "\n\n";

					if (!character.graczgra()){
						cout << "YOU ARE DEFEATED!" << "\n\n";
						playerDefeated = true;
					}
				}
				else { //MISS
					cout << "MISSED! \n\n";
				}
			

			//End turn
			playerTurn = true;
		}

		//Conditions
		if (!character.graczgra()){
			playerDefeated = true;
		}
		else if (enemies.isAlive()){
			enemiesDefeated = true;
		}
	}
}

/*void Event::puzzleEncouter(Bohater &character)
{
	bool completed = false;
	int userAns = 0;
	int chances = 3;
	int gainExp = (chances * character.getLevel() * (rand() % 10 + 1));
	int gainGold = (chances * character.getLevel() * (rand() % 10 + 1));
	//H:\ConsoleRPG\ConsoleRPG\
	
	Puzzle puzzle("Puzzles/1.txt");

	while (!completed && chances > 0)
	{
		std::cout << "Chances: " << chances << "\n\n";
		chances--;
		std::cout << puzzle.getAsString() << "\n";

		cout << "\nYour ANSWER: ";
		cin >> userAns;

		while (cin.fail())
		{
			cout << "Faulty input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "\nYour ANSWER: ";
			cin >> userAns;
		}

		cin.ignore(100, '\n');
		cout << "\n";

		if (puzzle.getCorrectAns() == userAns)
		{
			completed = true;

			character.gainExp(gainExp);
			character.gainExp(gainGold);
			std::cout << "YOU GAINED " << gainExp << " EXP!" << "\n";
			std::cout << "YOU GAINED " << gainGold << " GOLD!" << "\n\n";
		}
	}

	if (completed)
	{
		std::cout << "CONGRATZ YOU SUCCEDED! \n\n";
	}
	else
	{
		std::cout << "YOU FAILED BRAH! \n\n";
	}
}*/