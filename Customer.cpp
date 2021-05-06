#include "Customer.h"

Customer::Customer(){
	this->name="";
	this->address="";
	this->pincode="";
}

Customer::Customer(std::string name, std::string address,std::string pincode){
	this->name=name;
	this->address=address;
	this->pincode=pincode;
}

std::string Customer::getName(){
	return this->name;
}

void Customer::setName(std::string name){
	this->name=name;
}

std::string Customer::getAddress(){
	return this->address;
}

void Customer::setAddress(std::string address){
	this->address=address;
}

std::string Customer::getPincode(){
	return this->pincode;
}

void Customer::setPincode(std::string pincode){
	this->pincode=pincode;
}
