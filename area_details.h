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
using namespace std;
class area_details{

	map<int,map<int,string>> area_code;
	map<int,map<int,string>>::iterator itr;
	map<int,int>::iterator otr;
public:
	void print_all();
	void addCode(int CountryCode, int areaCode, string newAreaName );

	list<int> Search(int CountryCode);

	int Count();
	int Count(int CountryCode);

	void update(int CountryCode,int areaCode);

	void Delete(int CountryCode, int areaCode);

};

#endif /* AREA_DETAILS_H_ */
