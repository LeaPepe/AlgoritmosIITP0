#ifndef _SENSOR_H_INCLUDED_
#define _SENSOR_H_INCLUDED_

#include <cstdlib>
#include <iostream>
//#include <string>
#include <array.h>

using namespace std;

class Sensor {
	string ID;
	Array<double> data;
public:
	Sensor();
	Sensor(const string&);
	Sensor(const Sensor&);
	~Sensor();
	
	double getData(int);
	int getSize() const;
	const string& getID()const;
	void clear();
	void querry(ostream&,int,int);
	
	Sensor& operator+(const double);
	Sensor& operator+(const Sensor&);
	Sensor& operator=(const string&);
	Sensor& operator=(const Sensor&);
	bool operator==(const Sensor&);
	
	friend std::ostream& operator<<(std::ostream&,const Sensor&);
	friend std::istream& operator>>(std::istream&,Sensor&);
};

#endif
