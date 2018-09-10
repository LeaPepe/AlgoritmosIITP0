#include <complejo.h>
#include <iostream>
#include <cmath>

using namespace std;

sensor::sensor(char* name){
	this->ID = name;
	this->samples = 0;
	this->temperature = New array();
}
sensor::sensor(const sensor& s){
	ID = s.getID();
	samples = s.samples;
	temperature = New array(s.temperature);
}
sensor::~sensor(){
	delete temperature;
}
void sensor::addTemp(int& temp){
	temperature[samples] = temp;
	samples++;
}