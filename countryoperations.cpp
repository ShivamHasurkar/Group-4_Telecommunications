#include "countryoperations.h"
#include "country.cpp"
#include <set>
using namespace countryoperations;
using namespace std;

//default constructor
Countryoperations::Countryoperations()
{
    this->countries = {};
}

//parameterized constructor
Countryoperations::Countryoperations(set<Country *> countries)
{
    this->countries = countries;
}

//adding country to the list
bool Countryoperations::addCountry(int countrycode, string countryname)
{
    try
    {
        Country *country = new Country();
        country->setCode(countrycode);
        country->setName(countryname);
        this->countries.insert(country);
    }
    catch (exception e)
    {
        return false;
    }
}

//displaying all the countries
set<Country *> Countryoperations::displayCountries()
{
    return this->countries;
}

//count of countries
int Countryoperations::countryCount()
{
    return this->countries.size();
}

//updating country 
bool Countryoperations::updateCountry(int countrycode, int newcode, string countryname)
{
    try
    {
        set<Country *>::iterator itr;

        for (itr = countries.begin(); itr != countries.end(); itr++)
        {
            if ((*itr)->getCode() == countrycode)
                (*itr)->setName(countryname);
        }
        return true;
    }
    catch (exception e)
    {
        return false;
    }
}

//deleting country from list
bool Countryoperations::deleteCountry(int countrycode)
{
    try
    {
        set<Country *>::iterator itr;

        for (itr = countries.begin(); itr != countries.end(); itr++)
        {
            if ((*itr)->getCode() == countrycode)
                countries.erase(itr);
        }
        return true;
    }
    catch (exception e)
    {
        return false;
    }
}
