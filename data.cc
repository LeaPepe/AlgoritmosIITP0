#include<data.h>
#include <cstdlib>
#include <iostream>

using namespace std;

//Constructores y destructor
Data::Data(){
	data_ = 0;
	exist_ = false;
}
Data::Data(const Data& data){
	data_ = data.getData();
	exist_ = data.exist();
} 
Data::Data(const double& data){
	data_ = data;
	exist_ = true;
} 
Data::~Data(){
	
}

//metodos
void Data::clear(){
	data_ = 0;
	exist_ = false;
} 
bool Data::exist()const{
	return exist_;
}
double Data::getData()const{
	return data_;
}
void Data::setData(const double& data){
	data_ = data;
	exist_ = true;
}
//Operaciones nativas
bool Data::operator>(const Data& data){
	if(data_ > data.data_ && exist_ == data.exist()){
		return true;
	}
	return false;
}
bool Data::operator<(const Data& data){
	if(data_ < data.data_ && exist_ == data.exist()){
		return true;
	}
	return false;
} 
bool Data::operator==(const Data& data)const{
	if(data_ == data.data_ && exist_ == data.exist()){
		return true;
	}
	return false;
} 
bool Data::operator!=(const Data& data)const{
	if (data_ == data.data_ && exist_ == data.exist_){
		return false;
	}
	return true;
}  
Data& Data::operator=(const Data& data){
	data_ = data.getData();
	exist_ = data.exist();
	return *this;
}  
Data& Data::operator+(const Data& data){
	data_ += data.getData();
	if(data.exist() == true)
		exist_ = true;
	return *this;
}  
Data& Data::operator-(const Data& data){
	data_ -= data.getData();
	if(data.exist() == true)
		exist_ = true;
	return *this;
}  
Data& Data::operator/(const Data& data){
	data_ /= data.getData();
	if(data.exist() == true)
		exist_ = true;
	return *this;
}  
Data& Data::operator*(const Data& data){
	data_ *= data.getData();
	if(data.exist() == true)
		exist_ = true;
	return *this;
} 

bool Data::operator==(const double& data)const{
	if(data_ == data && exist_ == true){
		return true;
	}
	return false;
} 
bool Data::operator!=(const double& data)const{
	if ((data_ == data) && (exist_ == true)){
		return false;
	}
	return true;
} 
bool Data::operator>(const double& data){
	if(data_ > data){
		return true;
	}
	return false;
}
bool Data::operator<(const double& data){
	if(data_ < data){
		return true;
	}
	return false;
} 	
Data& Data::operator=(const double& data){
	data_ = data;
	exist_ = true;
	return *this;
}  
Data& Data::operator+(const double& data){
	data_ += data;
	exist_ = true;
	return *this;
}  
Data& Data::operator-(const double& data){
	data_ -= data;
	exist_ = true;
	return *this;
}  
Data& Data::operator/(const double& data){
	if (data == 0)
		std::exit(1);
	data_ /= data;
	exist_ = true;
	return *this;
}  
Data& Data::operator*(const double& data){
	data_ *= data;
	exist_ = true;
	return *this;
} 
std::ostream& operator<<(std::ostream& os,const Data& data){
	if(data.exist() == false){
		os << "NoData";
	}else{
		os << data.getData();
	}
	return os;
}