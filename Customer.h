#ifndef Customer
#define Customer

#include<string>

class Customer{
private:
	string name;
	string address;
	string pincode;
	
public:
	Customer();
	Customer(name);
	Customer(name,address);
	Customer(name,address,pincode);

	string getName();
	void setName(string name);
	
	string getAddress();
	void setAddress(string address);
	
	string getPincode();
	void setPincode(string pincode);
}

#endif
