#pragma once

//Klasa
template<typename T>
class wsk{
private:
	unsigned Wielkosc;
	unsigned iniWielkosc;
	unsigned ilosc;
	T* *TempWsk;

	//Prywatne Funkcje
	void Powiekszenie();
	void initialize(unsigned from);
public:
	//Podstawa
	wsk(unsigned size = 5);
	wsk(const wsk& obj);
	~wsk();

	//Dodatkowe Operatory
	T& operator[] (const unsigned index);
	void operator= (const wsk& obj);

	//Funkcje
	unsigned maxWielkosc();
	unsigned iloscF();
	void Dodaj(const T element);
	void Usun(const unsigned index, bool ordered = false);
};

//Konstruktor
template<typename T>
wsk<T>::wsk(unsigned size){
	this->iniWielkosc = size;
	this->Wielkosc = size;
	this->ilosc = 0;

	this->TempWsk = new T*[this->Wielkosc];

	this->initialize(0);
}

//Konstruktor kopiuj¹cy
template<typename T>
wsk<T>::wsk(const wsk& obj){
	this->iniWielkosc = obj.iniWielkosc;
	this->Wielkosc = obj.Wielkosc;
	this->ilosc = obj.ilosc;

	this->TempWsk = new T*[this->Wielkosc];

	for (size_t i = 0; i < this->ilosc; i++){
		this->TempWsk[i] = new T(*obj.TempWsk[i]);
	}

	this->initialize(0);
}

//Destruktor
template<typename T>
wsk<T>::~wsk(){
	for (size_t i = 0; i < this->ilosc; i++){
		delete this->TempWsk[i];
	}
	delete[] TempWsk;
}

//Przeci¹¿enie Operatora []
template<typename T>
T& wsk<T>::operator[] (const unsigned index){
	if (index < 0 || index >= this->ilosc)
		cout<<"Nie ma granic dla klamr!";

	return *this->TempWsk[index];
}

//Przeci¹¿enie Operatora =
template<typename T>
void wsk<T>::operator= (const wsk& obj){
	for (size_t i = 0; i < this->ilosc; i++){
		delete this->TempWsk[i];
	}
	delete[] TempWsk;

	this->iniWielkosc = obj.iniWielkosc;
	this->Wielkosc = obj.Wielkosc;
	this->ilosc = obj.ilosc;

	this->TempWsk = new T*[this->Wielkosc];

	for (size_t i = 0; i < this->ilosc; i++){
		this->TempWsk[i] = new T(*obj.TempWsk[i]);
	}

	this->initialize(0);
}

template<typename T>
void wsk<T>::Powiekszenie(){
	this->Wielkosc *= 2;
	T* *Temp2Wsk = new T*[this->Wielkosc]; //Nowa wielkosc tymczasowa wsk

	for (size_t i = 0; i < this->ilosc; i++){
		Temp2Wsk[i] = this->TempWsk[i];
	}

	delete[]TempWsk;
	this->TempWsk = Temp2Wsk;
	this->initialize(this->ilosc);
}

template<typename T>
void wsk<T>::initialize(unsigned from){
	for (size_t i = from; i < this->Wielkosc; i++){
		this->TempWsk[i] = nullptr;
	}
}

template<typename T>
unsigned wsk<T>::maxWielkosc(){
	return this->Wielkosc;
}

template<typename T>
unsigned wsk<T>::iloscF(){
	return this->ilosc;
}

template<typename T>
void wsk<T>::Dodaj(const T element){
	if (this->ilosc >= this->Wielkosc)
		this->Powiekszenie();

	this->TempWsk[this->ilosc++] = new T(element);
}

template<typename T>
void wsk<T>::Usun(const unsigned index, bool ordered){
	if (index < 0 || index >= this->ilosc)
		cout<<"Nie ma co usun¹æ!";
	if (ordered){
		delete this->TempWsk[index];

		for (size_t i = 0; i < this->ilosc - 1; i++){
			this->TempWsk[i] = this->TempWsk[i + 1];
		}
		this->TempWsk[--this->ilosc] = nullptr;
	} else {
		delete this->TempWsk[index];
		this->TempWsk[index] = this->TempWsk[this->ilosc - 1];
		this->TempWsk[--this->ilosc] = nullptr;
	}
}