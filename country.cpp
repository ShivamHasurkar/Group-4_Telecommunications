#include "country.h"
using namespace country;


//default constructor
Country ::Country()
{
    this->name = "";
    this->isdcode = 0;
    this->areas = {};
}

//parameterized constructor
Country ::Country(int code, string name, set<Area *> areas)
{
    this->name = name;
    this->isdcode = code;
    this->areas = areas;
}
//setter for code
void Country ::setCode(int isdcode)
{
    this->isdcode = isdcode;
}
//getter for code
int Country ::getCode()
{
    return this->isdcode;
}

//settter for name
void Country ::setName(string name)
{
    this->name = name;
}

//getter for name
string Country ::getName()
{
    return this->name;
}
//creating list of area
void Country ::setArea(Area *area)
{
    this->areas.insert(area);
}

//getting list of area
set<Area *> Country ::getAreas()
{
    return this->areas;
}
