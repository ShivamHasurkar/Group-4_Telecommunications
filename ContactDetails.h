#ifndef ContactDetails_H
#define ContactDetails_H

#include "Customer.h"
#include<map>

class ContactDetails{

public:
	typedef std::map<int, Customer*> Map3;
   	typedef std::map<int, Map3> Map2;
   	typedef std::map<int, Map2> Map1;
   	
   	Map1 contacts;
   	Map2 areas;
   	Map3 countries;
   	
   	
   	static ContactDetails *instance;
   	
   	static ContactDetails *getInstance();
   	
   	ContactDetails();
   	
	//add case 3
	bool addPhoneNumber(int countrycode, int areacode, int phoneNumber);
	
	//add case 4
	bool addCustomerDetails(int countrycode, int areacode, int phoneNumber, std::string name, std::string address, std::string pincode);
	
	//search case 3
	bool searchPhoneNumber(int countrycode, int areacode, int phoneNumber);
	
	//search case 4
	Customer *searchCustomerDetails(int countrycode, int areacode, int phoneNumber);
	
	//count case 4 return total count
	unsigned long long int countTotalPhoneNumbers();
	
	//count case 5 return count
	unsigned long long int countAllPhoneNumbers(int countrycode, int areacode);
	
	//update case 3
	bool updatePhoneNumber(int countrycode, int areacode, int oldPhoneNumber, int newPhoneNumber);
	
	//update case 4
	bool updateCustomerDetails(int countrycode, int areacode, int phoneNumber, std::string name, std::string address, std::string pincode);
	
	//delete case 3
	bool deletePhoneNumber(int countrycode, int areacode, int phoneNumber);
	
	//delete case 4
	bool deleteCustomerDetails(int countrycode, int areacode, int phoneNumber);
	
	
   	
	void addArea(int countrycode,int areacode);
	void deleteArea(int countrycode,int areacode);

	void updateAreacode(int countrycode,int oldareacode,int newareacode);
	
   	
   	void addCountry(int countrycode);

	void deleteCountry(int countrycode);


	void updateCountrycode(int oldcountrycode,int newcountrycode);

};

#endif
