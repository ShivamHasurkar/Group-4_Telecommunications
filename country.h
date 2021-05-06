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
        Country();
        Country(int, string, set<Area *>);
        void setCode(int code);
        int getCode();
        void setName(string name);
        string getName();
        void setArea(Area *area);
        set<Area *> getAreas();
    };
} // namespace country
#endif
