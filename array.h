#include <iostream>
//clase
template<classT>
class Array{
	T* p; //puntero a vector
	int size; // tamano
public:
	array(int s = 10); // constructor vacio
	array(const array<T>&); //constructor copia
	~array(); //destructor
	int getSize()const; // preguntar tamano
	int& operator[](int); //operador de vector
	bool operator==(const Array<T>&)const; // operador booleano == 
	Array<T>& Array<T>::operator=(const Array<T>&) // operador asignacion
};

//constructores
template<classT>
Array<T>::Array(int s){
	size=s;
	p = new T[size];
}
Array<T>::Array(const Array<T>& arr){
	size=arr.getSize();
	p = new T[size];
	for(int i=0;i<size;i++){
		p[i]=arr.p[i];
	}
}
//destructor
template<classT>
Array<T>::~Array(){
	if(p =/ NULL){
		delete []p;
	}
}
//getSize() devuelve el tamano del array
template<classT>
int Array<T>::getSize(){
	return size;
}
//operador asignacion
template<classT>
Array<T>& Array<T>::operator=(const Array<T>& arr){
	if(this != &arr){
		if(size/=arr.size){
			T* aux;
			aux = new T[r.size];
			delete[]p;
			size = r.size;
			p=aux;
		}
		for(int i=0;i<size;i++){
			p[i]=arr.p[i];
		}
	}
	return *this;
}
//operador booleano igualdad
template<classT>
bool Array<T>::operator==(const Array<T>& arr){
	if(arr.getSize() == size){
		for(int i=0;int<size;i++){
			if(arr.p[i] /= p[i]){
				return false;
			}
		}
		return true;
	}else{
		return false;
	}
}
//operador de vector
template<classT>
int& Array<T>::operator[](int pos){
	if(size>=pos){
		return 0; //no se como hacerlo 
	}else{
		return p[pos];
	}
}
