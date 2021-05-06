#ifndef ContactDetails_H
#define ContactDetails_H

#include "Customer.h"
#include<map>

class ContactDetails{

public:
	typedef std::map<int, Customer> Map3;
   	typedef std::map<int, Map3> Map2;
   	typedef std::map<int, Map2> Map1;
   	
   	Map1 contacts;
   	
	//add case 3
	bool addPhoneNumber(int countrycode, int areacode, int phoneNumber);
	
	//add case 4
	bool addCustomerDetails(int countrycode, int areacode, int phoneNumber, std::string name, std::string address, std::string pincode);
	
	//search case 3
	bool searchPhoneNumber(int countrycode, int areacode, int phoneNumber);
	
	//search case 4
	Customer searchCustomerDetails(int countrycode, int areacode, int phoneNumber);
	
	//count case 4 return total count
	unsigned long long int countTotalPhoneNumbers();
	
	//count case 5 return count
	unsigned long long int countAllPhoneNumbers(int countryCode, int areaCode);
	
	//update case 3
	bool updatePhoneNumber(int countryCode, int AreaCode, int phoneNumber);
	
	//update case 4
	bool updateCustomerDetails(int countryCode, int AreaCode, int phoneNumber);
	
	//delete case 3
	bool deletePhoneNumber(int countrycode, int areacode, int phoneNumber);
	
	//delete case 4
	bool deleteCustomerDetails(int countryCode, int AreaCode, int phoneNumber);

};

#endif
