#include <complejo.h>
#include <iostream>
#include <cmath>

using namespace std;

array::array(int l = 10){
	length = l;
	p = New int[l];
}
array::array(const array& a){
	length = a.getLength();
	p = New int[this->length];
	for (i=0;i<length,i++){
		this->p[i] = a[i];
	}
}
array::~array(){
	delete[]p;
}
int& array::operator[](int pos){
	return p[pos];
}
int array::getLength(){
	return length;
}