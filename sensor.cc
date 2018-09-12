#include <complejo.h>
#include <iostream>
#include <cmath>

//constructores
sensor::sensor(){
	this->ID = "sensor";
	this->size = 0;
	this->temp = New Array <int> ();
}
sensor::sensor(char* name){
	this->ID = name;
	this->size = 0;
	this->temp = New Array();
}
sensor::sensor(const sensor& s){
	ID = s.getID();
	size = s.getSize();
	temp = New Array(s.temp);
}
//destructor
sensor::~sensor(){
	delete temp;
}
// agregar temperatura
void sensor::addTemp(int value){
	while(size > temp.getSize()){
		temp.enlarge();
	}
	temp[size] = value;
	size++;
}
//setear el nombre o cambiarlo
void sensor::setID(string name){
	ID = name;
}
//obtener un valor de temperatura
int sensor::getTemp(int pos)const{
	if(size>pos){
		return temp[pos];
	}else{
		return 0;
	}
	
}
//obtener el nombre
sting sensor::getID()const{
	return string;
}
//obtener maximo
int sensor::getMax(int min,int max)const{
	int maxValue = 0;
	//si el maximo se pasa de la cantidad de muestras, fijo el size de muestra como max
	if(size < max ){
		max = size;
	}
	//calculo del maximo
	for(i = min; i<max;i++){
		if(maxValue < temp[i-1]){
			maxValue = temp[i-1];
		}
	}
	return maxValue;
}
//obtener maximo
int sensor::getMin(int min,int max)const{
	int minValue = 0;
	//si el maximo se pasa de la cantidad de muestras, fijo el size de muestra como max
	if(size < max ){
		max = size;
	}
	//calculo del maximo
	for(i = min; i<max;i++){
		if(minValue > temp[i-1]){
			minValue = temp[i-1];
		}
	}
	return minValue;
}
//obtener promedio
int sensor::getAvg(int min,int max)const{
	int avgValue = 0;
	int count;
	//si el maximo se pasa de la cantidad de muestras, fijo el size de muestra como max
	if(size < max ){ 
		max = size;
	}
	//calculo de suma avg
	for(i = min; i<max;i++){
		avgValue += temp[i-1];
		count++;
	}
	if(count == 0){
		return 0;
	}
	return avgValue/count;	
}
//obtener cantidad de muestras de un rango de posiciones
int getCount(int min,int max)const{
	int count;
	//si el maximo se pasa de la cantidad de muestras, fijo el size de muestra como max
	if(size < max ){ 
		max = size;
	}
	return max-min;
}