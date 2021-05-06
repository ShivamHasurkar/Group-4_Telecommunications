#ifndef COUNTRY_H
#define COUNTRY_H
#include AREA_H
#include <set>
#include <vector>
#include <string>
using namespace std;

namespace country
{
    class Country
    {
    private:
        int isdcode;
        string name;
        set<Area *> areas;

    public:
        //default constructor
        Country();
        //parameterized constructor
        Country(int, string, set<Area *>);
        //setter for isdcode
        void setCode(int code);
        //getter for isdcode
        int getCode();
        //setter for name
        void setName(string name);
        //getter for name
        string getName();
        //setting list of area
        void setArea(Area *area);
        //getting list of area
        set<Area *> getAreas();
    };
} // namespace country
#endif
