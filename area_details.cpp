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
   
void area_details::addCountry(int countrycode){
	try{
	map<int,map<int,string>> :: iterator it_out;
	it_out = area_code.find(countrycode);
	if(it_out==area_code.end()){
		map<int,string> map2;
		area_code.insert(std::pair<int,map<int,string>>(countrycode,map2));
	}
	}catch(std::exception &e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
}

void area_details::deleteCountry(int countrycode){
	try{
	map<int,map<int,string>> :: iterator it_out;
	it_out = area_code.find(countrycode);
	if(it_out!=area_code.end()){
		area_code.erase(countrycode);
	}
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
}


void area_details::updateCountrycode(int oldcountrycode,int newcountrycode){
	try{
	map<int,map<int,string>> :: iterator it_out;
	it_out = area_code.find(oldcountrycode);
	if(it_out!=area_code.end()){
		map<int,map<int,string>> :: iterator it_mid;
		it_mid = area_code.find(newcountrycode);
		if(it_mid==area_code.end()){
			map<int,string> m2=(*it_out).second;
			area_code.insert(std::pair<int,map<int,string>>(newcountrycode,m2));
			area_code.erase(oldcountrycode);
		}
	}
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
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
			map<int,map<int,string>>::iterator itr;
			itr=area_code.find(CountryCode);
			if(itr!=area_code.end()){
				map<int,string>::iterator iti;
				iti=(*itr).second.find(areaCode);
				if(iti==(*itr).second.end()){
					(*itr).second.insert(std::pair<int,std::string>(areaCode,newAreaName));
					contactdetails->addArea(CountryCode,areaCode);
					return true;
				}
			}
			return false;
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
											contactdetails->updateAreacode(CountryCode, areaCode,newAreaCode);
    
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
									        		cout<<"Deleted "<<country.first<<" "<<city.first;
									        		area_code.erase(country.first);
									        		contactdetails->deleteArea(CountryCode,areaCode);
            
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

