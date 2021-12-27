#include <iostream>

using namespace std;

#define WAGON(fun, name)    fun ## _ ## name
#define NUMB_WAGONS         10

void fill_wagon(int * wagons);
void analisis_wagon(int * wagons);

int main()
{
    cout << "Task 2. Analysis of the occupancy of wagons on the train" << endl;
    int wagons[NUMB_WAGONS];
    WAGON(fill, wagon)(wagons);
    cout << endl;
    WAGON(analisis, wagon)(wagons);
    return 0;
}

void fill_wagon(int * wagons)
{
    for(int i = 0; i < NUMB_WAGONS; ++i){
        cout << "Enter the number of passengers in the " << i + 1 << " carriage: ";
        cin >> wagons[i];
    }
}

void analisis_wagon(int * wagons)
{
    for(int i = 0; i < NUMB_WAGONS; ++i){
        if(wagons[i] > 20)
            cout << "Extra passengers in the " << i + 1 << " car" << endl;
        else if(wagons[i] < 20){
            cout << "There are empty seats in the " << i + 1 << " carriage" << endl;
        }
    }
}
