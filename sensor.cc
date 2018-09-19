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

void Sensor::querry(ostream output,size_t minRange,size_t maxRange){
	float avg = 0,min = 0,max = 0;
	int count = 0;
	if(minRange > maxRange){
		output << "BAD QUERRY" << endl;
		return;
	}
	if(minRange > temp.size()){
		output << "NO DATA" << endl;
		return;
	}
	if(maxRange > temp.size()){
		maxRange = temp.size();
	}
	min = max = temp[minRange]; //inicializo los min y max
	for(int i = minRange; i<=maxRange;i++){
		if(temp[i] < min){
			min = temp[i];
		}else{
			if(temp[i] > max){
				max = temp[i];
			}
		}
		avg+=temp[i];
		count++;
	}
	avg = avg/count;
	output << avg << ',' << min << ',' << max << ',' << count << endl;
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
	return *this;
}

bool Sensor :: compareName(string const & name){
	return ID==name;
}

std::istream & operator>> (std::istream& is,Sensor& sensor){
	cout << " istream no implementado";
	return is;
}