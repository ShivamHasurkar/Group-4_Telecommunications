#ifndef Customer_H
#define Customer_H

#include<iostream>
#include<string>

class Customer{
private:
	std::string name;
	std::string address;
	std::string pincode;
	
public:
	Customer();
	Customer(std::string name);
	Customer(std::string name,std::string address);
	Customer(std::string name,std::string address,std::string pincode);

	std::string getName();
	void setName(std::string name);
	
	std::string getAddress();
	void setAddress(std::string address);
	
	std::string getPincode();
	void setPincode(std::string pincode);
};

#endif
