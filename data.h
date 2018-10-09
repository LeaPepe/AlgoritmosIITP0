// doubleemplate de arreglo dinamico

#ifndef DAdoubleA_H
#define DAdoubleA_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Data{
public:
	Data();
	Data(const double&); 
	Data(const Data&); 
	~Data();
	
	void clear();
	bool exist()const;
	double getData()const;
	void setData(const double&);
	
	bool operator==(const Data&)const; 
	bool operator!=(const Data&)const; 
	bool operator>(const Data&)const;
	bool operator<(const Data&)const;
	Data& operator=(const Data&); 
	Data& operator+(const Data&); 
	Data& operator-(const Data&); 
	Data& operator/(const Data&); 
	Data& operator*(const Data&);
	bool operator>(const Data&);
	bool operator<(const Data&);
	
	bool operator==(const double&)const; 
	bool operator!=(const double&)const; 
	bool operator>(const double&);
	bool operator<(const double&);
	Data& operator=(const double&); 
	Data& operator+(const double&); 
	Data& operator-(const double&); 
	Data& operator/(const double&); 
	Data& operator*(const double&); 

	
	friend std::ostream& operator<<(std::ostream&,const Data&);

private:
	double data_;
	bool exist_;
};


#endif
