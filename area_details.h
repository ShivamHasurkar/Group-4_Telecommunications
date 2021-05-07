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
	bool addCode(int CountryCode, int areaCode, string newAreaName );

	list<int> Search(int CountryCode);

	int Count();
	int Count(int CountryCode);

	bool update(int CountryCode,int areaCode);

	bool Delete(int CountryCode, int areaCode);

};

#endif /* AREA_DETAILS_H_ */

