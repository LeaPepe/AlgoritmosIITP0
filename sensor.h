#ifndef _SENSOR_H_INCLUDED_
#define _SENSOR_H_INCLUDED_

#include <iostream>

class sensor {
	int samples;
	string ID;
	array temperature;
public:
	sensor();
	sensor(char*);
	~sensor();
	void setID(string);
	void addTemp(int);
	int& getTemp(int)const;
	string getID()const;
	int getMax(int const &,int const &)const;
	int getMin(int const &,int const &)const;
	int getAvg(int const &,int const &)const;
	Array getQuerry(int const &,int const &)const; //devuelve avg,min,max,cantidad de muestras
};

#endif
