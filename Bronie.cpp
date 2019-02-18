#include "Bronie.h"

//Miecze - si³a
string nazwy1[6] = { "DrewnianyMiecz", "SzklanyMiecz", "ElfickiMiecz",
"MrocznyMiecz", "ZaklêtyMiecz","MieczZag³ady" };

//£uki - zrêcznoœæ
string nazwy2[6] = { "Zwyk³y£uk", "£ukRefleksyjny", "£ukBojowy",
"£ukBlokowy", "Elektryczny£uk", "£uk£owcyG³ów" };

//Sztylety - szczêœcie
string nazwy3[6] = { "OstrzaZBr¹zu", "MetaloweTasaki", "SztyletyZabójcy",
"ZatruteOstrza", "SztyletyCienia", "OstrzaSkrytobójcy" };

//Ró¿d¿ki - magia
string nazwy4[6] = { "Zwyk³aRó¿d¿ka", "Ró¿d¿kaZiemii", "Ró¿d¿kaPowietrza",
"Ró¿d¿kaWody", "Ró¿d¿kaOgnia", "Ró¿d¿ka¯ywio³ów" };

//Bu³awy i topory - obrona
string nazwy5[6] = { "DrewnianaPa³ka", "Bu³awaZbója", "ToporyWikinga",
"Bu³awaOrka", "M³otZasiêgowy", "M³otThora" };

Bronie::Bronie() :Przedmiot(){
	this->maxsila = 0;
	this->minsila = 0;
	this->minzre = 0;
	this->maxzre = 0;
	this->minmagia = 0;
	this->maxmagia = 0;
	this->minszcz = 0;
	this->maxszcz = 0;
	this->minobr = 0;
	this->maxobr = 0;
}

Bronie::Bronie(int nrbuydynku,  int poziom, int rzadkosc) : Przedmiot(poziom, rzadkosc) {
	switch (nrbuydynku) {
	case 3: //Miecze
		this->maxsila = rand() % poziom * (rzadkosc + 1);
		this->maxsila += (rzadkosc + 1) * 5;
		this->ustawNazwe(nazwy1[rand() % 6]);
		if (rzadkosc == 3)
			this->maxsila += poziom * 5;
		if (rzadkosc == 4)
			this->maxsila += poziom * 10;

		this->minsila = this->maxsila / 2;
		this->minzre = 1;
		this->maxzre = 2;
		this->minmagia = 1;
		this->maxmagia = 2;
		this->minszcz = 0;
		this->maxszcz = 0;
		this->minobr = 1;
		this->maxobr = (poziom + 1) + poziom;
		break;

	case 4: //£uki
		this->maxzre = rand() % poziom * (rzadkosc + 1);
		this->maxzre += (rzadkosc + 1) * 5;
		this->ustawNazwe(nazwy2[rand() % 6]);
		if (rzadkosc == 3)
			this->maxzre += poziom * 5;
		if (rzadkosc == 4)
			this->maxzre += poziom * 10;

		this->minzre = this->maxzre / 2;
		this->minsila = 1;
		this->maxsila = 2;
		this->minmagia = 0;
		this->maxmagia = 0 + poziom;
		this->minszcz = 0;
		this->maxszcz = 0 + poziom;
		this->minobr = 0;
		this->maxobr = (poziom + 1) + poziom;
		break;

	case 5: //Sztylety
		this->maxszcz = rand() % poziom * (rzadkosc + 1);
		this->maxszcz += (rzadkosc + 1) * 5;
		this->ustawNazwe(nazwy3[rand() % 6]);
		if (rzadkosc == 3)
			this->maxsila += poziom * 5;
		if (rzadkosc == 4)
			this->maxsila += poziom * 10;

		this->minsila = (int)(poziom*rzadkosc);
		this->maxsila = (int)((poziom + 1)*rzadkosc) + poziom;
		this->minzre = 1;
		this->maxzre = poziom;
		this->minmagia = 1;
		this->maxmagia = 1;
		this->minobr = 1;
		this->maxobr = 1;
		break;

	case 6: //Ró¿d¿ki
		this->maxmagia = rand() % poziom * (rzadkosc + 1);
		this->maxmagia += (rzadkosc + 1) * 5;
		this->ustawNazwe(nazwy4[rand() % 6]);
		if (rzadkosc == 3)
			this->maxmagia += poziom * 5;
		if (rzadkosc == 4)
			this->maxmagia += poziom * 10;

		this->minmagia = (int) (rand() % this->maxmagia + (int)((this->maxmagia + 1) / 2));
		this->minsila = 1;
		this->maxsila = poziom + 1;
		this->minzre = 1;
		this->maxzre = 1;
		this->minszcz = 1;
		this->maxszcz = poziom + 1;
		this->minobr = 1;
		this->maxobr = poziom + 1;
		break;

	case 7: //Bu³awy i Topory
		this->maxobr = rand() % poziom * (rzadkosc + 1);
		this->maxobr += (rzadkosc + 1) * 5;
		this->ustawNazwe(nazwy1[rand() % 6]);
		if (rzadkosc == 3)
			this->maxobr += poziom * 5;
		if (rzadkosc == 4)
			this->maxobr += poziom * 10;

		this->maxsila = (int)(this->maxobr / 2) + poziom;
		this->minsila = (int)(this->maxobr / 2);
		this->minzre = 1;
		this->maxzre = 1;
		this->minmagia = (int)(poziom*rzadkosc);
		this->maxmagia = (int)(poziom*rzadkosc) + 1;
		this->minszcz = 1;
		this->maxszcz = 1;
		break;
	}
}

Bronie::Bronie(int mindmg, int maxdmg, int minzre, int maxzre, int minmagia, int maxmagia,
	int minszcz, int maxszcz, int minobr, int maxobr,
	string nazwa, int poziom, int cenak, int cenas, int rzadkosc)
	: Przedmiot(nazwa, poziom, cenak, cenas, rzadkosc){
	this->minsila = mindmg;
	this->maxsila = maxdmg;
	this->minzre = minzre;
	this->maxzre = maxzre;
	this->minmagia = minmagia;
	this->maxmagia = maxmagia;
	this->minszcz = minszcz;
	this->maxszcz = maxszcz;
	this->minobr = minobr;
	this->maxobr = maxobr;
}

Bronie* Bronie::Kopiowanie()const{
	return new Bronie(*this);
}

string Bronie::toString()const{
	string str = this->przedmiotNazwa() + " | Poziom: " + to_string(this->przedmiotPoziom())
	+ " | Rzadkoœæ: " + to_string(this->przedmiotRzadkosc())
	+ " \n| Si³a: " + to_string(this->minsila)
	+ " - " + to_string(this->maxsila)
	+ " \n| Zrêcznoœæ: " + to_string(this->minzre)
	+ " - " + to_string(this->maxzre)
	+ " \n| Magia: " + to_string(this->minmagia)
	+ " - " + to_string(this->maxmagia)
	+ " \n| Szczêœcie: " + to_string(this->minszcz)
	+ " - " + to_string(this->maxszcz)
	+ " \n| Obrona: " + to_string(this->minobr)
	+ " - " + to_string(this->maxobr);
	return str;
}

string Bronie::saveString()const{
	string sStr =this->przedmiotNazwa()
		+ " " + to_string(this->przedmiotPoziom())
		+ " " + to_string(this->przedmiotRzadkosc())
		+ " " + to_string(this->przedmiotCenak())
		+ " " + to_string(this->przedmiotCenas())
		+ " " + to_string(this->minsila)
		+ " " + to_string(this->maxsila) 
		+ " " + to_string(this->minzre)
		+ " " + to_string(this->maxzre)
		+ " " + to_string(this->minmagia)
		+ " " + to_string(this->maxmagia)
		+ " " + to_string(this->minszcz)
		+ " " + to_string(this->maxszcz)
		+ " " + to_string(this->minobr)
		+ " " + to_string(this->maxobr)
		+ " ";
	return sStr;
}