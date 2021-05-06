#include "ContactDetails.h"
#include "Customer.h"
#include<iterator>

ContactDetails::ContactDetails(){}

ContactDetails* ContactDetails::getInstance() {
	if (!instance)
		instance = new ContactDetails;
	return instance;
}


bool ContactDetails::addPhoneNumber(int countrycode, int areacode, int phoneNumber){
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		Map2 :: iterator it_mid;
		it_mid = (*it_out).second.find(areacode);
		if(it_mid!=(*it_out).second.end()){
			Map3 :: iterator it_in;
			it_in=(*it_mid).second.find(phoneNumber);
			if(it_in==(*it_mid).second.end()){
				Customer *c=new Customer();
				(*it_mid).second.insert(std::pair<int,Customer*>(phoneNumber,c));
				return true;
			}
		}
	}
	return false;
}

bool ContactDetails::addCustomerDetails(int countrycode, int areacode, int phoneNumber, std::string name, std::string address, std::string pincode){
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		Map2 :: iterator it_mid;
		it_mid = (*it_out).second.find(areacode);
		if(it_mid!=(*it_out).second.end()){
			Map3 :: iterator it_in;
			it_in=(*it_mid).second.find(phoneNumber);
			if(it_in!=(*it_mid).second.end()){
				Customer *c=new Customer(name,address,pincode);
				(*it_in).second=c;
				return true;
			}
		}
	}
	return false;
}

bool ContactDetails::searchPhoneNumber(int countrycode, int areacode, int phoneNumber){
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		Map2 :: iterator it_mid;
		it_mid = (*it_out).second.find(areacode);
		if(it_mid!=(*it_out).second.end()){
			Map3 :: iterator it_in;
			it_in=(*it_mid).second.find(phoneNumber);
			if(it_in!=(*it_mid).second.end()){
				return true;
			}
		}
	}
	return false;
}

Customer* ContactDetails::searchCustomerDetails(int countrycode, int areacode, int phoneNumber){
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		Map2 :: iterator it_mid;
		it_mid = (*it_out).second.find(areacode);
		if(it_mid!=(*it_out).second.end()){
			Map3 :: iterator it_in;
			it_in=(*it_mid).second.find(phoneNumber);
			if(it_in!=(*it_mid).second.end()){
				return (*it_in).second;
			}
		}
	}
	return NULL;
}

unsigned long long int ContactDetails::countTotalPhoneNumbers(){
	unsigned long long int count=0;
	Map1 :: iterator it_out;
	for(it_out=contacts.begin();it_out!=contacts.end();it_out++){
		Map2 :: iterator it_mid;
		for(it_mid=(*it_out).second.begin();it_mid!=(*it_out).second.end();it_mid++){
			count+=(*it_mid).second.size();
		}
	}
	return count;
}

unsigned long long int ContactDetails::countAllPhoneNumbers(int countrycode, int areacode){
	unsigned long long int count=0;
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		Map2 :: iterator it_mid;
		it_mid = (*it_out).second.find(areacode);
		if(it_mid!=(*it_out).second.end()){
			count+=(*it_mid).second.size();
		}
	}
	return count;
}

bool ContactDetails::updatePhoneNumber(int countrycode, int areacode, int oldPhoneNumber, int newPhoneNumber){
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		Map2 :: iterator it_mid;
		it_mid = (*it_out).second.find(areacode);
		if(it_mid!=(*it_out).second.end()){
			Map3 :: iterator it_in;
			it_in=(*it_mid).second.find(oldPhoneNumber);
			if(it_in!=(*it_mid).second.end()){
				Map3 :: iterator it_inn;
				it_inn=(*it_mid).second.find(newPhoneNumber);
				if(it_inn==(*it_mid).second.end()){
					Customer *c=(*it_in).second;
					(*it_mid).second.insert(std::pair<int,Customer*>(newPhoneNumber,c));
					(*it_mid).second.erase(it_in);
					return true;
				}
			}
		}
	}
	return false;
}

bool ContactDetails::updateCustomerDetails(int countrycode, int areacode, int phoneNumber, std::string name, std::string address, std::string pincode){
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		Map2 :: iterator it_mid;
		it_mid = (*it_out).second.find(areacode);
		if(it_mid!=(*it_out).second.end()){
			Map3 :: iterator it_in;
			it_in=(*it_mid).second.find(phoneNumber);
			if(it_in!=(*it_mid).second.end()){
				Customer *c=new Customer(name,address,pincode);
				(*it_in).second=c;
				return true;
			}
		}
	}
	return false;
}

bool ContactDetails::deletePhoneNumber(int countrycode, int areacode, int phoneNumber){
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		Map2 :: iterator it_mid;
		it_mid = (*it_out).second.find(areacode);
		if(it_mid!=(*it_out).second.end()){
			Map3 :: iterator it_in;
			it_in=(*it_mid).second.find(phoneNumber);
			if(it_in!=(*it_mid).second.end()){
				(*it_mid).second.erase(phoneNumber);
			}
		}
	}
	return false;
}

bool ContactDetails::deleteCustomerDetails(int countrycode, int areacode, int phoneNumber){
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		Map2 :: iterator it_mid;
		it_mid = (*it_out).second.find(areacode);
		if(it_mid!=(*it_out).second.end()){
			Map3 :: iterator it_in;
			it_in=(*it_mid).second.find(phoneNumber);
			if(it_in!=(*it_mid).second.end()){
				Customer *c=new Customer();
				(*it_in).second=c;
				std::cout<<(*it_in).first<<std::endl;
				return true;
			}
		}
	}
	return false;
}


