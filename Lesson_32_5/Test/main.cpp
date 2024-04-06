#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace std;

struct Record
{
    string name;
    string family;
    int age;
    bool married;
};

int main()
{
    Record record;
    ifstream file("record.json");

    nlohmann::json dict;
    file >> dict;
    record.name = dict["name"];
    record.family = dict["family"];
    record.age = dict["age"];
    record.married = dict["married"];
    cout << record.name << " " << record.family << " " << record.age << " " << record.married << endl;

    return 0;
}

/*
int main()
{
    Record record;
//    cin >> record.name >> record.family >> record.age >> record.married;
//    ofstream file("record.json");

    nlohmann::json dict = "{\"name\":\"Abdurakhim\"}"_json;
    record.name = dict["name"];
    cout << record.name;

//    nlohmann::json dict = {
//        {"name", record.name},
//        {"family", record.family},
//        {"age", record.age},
//        {"married", record.married}
//    };

//    nlohmann::json dict;
//    dict["name"] = record.name;
//    dict["family"] = record.family;
//    dict["age"] = record.age;
//    dict["married"] = record.married;

//    file << dict;
    return 0;
}*/
