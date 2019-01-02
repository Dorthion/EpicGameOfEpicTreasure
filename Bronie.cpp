#include "Bronie.h"

//Miecze - si�a
string nazwy1[6] = { "Drewniany Miecz", "Szklany Miecz", "Elficki Miecz",
"Mroczny Miecz", "Zakl�ty Miecz","Miecz Zag�ady" };

//�uki - zr�czno��
string nazwy2[6] = { "Zwyk�y �uk", "�uk Refleksyjny", "�uk Bojowy",
"�uk Blokowy", "Elektryczny �uk", "�uk �owcy G��w" };

//Sztylety - szcz�cie
string nazwy3[6] = { "Ostrza z Br�zu", "Metalowe Tasaki", "Sztylety Zab�jcy",
"Zatrute Ostrza", "Sztylety Cienia", "Ostrza Skrytob�jcy" };

//R�d�ki - magia
string nazwy4[6] = { "Zwyk�a r�d�ka", "R�d�ka Ziemii", "R�d�ka Powietrza",
"R�d�ka Wody", "R�d�ka Ognia", "R�d�ka �ywio��w" };

//Bu�awy i topory - obrona
string nazwy5[6] = { "Drewniana Pa�ka", "Bu�awa Zb�ja", "Topory Wikinga",
"Bu�awa Orka", "M�ot Zasi�gowy", "M�ot Thora" };

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
	case 3:
		this->maxsila = rand() % poziom * (rzadkosc + 1);
		this->maxsila += (rzadkosc + 1) * 5;
		this->setName(nazwy1[rand() % 5]);
		if (rzadkosc == 3)
			this->maxsila += poziom * 5;
		else if (rzadkosc == 4)
			this->maxsila += poziom * 10;

		this->minsila = this->maxsila / 2;
		break;
	case 4:
		this->maxsila = rand() % poziom * (rzadkosc + 1);
		this->maxsila += (rzadkosc + 1) * 5;
		this->setName(nazwy1[rand() % 5]);
		if (rzadkosc == 3)
			this->maxsila += poziom * 5;
		else if (rzadkosc == 4)
			this->maxsila += poziom * 10;

		this->minsila = this->maxsila / 2;
		break;
	case 5:
		this->maxsila = rand() % poziom * (rzadkosc + 1);
		this->maxsila += (rzadkosc + 1) * 5;
		this->setName(nazwy1[rand() % 5]);
		if (rzadkosc == 3)
			this->maxsila += poziom * 5;
		else if (rzadkosc == 4)
			this->maxsila += poziom * 10;

		this->minsila = this->maxsila / 2;
		break;
	case 6:
		this->maxsila = rand() % poziom * (rzadkosc + 1);
		this->maxsila += (rzadkosc + 1) * 5;
		this->setName(nazwy1[rand() % 5]);
		if (rzadkosc == 3)
			this->maxsila += poziom * 5;
		else if (rzadkosc == 4)
			this->maxsila += poziom * 10;

		this->minsila = this->maxsila / 2;
		break;
	case 7:
		this->maxsila = rand() % poziom * (rzadkosc + 1);
		this->maxsila += (rzadkosc + 1) * 5;
		this->setName(nazwy1[rand() % 5]);
		if (rzadkosc == 3)
			this->maxsila += poziom * 5;
		else if (rzadkosc == 4)
			this->maxsila += poziom * 10;

		this->minsila = this->maxsila / 2;
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
	+ " | Rzadko��: " + to_string(this->getRarity())
	+ " \n| Si�a: " + to_string(this->minsila)
	+ " - " + to_string(this->maxsila)
	+ " \n| Zr�czno��: " + to_string(this->minzre)
	+ " - " + to_string(this->maxzre)
	+ " \n| Magia: " + to_string(this->minmagia)
	+ " - " + to_string(this->maxmagia)
	+ " \n| Szcz�cie: " + to_string(this->minszcz)
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