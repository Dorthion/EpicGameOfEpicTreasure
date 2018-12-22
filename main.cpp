#include "Gra.h"

int main() {
	//srand(time(NULL));
	Gra OgolnieGra;
	setlocale(LC_ALL, "");
	while (OgolnieGra.CzyGra()) {
		OgolnieGra.Menu();
	}
	return 0;
}