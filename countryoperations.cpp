#include "countryoperations.h"
#include "country.cpp"
#include <set>
using namespace countryoperations;
using namespace std;

Countryoperations::Countryoperations()
{
    this->countries = {};
}
Countryoperations::Countryoperations(set<Country *> countries)
{
    this->countries = countries;
}
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

set<Country *> Countryoperations::displayCountries()
{
    return this->countries;
}
int Countryoperations::countryCount()
{
    return this->countries.size();
}
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