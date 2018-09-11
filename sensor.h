#ifndef _SENSOR_H_INCLUDED_
#define _SENSOR_H_INCLUDED_

#include <iostream>

class sensor {
	int size;
	string ID;
	array temperature;
public:
	sensor();
	sensor(char*);
	~sensor();
	void setID(string);
	void addTemp(int);
	int getTemp(int)const;
	
	int getSize() const;
	string getID()const;
	int getMax(int,int)const;
	int getMin(int,int)const;
	int getAvg(int,int)const;
	int getCount(int,int)const;
};

#endif
