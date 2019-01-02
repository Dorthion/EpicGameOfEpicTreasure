#include "Ekwipunek.h"

Ekwipunek::Ekwipunek(){
	this->cap = 5;
	this->nrOfItems = 0;
	this->itemArr = new Przedmiot*[cap];
	this->initialize();
}

Ekwipunek::~Ekwipunek(){
	for (size_t i = 0; i < this->nrOfItems; i++){
		delete this->itemArr[i];
	}
	delete[] this->itemArr;
}

Ekwipunek::Ekwipunek(const Ekwipunek &obj){
	this->cap = obj.cap;
	this->nrOfItems = obj.nrOfItems;
	this->itemArr = new Przedmiot*[this->cap];

	for (size_t i = 0; i < this->nrOfItems; i++){
		this->itemArr[i] = obj.itemArr[i]->clone();
	}

	initialize(this->nrOfItems);
}

Przedmiot& Ekwipunek::operator[](const int index){
	if (index < 0 || index >= this->nrOfItems)
		throw("BAD INDEX!");

	return *this->itemArr[index];
}

void Ekwipunek::operator=(const Ekwipunek &obj){
	for (size_t i = 0; i < this->nrOfItems; i++){
		delete this->itemArr[i];
	}
	delete[] this->itemArr;

	this->cap = obj.cap;
	this->nrOfItems = obj.nrOfItems;
	this->itemArr = new Przedmiot*[this->cap];

	for (size_t i = 0; i < this->nrOfItems; i++){
		this->itemArr[i] = obj.itemArr[i]->clone();
	}

	initialize(this->nrOfItems);
}

void Ekwipunek::expand(){
	this->cap *= 2;

	Przedmiot **tempArr = new Przedmiot*[this->cap];

	for (size_t i = 0; i < this->nrOfItems; i++){
		tempArr[i] = this->itemArr[i];
	}

	delete[] this->itemArr;

	this->itemArr = tempArr;

	this->initialize(this->nrOfItems);
}

void Ekwipunek::initialize(const int from){
	for (size_t i = from; i < cap; i++){
		this->itemArr[i] = nullptr;
	}
}

void Ekwipunek::addItem(const Przedmiot &item){
	if (this->nrOfItems >= this->cap){
		expand();
	}
	this->itemArr[this->nrOfItems++] = item.clone();
}

void Ekwipunek::removeItem(int index){
	if (index < 0 || index >= this->nrOfItems)
		throw("OUT OF BOUNDS REMOVE ITEM INVENTORY");

	delete this->itemArr[index];
	this->itemArr[index] = this->itemArr[this->nrOfItems - 1];
	this->itemArr[--this->nrOfItems] = nullptr;
}