#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <sensor.h>
//constructores
Sensor::Sensor(){
	ID = "Sensor";
}
Sensor::Sensor(const string& name){
	ID = name;
}
Sensor::Sensor(const Sensor& s){
	ID = s.getID();
	temp = s.temp;
}
//destructor
Sensor::~Sensor(){
}

//obtener un valor de temperatura
float Sensor::getTemp(int pos){
	return temp[pos];
}
//obtener el nombre
const string& Sensor::getID()const{
	return ID;
}

int Sensor::getSize()const{
	return temp.size();
}

void Sensor::clear(){
	temp.clear();
	ID.clear();
}
//obtener maximo
float Sensor::getMax(int min,int max){
	float maxValue = 0;
	//si el maximo se pasa de la cantidad de muestras, fijo el size de muestra como max
	if(temp.size() < max ){
		max = temp.size();
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
	if(temp.size() < max ){
		max = temp.size();
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
	if(temp.size() < max ){ 
		max = temp.size();
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
	if(temp.size() < max ){ 
		max = temp.size();
	}
	return max-min;
}

std::ostream & operator<< (std::ostream& os,const Sensor& sensor){

	os << "Sensor ID: " << sensor.getID() << endl;
	os << "Temperaturas:"<<endl;
	os << sensor.temp <<endl;

	return os;
}

Sensor& Sensor::operator+(const float value){
	temp.push_back(value);
	return *this;
}

Sensor& Sensor::operator=(const string& name){
	ID = name;
	return *this;
}

Sensor& Sensor::operator=(const Sensor& s){
	ID = s.ID;
	temp = s.temp;
}

std::istream & operator>> (std::istream& is,Sensor& sensor){
	cout << " istream no implementado";
	return is;
}