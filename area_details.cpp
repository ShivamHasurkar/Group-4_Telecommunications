/*
 * area_details.cpp
 *
 *  Created on: 06-May-2021
 *      Author: saurabh
 */
 
#include"area_details.h"

area_details* area_details::getInstance() {
      if (!instance)
      instance = new area_details;
      return instance;
   }

	//Looping through Map to print all data elements
	bool area_details::print_all(){
		try{

			for (auto country : area_code) {
				for (auto city : country.second){
					cout << country.first << ":" << city.first << " -> " << city.second << endl;
					}
				}
			return true;
		}
		catch (exception &e){
			cout<<"Exception Caught: "<< e.what()<<endl;
			return false;
		}



	}


	//Inserting Data element into directory
	bool area_details::addCode(int CountryCode, int areaCode, string newAreaName ){

		try{
			for(auto country : area_code){
				if (CountryCode==country.first){
					area_code[CountryCode].emplace(areaCode, newAreaName);
					return true;
				}
			}
		}
		catch(exception &e){
			cout<<"Exception Caught: "<< e.what()<<endl;
			return false;
		}
	}




	//Creating a list and pushing into list l
	list<int> area_details::Search(int CountryCode){

		try{

			list<int> l;

			for (auto country : area_code) {
		        for (auto city : country.second){

		            l.push_back(city.first);
		        	}
		 	 	 }
		 	return l;

			}

		catch(exception &e){
			cout<<"Exception Caught: "<< e.what()<<endl;
			return {};
			}
	}



	//Counting every element present in the telephonedirectory
	int area_details::Count(){
		try{

			int count =0;
				for (auto country : area_code) {
					for (auto city : country.second){
							  count++;
					}
				}
			return count;
			}
		catch (exception &e)
			{
				cout<<"Exception Caught: "<< e.what()<<endl;
				return -1;
			}
		}


	//Counting every element present in the telephonedirectory
	int area_details::Count(int CountryCode){
		try{
			int count =0;
					for (auto country : area_code) {
						if (CountryCode == country.first){
							for (auto city : country.second){
							count++;
						}
						}
					}

					return count;

		}
		catch (exception &e){
			cout<<"Exception Caught: "<< e.what()<<endl;
			return -1;
		}
	}




	//new data elements which will be inserted
	bool area_details::update(int CountryCode,int areaCode){
		try{
			for(auto country : area_code){
				if (CountryCode==country.first){
					cout<<"Updating "<<CountryCode<<" "<<areaCode<<endl;
					int newAreaCode;
					string  newAreaName;
					cout<<"Enter newAreaCode"<<endl;
					cin>>newAreaCode;

					cout<<"Enter newAreaName"<<endl;
					cin>>newAreaName;

					for (auto country : area_code) {
						if (country.first==CountryCode){
									for (auto city : country.second){
										if (city.first==areaCode){
											area_code.erase(country.first);

											area_code[country.first].emplace(newAreaCode,newAreaName);
											cout << country.first << ":" << city.first << " -> " << city.second << endl;
											break;
										}

									}
						}
					}
					return true;
		}
		}
		}
		catch(exception &e){
			cout<<"Exception Caught: "<< e.what()<<endl;
					return false;
		}
	}



	//Deleting data and creating flag
	bool area_details::Delete(int CountryCode, int areaCode){
		try{
			bool del=0;
					for (auto country : area_code) {
								if (country.first==CountryCode){
									        for (auto city : country.second){
									        	if (city.first==areaCode){
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
					return true;
		}
		catch(exception &e){
			cout<<"Exception Caught: "<< e.what()<<endl;
			return false;
		}
	}

