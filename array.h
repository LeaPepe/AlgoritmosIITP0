#ifndef _ARRAY_TEMPLATE_H_INCLUDED_
#define _ARRAY_TEMPLATE_H_INCLUDED_
//probando
#include <iostream>
#include <stdio.h>
using namespace std;
//plantilla de Array
template <class T>
class Array{
	T* p; //puntero a vector
	int size; // tamano
public:
	Array(); // constructor vacio
	Array(int); // constructor de tamano definido
	Array(const Array <T>&); //constructor copia
	~Array(); //destructor
	int getSize() const; // preguntar tamano
	T& operator[](int); //operador de vector
	bool operator==(const Array <T>&)const; // operador booleano == 
	Array <T>& operator=(const Array <T>&); // operador asignacion
	void enlarge(int size = 10);
};

//constructores
template<class T>
Array <T>::Array(){
	size=10;
	p = new T[size];
}
template<class T>
Array <T>::Array(int s){
	size=s;
	p = new T[size];
}
template<class T>
Array <T>::Array(const Array <T> & arr){
	size=arr.getSize();
	p = new T[size];
	for(int i=0;i<size;i++){
		p[i]=arr.p[i];
	}
}
//destructor
template<class T>
Array <T>::~Array(){
	if(p != NULL){
		delete []p;
	}
}
//getSize() devuelve el tamano del array
template<class T>
int Array <T>::getSize() const{
	return size;
}
//operador asignacion
template<class T>
Array <T>& Array<T>::operator=(const Array<T>& arr){
	if(this != &arr){
		if(size != arr.size){
			T* aux;
			aux = new T[arr.size];
			delete[]p;
			size = arr.size;
			p=aux;
		}
		for(int i=0;i<size;i++){
			p[i]=arr.p[i];
		}
	}
	return *this;
}
//operador booleano igualdad
template<class T>
bool Array <T>::operator==(const Array <T> & arr)const{
	if(arr.getSize() == size){
		for(int i=0;i<size;i++){
			if(arr.p[i] != p[i]){
				return false;
			}
		}
		return true;
	}else{
		return false;
	}
}
//operador de vector
template<class T>
T& Array <T>::operator[](int pos){
	if(size>=pos){
		return 0; //no se como hacerlo 
	}else{
		return p[pos];
	}
}
//agrandar vector
template<class T>
void  Array <T>::enlarge(int s){
	int newSize = size+s;
	T* aux;
	aux = new T[newSize];
	for(int i=0;i<size;i++){
		aux[i] = p[i];
	}
	delete[] p;
	size = newSize;
	p = aux;
	
}

#endif
