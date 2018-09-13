#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <sensor.h>
//constructores
Sensor::Sensor(){
	ID = "Sensor";
	size = 0;
}
Sensor::Sensor(string name){
	ID = name;
	size = 0;
}
Sensor::Sensor(const Sensor& s){
	ID = s.getID();
	size = s.getSize();
}
//destructor
Sensor::~Sensor(){
}
// agregar temperatura
void Sensor::addTemp(float value){
	while(size > temp.getSize()){
		temp.enlarge();
	}
	temp[size] = value;
	size++;
}
//setear el nombre o cambiarlo
void Sensor::setID(string name){
	ID = name;
}
//obtener un valor de temperatura
float Sensor::getTemp(int pos){
	if(size>pos){
		return temp[pos];
	}else{
		return 0;
	}
	
}
//obtener el nombre
string Sensor::getID()const{
	return ID;
}

int Sensor::getSize()const{
	return size;
}
//obtener maximo
float Sensor::getMax(int min,int max){
	float maxValue = 0;
	//si el maximo se pasa de la cantidad de muestras, fijo el size de muestra como max
	if(size < max ){
		max = size;
	}
	//calculo del maximo
	for(int i = min; i<max;i++){
		if(maxValue < temp[i-1]){
			maxValue = temp[i-1];
		}
	}
	return maxValue;
}
//obtener minimo
float Sensor::getMin(int min,int max){
	float minValue = 0;
	//si el maximo se pasa de la cantidad de muestras, fijo el size de muestra como max
	if(size < max ){
		max = size;
	}
	//calculo del maximo
	for(int i = min; i<max;i++){
		if(minValue > temp[i-1]){
			minValue = temp[i-1];
		}
	}
	return minValue;
}
//obtener promedio
float Sensor::getAvg(int min,int max){
	float avgValue = 0;
	int count;
	//si el maximo se pasa de la cantidad de muestras, fijo el size de muestra como max
	if(size < max ){ 
		max = size;
	}
	//calculo de suma avg
	for(int i = min; i<max;i++){
		avgValue += temp[i-1];
		count++;
	}
	if(count == 0){
		return 0;
	}
	return avgValue/count;	
}
//obtener cantidad de muestras de un rango de posiciones
int Sensor::getCount(int min,int max)const{
	//si el maximo se pasa de la cantidad de muestras, fijo el size de muestra como max
	if(size < max ){ 
		max = size;
	}
	return max-min;
}