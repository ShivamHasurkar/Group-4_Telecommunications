/*
/*
 * area_details.h
 *
 *  Created on: 06-May-2021
 *      Author: saurabh
 */

#ifndef AREA_DETAILS_H_
#define AREA_DETAILS_H_
#include<iostream>
#include<string>
#include<map>
#include<list>
#include "ContactDetails.h"
using namespace std;
class area_details{

	map<int,map<int,string>> area_code;
	map<int,map<int,string>>::iterator itr;
	map<int,int>::iterator otr;
public:
	
	static area_details *instance;

	area_details *getInstance();
	
	ContactDetails *contactdetails=contactdetails->getInstance();

	
	bool print_all();
	//adding code
	bool addCode(int CountryCode, int areaCode, string newAreaName );
	//searching area as per countrycode and area code
	bool Search(int CountryCode,int areaCode);
	//count total areas
	int Count();
	//count total areas country wise
	int Count(int CountryCode);
	//updating area with countrycode and areacode
	bool update(int CountryCode,int areaCode);
	//adding country
	void addCountry(int countrycode);
	//deleting country
	void deleteCountry(int countrycode);
	//updating country
	void updateCountrycode(int oldcountrycode,int newcountrycode);
	//deleting area with country and areacode
	bool Delete(int CountryCode, int areaCode);

};

#endif /* AREA_DETAILS_H_ */

