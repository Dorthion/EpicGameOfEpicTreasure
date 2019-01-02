#pragma once

template<typename T>
class wsk{
private:
	unsigned cap;
	unsigned initialCap;
	unsigned ilosc;
	T* *arr;

	void expand();
	void initialize(unsigned from);
public:
	wsk(unsigned size = 5);
	wsk(const wsk& obj);
	~wsk();

	T& operator[] (const unsigned index);
	void operator= (const wsk& obj);

	unsigned maxCap();
	unsigned size();
	void push(const T element);
	void remove(const unsigned index, bool ordered = false);
};

template<typename T>
wsk<T>::wsk(unsigned size){
	this->initialCap = size;
	this->cap = size;
	this->ilosc = 0;

	this->arr = new T*[this->cap];

	this->initialize(0);
}

template<typename T>
wsk<T>::wsk(const wsk& obj){
	this->initialCap = obj.initialCap;
	this->cap = obj.cap;
	this->ilosc = obj.ilosc;

	this->arr = new T*[this->cap];

	for (size_t i = 0; i < this->ilosc; i++){
		this->arr[i] = new T(*obj.arr[i]);
	}

	this->initialize(0);
}

template<typename T>
wsk<T>::~wsk(){
	for (size_t i = 0; i < this->ilosc; i++){
		delete this->arr[i];
	}
	delete[] arr;
}

template<typename T>
T& wsk<T>::operator[] (const unsigned index){
	if (index < 0 || index >= this->ilosc)
		throw "OUT OF BOUNDS INDEXING OPERATOR.";

	return *this->arr[index];
}

template<typename T>
void wsk<T>::operator= (const wsk& obj){
	for (size_t i = 0; i < this->ilosc; i++){
		delete this->arr[i];
	}
	delete[] arr;

	this->initialCap = obj.initialCap;
	this->cap = obj.cap;
	this->ilosc = obj.ilosc;

	this->arr = new T*[this->cap];

	for (size_t i = 0; i < this->ilosc; i++){
		this->arr[i] = new T(*obj.arr[i]);
	}

	this->initialize(0);
}

template<typename T>
void wsk<T>::expand(){
	this->cap *= 2;

	T* *tempArr = new T*[this->cap];

	for (size_t i = 0; i < this->ilosc; i++){
		tempArr[i] = this->arr[i];
	}

	delete[]arr;

	this->arr = tempArr;

	this->initialize(this->ilosc);
}

template<typename T>
void wsk<T>::initialize(unsigned from){
	for (size_t i = from; i < this->cap; i++){
		this->arr[i] = nullptr;
	}
}

template<typename T>
unsigned wsk<T>::maxCap(){
	return this->cap;
}

template<typename T>
unsigned wsk<T>::size(){
	return this->ilosc;
}

template<typename T>
void wsk<T>::push(const T element){
	if (this->ilosc >= this->cap)
		this->expand();

	this->arr[this->ilosc++] = new T(element);
}

template<typename T>
void wsk<T>::remove(const unsigned index, bool ordered){
	if (index < 0 || index >= this->ilosc)
		throw "OUT OF BOUNDS REMOVE.";

	if (ordered){
		delete this->arr[index];

		for (size_t i = 0; i < this->ilosc - 1; i++){
			this->arr[i] = this->arr[i + 1];
		}

		this->arr[--this->ilosc] = nullptr;
	} else {
		delete this->arr[index];

		this->arr[index] = this->arr[this->ilosc - 1];

		this->arr[--this->ilosc] = nullptr;
	}
}