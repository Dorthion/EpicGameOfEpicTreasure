#pragma once
#include"Biblioteki.h"
#include"Bronie.h"

class Ekwipunek{
private:
	int cap;
	int nrOfItems;
	Przedmiot **itemArr;
	void expand();
	void initialize(const int from = 0);

public:
	Ekwipunek();
	~Ekwipunek();
	Ekwipunek(const Ekwipunek &obj);
	inline int size()const { return this->nrOfItems; };
	Przedmiot& operator[](const int index);
	void operator=(const Ekwipunek &obj);
	void addItem(const Przedmiot &item);
	void removeItem(int index);
	inline void debugPrint() const{
		for (size_t i = 0; i < this->nrOfItems; i++){
			cout << this->itemArr[i]->debugPrint() << endl;
		}
	}
};