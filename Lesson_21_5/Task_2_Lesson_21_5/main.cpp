#include <iostream>
#include <vector>

using namespace std;

struct Construction{
    bool available = false;
    int square = 0;
};

struct Bath{
    bool available = false;
    bool chimney = false;
    int square = 0;
};

struct Floor{
    int height;
    Construction sleeping;
    Construction kitchen;
    Construction bathroom;
    Construction childroom;
    Construction livingroom;
};

struct House{
    vector<Floor> floor;
    bool chimney = false;
};

struct Piece{
    vector<House> house;
    Construction garage;
    Construction barn;
    Bath bath;
};

void recordVillageData(Piece& village);
void recordHouseData(House& house);
void recordFloorData(Floor& floor);
int setSquare(void);
bool availabilityBilding(string bild);
void countSqrVillage(Piece& village,  int& sum_sqr);
void countSqrHouse(House& house, int& sum_sqr);
void countSqrFloor(Floor& floor, int& sum_sqr);

int main()
{
    int parcels;
    cout << "Task 2. Data model for the village." << endl;
    cout << "Enter the number of parcels:";
    cin >> parcels;
    vector<Piece> village(parcels);
    for(int i = 0; i < parcels; ++i){
        cout << "\n===Parcel N" << i+1 << "===" << endl;
        recordVillageData(village[i]);
    }
    int sum_square = 0;
    for(int i = 0; i < village.size(); ++i){
        countSqrVillage(village[i], sum_square);
    }
    cout << "Summ square = " << sum_square << endl;
    return 0;
}

void recordVillageData(Piece& village)
{
    int num_hours;
    cout << "   Input the number of hours: ";
    cin >> num_hours;
    for(int i = 0; i < num_hours; ++i){
        House house;
        cout << "\n   ===House N" << i+1 << "===" << endl;
        recordHouseData(house);
        village.house.push_back(house);
    }
    village.garage.available = availabilityBilding("   Garage");
    if(village.garage.available){
        village.garage.square = setSquare();
    }
    village.barn.available = availabilityBilding("   Barn");
    if(village.barn.available){
        village.barn.square = setSquare();
    }
    village.bath.available = availabilityBilding("   Bath");
    if(village.bath.available){
        village.bath.square = setSquare();
        village.bath.chimney = availabilityBilding("      Chimney");
    }
}

void recordHouseData(House& house)
{
    int num_floor;
    cout << "      Input the number of floor: ";
    cin >> num_floor;
    for(int i = 0; i < num_floor; ++i){
        Floor floor;
        cout << "\n      ===Floor N" << i+1 << "===" << endl;
        recordFloorData(floor);
        house.floor.push_back(floor);
    }
    string chimney;
    cout << "      Input chimney yes/no: ";
    cin >> chimney;
    house.chimney = chimney == "yes";
}

void recordFloorData(Floor& floor)
{
    int height;
    cout << "         Input Height: ";
    cin >> height;
    floor.height = height;
    floor.sleeping.available = availabilityBilding("         Sleeping");
    if(floor.sleeping.available){
        cout << "      ";
        floor.sleeping.square = setSquare();
    }
    floor.kitchen.available = availabilityBilding("         Kitchen");
    if(floor.kitchen.available){
        cout << "      ";
        floor.kitchen.square = setSquare();
    }
    floor.bathroom.available = availabilityBilding("         Bathroom");
    if(floor.bathroom.available){
        cout << "      ";
        floor.bathroom.square = setSquare();
    }
    floor.childroom.available = availabilityBilding("         Childroom");
    if(floor.childroom.available){
        cout << "      ";
        floor.childroom.square = setSquare();
    }
    floor.livingroom.available = availabilityBilding("         Livingroom");
    if(floor.livingroom.available){
        cout << "      ";
        floor.livingroom.square = setSquare();
    }
}

int setSquare(void)
{
    int square;
    cout << "      Input square: ";
    cin >> square;
    return square;
}

bool availabilityBilding(string bild)
{
    string bilding;
    cout << bild << " yes/no: ";
    cin >> bilding;
    return (bilding == "yes");
}

void countSqrVillage(Piece& village,  int& sum_sqr)
{
    for(int i = 0; i < village.house.size(); ++i){
        countSqrHouse(village.house[i], sum_sqr);
    }
    sum_sqr += village.garage.square + village.barn.square + village.bath.square;
}

void countSqrHouse(House& house, int& sum_sqr)
{
    for(int i = 0; i < house.floor.size(); ++i){
        countSqrFloor(house.floor[i], sum_sqr);
    }
}

void countSqrFloor(Floor& floor, int& sum_sqr)
{
    sum_sqr += floor.sleeping.square + floor.kitchen.square + floor.bathroom.square
            + floor.childroom.square + floor.livingroom.square;
}
