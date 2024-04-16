#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Part
{

};

class Tool
{
public:
    Tool(initializer_list<Part> parts)
    {
        mParts = parts;
    }

private:
    vector<Part> mParts;
};



class GeoPoint
{
public:
    GeoPoint(float longitude, float latitude)
        :mLon(longitude), mLat(latitude){}
private:
    float mLon, mLat;
};

class Route
{
public:
    Route(initializer_list<GeoPoint> points)
        :mPoints(points){}
private:
    vector<GeoPoint> mPoints;
};



class Unit
{
public:
    double height()
    {
        return h;
    }

    void begin()
    {

    }

    void end()
    {

    }

private:
    double h;
};

bool compareBeHeight(Unit &unit1, Unit& unit2)
{
    return unit1.height() < unit2.height();
}


int main()
{
//    int x[] = {5,6,7};
//    Tool t = {Part(), Part()};
//    vector<int> v = {1,2,3};

//    GeoPoint point1{50, 30};
//    auto route = Route{point1, {30, 40}, {30.5, 41}, {31, 55}};


//    vector<Unit> units;
//    //sort(units.begin(), units.end(), compareBeHeight);
//    sort(units.begin(), units.end(), [](Unit &unit1, Unit& unit2)
//    {
//        return unit1.height() < unit2.height();
//    }
//    );

    auto teleport = [](Unit &unit)
    {
        auto man = static_cast<Human*>(&unit);
        if(man)
            man->setGeoPos(random(), random());
    };

    vector<Unit> warriors;
    for_each(warriors.begin(), warriors.end(), teleport);

    return 0;
}

