#ifndef _SENSOR_H_INCLUDED_
#define _SENSOR_H_INCLUDED_

#include <cstdlib>
#include <iostream>
#include <string>
#include <array.h>

using namespace std;

class Sensor {
	string ID;
	Array<float> temp;

public:
	Sensor();
	Sensor(const string&);
	Sensor(const Sensor&);
	~Sensor();
	
	
	float getTemp(int);
	int getSize() const;
	const string& getID()const;
	void clear();
	void querry(ostream output,size_t,size_t);
	
	Sensor& operator+(const float);
	Sensor& operator=(const string&);
	Sensor& operator=(const Sensor&);
	bool compareName(string const &);
	friend std::ostream& operator<<(std::ostream&,const Sensor&);
	friend std::istream& operator>>(std::istream&,Sensor&);
};

#endif
