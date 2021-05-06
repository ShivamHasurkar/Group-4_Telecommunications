#ifndef COUNTRY_H
#define COUNTRY_H
//#include "ContactDetails.cpp"
#include AREA_H
#include <map>
#include <string>
using namespace std;

namespace country
{
    class Country
    {
    private:
        map<int, string> country;
        ContactDetails contactdetails;

    public:
        //default construcor
        Country();

        //parameterized constructor
        Country(map<int, string>, ContactDetails);

        //setting country
        void setCountry(int code, string name);

        //getting country with code
        string getCountryName(int code);

        //get all countries
        void printAllCountries();

        //updating country
        bool updateCountry(int oldcode, int newcode, string name);

        //deleting country
        //updating country
        bool deleteCountry(int code);

        //total countries
        int getCountryCount();

        //setting contact details
        void setContactDetails(ContactDetails);

        //getting contactdetails
        ContactDetails getContactDetails();
    };
} // namespace country
#endif
