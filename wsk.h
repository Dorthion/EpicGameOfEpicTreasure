#pragma once

//Klasa
template<typename T>
class wsk{
private:
	//Prywatne zmienne
	unsigned Wielkosc;
	unsigned iniWielkosc;
	unsigned ilosc;
	T* *TempWsk;

	//Prywatne Funkcje
	void Powiekszenie();
	void Inicjalizacja(unsigned IloscWsk);
public:
	//Podstawa
	wsk(unsigned Wielkoscwsk = 5);
	wsk(const wsk& Obiekt);
	~wsk();

	//Dodatkowe Operatory
	T& operator[] (const unsigned numer);
	void operator= (const wsk& Obiekt);

	//Funkcje
	unsigned maxWielkosc();
	unsigned iloscF();
	void Dodaj(const T element);
	void Usun(const unsigned numer, bool Wybor = false);
};

//Konstruktor
template<typename T>
wsk<T>::wsk(unsigned Wielkoscwsk){
	this->iniWielkosc = Wielkoscwsk;
	this->Wielkosc = Wielkoscwsk;
	this->ilosc = 0;

	this->TempWsk = new T*[this->Wielkosc];

	this->Inicjalizacja(0);
}

//Konstruktor kopiuj¹cy
template<typename T>
wsk<T>::wsk(const wsk& Obiekt){
	this->iniWielkosc = Obiekt.iniWielkosc;
	this->Wielkosc = Obiekt.Wielkosc;
	this->ilosc = Obiekt.ilosc;

	this->TempWsk = new T*[this->Wielkosc];

	for (size_t i = 0; i < this->ilosc; i++){
		this->TempWsk[i] = new T(*Obiekt.TempWsk[i]);
	}

	this->Inicjalizacja(0);
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
T& wsk<T>::operator[] (const unsigned numer){
	if (numer < 0 || numer >= this->ilosc)
		cout<<"Nie ma granic dla klamr!";

	return *this->TempWsk[numer];
}

//Przeci¹¿enie Operatora =
template<typename T>
void wsk<T>::operator= (const wsk& Obiekt){
	for (size_t i = 0; i < this->ilosc; i++){
		delete this->TempWsk[i];
	}
	delete[] TempWsk;

	this->iniWielkosc = Obiekt.iniWielkosc;
	this->Wielkosc = Obiekt.Wielkosc;
	this->ilosc = Obiekt.ilosc;

	this->TempWsk = new T*[this->Wielkosc];

	for (size_t i = 0; i < this->ilosc; i++){
		this->TempWsk[i] = new T(*Obiekt.TempWsk[i]);
	}

	this->Inicjalizacja(0);
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
	this->Inicjalizacja(this->ilosc);
}

template<typename T>
void wsk<T>::Inicjalizacja(unsigned IloscWsk){
	for (size_t i = IloscWsk; i < this->Wielkosc; i++){
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
void wsk<T>::Usun(const unsigned numer, bool Wybor){
	if (numer < 0 || numer >= this->ilosc)
		cout<<"Nie ma co usun¹æ!";
	if (Wybor){
		delete this->TempWsk[numer];
		for (size_t i = 0; i < this->ilosc - 1; i++){
			this->TempWsk[i] = this->TempWsk[i + 1];
		}
		this->TempWsk[--this->ilosc] = nullptr;
	} else {
		delete this->TempWsk[numer];
		this->TempWsk[numer] = this->TempWsk[this->ilosc - 1];
		this->TempWsk[--this->ilosc] = nullptr;
	}
}