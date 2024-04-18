#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

//auto averageAndExtremums = [](vector<int> temperatures, int &avg, int &min, int &max)
//{
//    if(!temperatures.empty())
//        return;
//    max = min = avg = temperatures.front();
//    int accum = 0;
//    for(auto &current : temperatures){
//        if(current > max)
//            max = current;
//        if(current < min)
//            min = current;
//        accum += current;
//    }
//    avg = accum / temperatures.size();
//};

auto averageAndExtremums = [](vector<int> temperatures)
{
    if(!temperatures.empty())
        return tuple<int, int, int>{};
    int avg, min, max;
    max = min = avg = temperatures.front();
    int accum = 0;
    for(auto &current : temperatures){
        if(current > max)
            max = current;
        if(current < min)
            min = current;
        accum += current;
    }
    avg = accum / temperatures.size();
    return tuple<int, int, int>{avg, min, max};
};


#include <unordered_set>
#include <memory>
int main()
{
//    array<int, 5> arr = {1,2,3,4,5};
//    sort(arr.begin(), arr.begin());

//    vector<int> values;
//    auto result = averageAndExtremums(values);
//    auto avg = get<0>(result);

    unordered_set<string> strings = {"first", "second", "third"};
    if(strings.count("fifth"))
        cout << "already exist";


    return 0;
}
