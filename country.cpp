#include "country.h"
using namespace country;

Country ::Country()
{
    this->name = "";
    this->isdcode = 0;
    this->areas = {};
}
Country ::Country(int code, string name, set<Area *> areas)
{
    this->name = name;
    this->isdcode = code;
    this->areas = areas;
}
void Country ::setCode(int isdcode)
{
    this->isdcode = isdcode;
}
int Country ::getCode()
{
    return this->isdcode;
}
void Country ::setName(string name)
{
    this->name = name;
}
string Country ::getName()
{
    return this->name;
}
void Country ::setArea(Area *area)
{
    this->areas.insert(area);
}
set<Area *> Country ::getAreas()
{
    return this->areas;
}