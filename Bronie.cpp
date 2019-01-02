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
	case 4: //�uki
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
	case 6: //R�d�ki
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
	case 7: //Bu�awy i Topory
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