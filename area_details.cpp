/*
 * area_details.cpp
 *
 *  Created on: 06-May-2021
 *      Author: saurabh
 */
#include"area_details.h"

	void area_details::print_all(){
		//Looping through Map to print all data elements
		for (auto country : area_code) {
				        for (auto city : country.second){
				            cout << country.first << ":" << city.first << " -> " << city.second << endl;
				        }
				 }

	}
	void area_details::addCode(int CountryCode, int areaCode, string newAreaName ){
		//Inserting Data element into directory
		area_code[CountryCode].emplace(areaCode, newAreaName);

	}

	list<int> area_details::Search(int CountryCode){
		list<int> l;
		 for (auto country : area_code) {
		        for (auto city : country.second){
		            //Creating a list and pushing into list l
		            l.push_back(city.first);
		        }
		 }
		 return l;
	}
	int area_details::Count(){
		int count =0;
		for (auto country : area_code) {
				        for (auto city : country.second){
				            //Counting every element present in the telephonedirectory 
				            count++;
				        }
				 }
		return count;
	}
	int area_details::Count(int CountryCode){
		int count =0;
		for (auto country : area_code) {
			if (CountryCode == country.first){
				for (auto city : country.second){
				//Counting only elements with given country name
				count++;
			}
			}
		}

		return count;
	}

	void area_details::update(int CountryCode,int areaCode){
		cout<<"Updating "<<CountryCode<<" "<<areaCode<<endl;
		//new data elements which will be inserted
		int newAreaCode;
		string  newAreaName;
		cout<<"Enter new AreaCode";
		cin>>newAreaCode;
		cout<<"Enter new Area Name";
		cin>>newAreaName;
		for (auto country : area_code) {
			if (country.first==CountryCode){
				        for (auto city : country.second){
				        	if (city.first==areaCode){
							//Erasing data to be Updated
				        		area_code.erase(country.first);
							//Inserting new data element
				        		area_code[country.first].emplace(newAreaCode,newAreaName);
				        		cout << country.first << ":" << city.first << " -> " << city.second << endl;

				        	}

				        }
			}
		}
	}

	void area_details::Delete(int CountryCode, int areaCode){
		bool del=0;
		for (auto country : area_code) {
					if (country.first==CountryCode){
						        for (auto city : country.second){
						        	if (city.first==areaCode){
						        		//Deleting data and creating flag
									del=1;
						        		area_code.erase(country.first);
						        		cout<<"Deleted "<<country.first<<" "<<city.first;
						        	}

						        }
					}
		}
		if (del==0){
			cout<<CountryCode<<" "<<areaCode<<" Not Found";
		}
	}

