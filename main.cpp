#include "Gra.h"
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "");
	Gra OgolnieGra;
	OgolnieGra.InitGry();
	while (OgolnieGra.CzyGra()) {
		OgolnieGra.Menu();
	}
	return 0;
}