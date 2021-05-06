#include "country.h"
#include <map>
#include <string>
#include <iostream>
//#include "ContactDetails..cpp"
using namespace country;
using namespace std;

//Default constructor
Country::Country()
{
    this->country = {};
}

//parameterized constructor
Country::Country(map<int, string> country)
{
    this->country = country;
}

//setting country
void Country::setCountry(int code, string name)
{
    this->country.insert({code, name});
    contactdetails->addCountry(code);
}

//getter for countryname
string Country::getCountryName(int code)
{
    auto itr = this->country.find(code);
    return (*itr).second;
}

//getting all countries
void Country::printAllCountries()
{
    for (auto itr : this->country)
    {
        cout << itr.first << " : " << itr.second;
    }
}

//count of all countries
int Country::getCountryCount()
{
    return this->country.size();
}

//updating country
bool Country::updateCountry(int oldcode, int newcode, string name)
{
    try
    {

        auto itr = this->country.find(oldcode);
        itr->first = newcode;
        itr->second = name;
    }
    catch (exception exception)
    {
        return false;
    }
    contactdetails->updateCountrycode(oldcode,newcode);
    return true;
}

//deleting country
bool Country ::deleteCountry(int code)

{
    try
    {
        int result = this->country.erase(code);
        if (result)
        {
        	contactdetails->deleteCountry(code);
            return true;
          }
    }
    catch (exception exception)
    {
        return false;
    }
    return false;
}

//setting contactdetails
void Country ::setContactDetails(ContactDetails contactdetails)
{
    this->contactdetails = contactdetails;
}
//getting contactdetails
ContactDetails Country ::getContactDetails()
{
    return this->contactdetails;
}
