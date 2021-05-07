#ifndef COUNTRY_H
#define COUNTRY_H
#include "ContactDetails.h"
#include <map>
#include <string>
using namespace std;


    class Country
    {
    private:
        map<int, string> country;
    public:
    
    
        ContactDetails *contactdetails=contactdetails->getInstance();

        //default construcor
        Country();
        static Country *instance;


        //parameterized constructor
        Country(map<int, string>);
        
        Country *getInstance();

        //setting country
        bool setCountry(int code, string name);

        //getting country with code
        bool searchCountry(int code);

        //get all countries
        void printAllCountries();

        //updating country
        bool updateCountry(int oldcode, int newcode, string name);

        //deleting country
        //updating country
        bool deleteCountry(int code);

        //total countries
        int getCountryCount();

        
    };
// namespace country
#endif
