#include "Bronie.h"

//Miecze - si³a
string nazwy1[6] = { "Drewniany Miecz", "Szklany Miecz", "Elficki Miecz",
"Mroczny Miecz", "Zaklêty Miecz","Miecz Zag³ady" };

//£uki - zrêcznoœæ
string nazwy2[6] = { "Zwyk³y £uk", "£uk Refleksyjny", "£uk Bojowy",
"£uk Blokowy", "Elektryczny £uk", "£uk £owcy G³ów" };

//Sztylety - szczêœcie
string nazwy3[6] = { "Ostrza z Br¹zu", "Metalowe Tasaki", "Sztylety Zabójcy",
"Zatrute Ostrza", "Sztylety Cienia", "Ostrza Skrytobójcy" };

//Ró¿d¿ki - magia
string nazwy4[6] = { "Zwyk³a ró¿d¿ka", "Ró¿d¿ka Ziemii", "Ró¿d¿ka Powietrza",
"Ró¿d¿ka Wody", "Ró¿d¿ka Ognia", "Ró¿d¿ka ¯ywio³ów" };

//Bu³awy i topory - obrona
string nazwy5[6] = { "Drewniana Pa³ka", "Bu³awa Zbója", "Topory Wikinga",
"Bu³awa Orka", "M³ot Zasiêgowy", "M³ot Thora" };

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
		this->setName(nazwy1[rand() % 6]);
		if (rzadkosc == 3)
			this->maxsila += poziom * 5;
		else if (rzadkosc == 4)
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
		this->setName(nazwy2[rand() % 6]);
		if (rzadkosc == 3)
			this->maxzre += poziom * 5;
		else if (rzadkosc == 4)
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
		this->setName(nazwy3[rand() % 6]);
		if (rzadkosc == 3)
			this->maxsila += poziom * 5;
		else if (rzadkosc == 4)
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
		this->setName(nazwy4[rand() % 6]);
		if (rzadkosc == 3)
			this->maxmagia += poziom * 5;
		else if (rzadkosc == 4)
			this->maxmagia += poziom * 10;

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
		this->setName(nazwy1[rand() % 5]);
		if (rzadkosc == 3)
			this->maxobr += poziom * 5;
		else if (rzadkosc == 4)
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
	string nazwa, int poziom, int buyValue, int sellValue, int rzadkosc)
	: Przedmiot(nazwa, poziom, buyValue, sellValue, rzadkosc){
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

Bronie::~Bronie(){
}

Bronie* Bronie::clone()const{
	return new Bronie(*this);
}

string Bronie::toString()const{
	string str = this->getName() + " | Poziom: " + to_string(this->getLevel())
	+ " | Rzadkoœæ: " + to_string(this->getRarity())
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

string Bronie::toStringSave()const{
	string str =this->getName()
		+ " " + to_string(this->getLevel())
		+ " " + to_string(this->getRarity())
		+ " " + to_string(this->getBuyValue())
		+ " " + to_string(this->getSellValue())
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
	return str;
}