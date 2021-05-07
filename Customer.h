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
	//default constructor
	Customer();
	//parameterized  constructor
	Customer(std::string name,std::string address,std::string pincode);
	
	//getter for name
	std::string getName();
	//setter for name
	void setName(std::string name);
	//getter for address
	std::string getAddress();
	//setter for address
	void setAddress(std::string address);
	//getter for pincode
	std::string getPincode();
	//setter for pincode
	void setPincode(std::string pincode);
	//display
	void display();
};

#endif
