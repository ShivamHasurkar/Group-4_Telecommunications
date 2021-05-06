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
        Countryoperations();
        Countryoperations(set<Country*>);
        bool addCountry(int countrycode, string countryname);
        set<Country*> displayCountries();
        int countryCount();
        bool updateCountry(int countrycode, int newcode, string countryname);
        bool deleteCountry(int countrycode);
    };
} // namespace countryoperations
#endif