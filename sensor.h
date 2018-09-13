#ifndef _SENSOR_H_INCLUDED_
#define _SENSOR_H_INCLUDED_

#include <cstdlib>
#include <iostream>
#include <string>
#include <array.h>

using namespace std;

class Sensor {
	int size;
	string ID;
	Array<float> temp;

public:
	Sensor();
	Sensor(string);
	Sensor(const Sensor&);
	~Sensor();
	void setID(string);
	void addTemp(float);
	float getTemp(int);
	
	int getSize() const;
	string getID()const;
	float getMax(int,int);
	float getMin(int,int);
	float getAvg(int,int);
	int getCount(int,int)const;
};

#endif
