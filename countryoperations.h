#ifndef COUNTRYOPERATIONS_H
#define COUNTRYOPERATIONS_H
#include "country.h";
#include <set>
#include <string>
using namespace std;
using namespace country;

namespace countryoperations
{
    class Countryoperations
    {
    private:
        set<Country *> countries;

    public:
        //default constructor
        Countryoperations();
        //parameterized constructor
        Countryoperations(set<Country*>);
        //adding country
        bool addCountry(int countrycode, string countryname);
        //displaying all countries
        set<Country*> displayCountries();
        //total number of countries
        int countryCount();
        //updating country
        bool updateCountry(int countrycode, int newcode, string countryname);
        //deleting country from list
        bool deleteCountry(int countrycode);
    };
} // namespace countryoperations
#endif
