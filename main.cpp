#include "Gra.h"
int main() {
	srand((unsigned int)time(NULL));
	setlocale(LC_ALL, "");
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	Gra OgolnieGra;
	OgolnieGra.InitGry();
	while (OgolnieGra.CzyGra()) {
		OgolnieGra.Menu();
	}
	return 0;
}