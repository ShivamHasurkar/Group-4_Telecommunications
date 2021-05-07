#include "ContactDetails.h"
#include "Customer.h"
#include<iterator>

ContactDetails::ContactDetails(){}

ContactDetails* ContactDetails::getInstance() {
	if (!instance)
		instance = new ContactDetails;
	return instance;
}

void ContactDetails::addCountry(int countrycode){
	try{
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out==contacts.end()){
		Map2 map2;
		contacts.insert(std::pair<int,Map2>(countrycode,map2));
	}
	}catch(std::exception &e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
}

void ContactDetails::deleteCountry(int countrycode){
	try{
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		contacts.erase(countrycode);
	}
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
}

void ContactDetails::updateCountrycode(int oldcountrycode,int newcountrycode){
	try{
	Map1 :: iterator it_out;
	it_out = contacts.find(oldcountrycode);
	if(it_out!=contacts.end()){
		Map1 :: iterator it_mid;
		it_mid = contacts.find(newcountrycode);
		if(it_mid==contacts.end()){
			Map2 m2=(*it_out).second;
			contacts.insert(std::pair<int,Map2>(newcountrycode,m2));
			contacts.erase(oldcountrycode);
		}
	}
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
}

void ContactDetails::addArea(int countrycode,int areacode){
	try{
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		Map2 :: iterator it_mid;
		it_mid = (*it_out).second.find(areacode);
		if(it_mid==(*it_out).second.end()){
			Map3 m3;
			(*it_out).second.insert(std::pair<int,Map3>(areacode,m3));
		}
	}
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
}

void ContactDetails::deleteArea(int countrycode,int areacode){
	try{
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		Map2 :: iterator it_mid;
		it_mid = (*it_out).second.find(areacode);
		if(it_mid!=(*it_out).second.end()){
			(*it_out).second.erase(areacode);
		}
	}
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
}

void ContactDetails::updateAreacode(int countrycode,int oldareacode,int newareacode){
	try{
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		Map2 :: iterator it_mid;
		it_mid = (*it_out).second.find(oldareacode);
		if(it_mid!=(*it_out).second.end()){
			Map2 :: iterator it_midd;
			it_midd = (*it_out).second.find(newareacode);
			if(it_midd==(*it_out).second.end()){
				Map3 m3=(*it_mid).second;
				(*it_out).second.insert(std::pair<int,Map3>(newareacode,m3));
				(*it_out).second.erase(oldareacode);
			}
		}
	}
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
}

void ContactDetails::printMaps(){
	try{
	Map1 :: iterator it_out;
	for(it_out=contacts.begin();it_out!=contacts.end();it_out++){
		std::cout<<(*it_out).first<<std::endl;
		Map2:: iterator it_mid;
		for(it_mid=(*it_out).second.begin();it_mid!=(*it_out).second.end();it_mid++){
		std::cout<<(*it_out).first<<":"<<(*it_mid).first<<std::endl;
			Map3:: iterator it_in;
			for(it_in=(*it_mid).second.begin();it_in!=(*it_mid).second.end();it_in++){
				std::cout<<(*it_out).first<<":"<<(*it_mid).first<<":"<<(*it_in).first<<std::endl;
			}
		}
	}
	}
	catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
}

bool ContactDetails::addPhoneNumber(int countrycode, int areacode, int phoneNumber){
	try{
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
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
	return false;
}

bool ContactDetails::addCustomerDetails(int countrycode, int areacode, int phoneNumber, std::string name, std::string address, std::string pincode){
	try{
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
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
	return false;
}

bool ContactDetails::searchPhoneNumber(int countrycode, int areacode, int phoneNumber){
	try{
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
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
	std::cout<<false<<std::endl;
	return false;
}

Customer* ContactDetails::searchCustomerDetails(int countrycode, int areacode, int phoneNumber){
	try{
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
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
	return NULL;
}

unsigned long long int ContactDetails::countTotalPhoneNumbers(){
	unsigned long long int count=0;
	try{
	Map1 :: iterator it_out;
	for(it_out=contacts.begin();it_out!=contacts.end();it_out++){
		Map2 :: iterator it_mid;
		for(it_mid=(*it_out).second.begin();it_mid!=(*it_out).second.end();it_mid++){
			count+=(*it_mid).second.size();
		}
	}
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
	return count;
}

unsigned long long int ContactDetails::countAllPhoneNumbers(int countrycode, int areacode){
	unsigned long long int count=0;
	try{
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		Map2 :: iterator it_mid;
		it_mid = (*it_out).second.find(areacode);
		if(it_mid!=(*it_out).second.end()){
			count+=(*it_mid).second.size();
		}
	}
	}catch(std::exception e)
	{
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
	return count;
}

bool ContactDetails::updatePhoneNumber(int countrycode, int areacode, int oldPhoneNumber, int newPhoneNumber){
	try{
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
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
	return false;
}

bool ContactDetails::updateCustomerDetails(int countrycode, int areacode, int phoneNumber, std::string name, std::string address, std::string pincode){
	try{
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
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
	return false;
}

bool ContactDetails::deletePhoneNumber(int countrycode, int areacode, int phoneNumber){
	try{
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
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
	return false;
}

bool ContactDetails::deleteCustomerDetails(int countrycode, int areacode, int phoneNumber){
	try{
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
	}catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
	return false;
}

std::list<int> ContactDetails::printPhoneNumber(int countrycode, int areacode, int phoneNumber){
	std::list<int> l;
	try{
	Map1 :: iterator it_out;
	it_out = contacts.find(countrycode);
	if(it_out!=contacts.end()){
		Map2 :: iterator it_mid;
		it_mid = (*it_out).second.find(areacode);
		if(it_mid!=(*it_out).second.end()){
			Map3 :: iterator it_in;
			for(it_in=(*it_mid).second.begin();it_in!=(*it_mid).second.end();it_in++){
				l.push_back((*it_in).first);
			}
		}
	}
	}
	catch(std::exception e){
		std::cout<<"Exception Caught: "<< e.what()<<std::endl;
	}
	return l;
			
}
   	
/*
ContactDetails *ContactDetails::instance = 0;

int main(){
	ContactDetails *c=c->getInstance();
	c->addCountry(20);
	c->addArea(20,30);
	c->addPhoneNumber(20,30,40);
	std::cout<<c->countTotalPhoneNumbers()<<std::endl;
}
*/
