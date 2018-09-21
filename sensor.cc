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
	data = s.data;
}
//destructor
Sensor::~Sensor(){
}

//obtener un valor de dataeratura
float Sensor::getData(int pos){
	return data[pos];
}
//obtener el nombre
const string& Sensor::getID()const{
	return ID;
}

int Sensor::getSize()const{
	return data.size();
}

void Sensor::clear(){
	data.clear();
	ID.clear();
}

void Sensor::querry(ostream& output,int minRange,int maxRange){
	float avg = 0,min = 0,max = 0;
	int count = 0;
	if(minRange > maxRange){
		output << "BAD QUERRY BAD RANGE" << endl;
		return;
	}
	if(minRange > data.size()){
		output << "NO DATA IN RANGE" << endl;
		return;
	}
	if(maxRange > data.size()){
		maxRange = data.size();
	}
	min = max = data[minRange]; //inicializo los min y max
	for(int i = minRange; i<=maxRange;i++){
		if(data[i] < min){
			min = data[i];
		}else{
			if(data[i] > max){
				max = data[i];
			}
		}
		avg+=data[i];
		count++;
	}
	avg = avg/count;
	output << avg << ',' << min << ',' << max << ',' << count << endl;
}

std::ostream & operator<< (std::ostream& os,const Sensor& sensor){

	os << "Sensor ID: " << sensor.getID() << endl;
	os << "Temperaturas:"<<endl;
	os << sensor.data <<endl;
	os << "Cantidad de datos: " << sensor.getSize() << endl;
	return os;
}

Sensor& Sensor::operator+(const float value){
	data.push_back(value);
	return *this;
}

Sensor& Sensor::operator=(const string& name){
	ID = name;
	return *this;
}

Sensor& Sensor::operator=(const Sensor& s){
	ID = s.ID;
	data = s.data;
	return *this;
}

bool Sensor :: operator==(const Sensor& s){
	return s.ID==ID;
}

std::istream & operator>> (std::istream& is,Sensor& sensor){
	cout << " istream no implementado";
	return is;
}