#include <iostream>

using namespace std;

int main()
{
    int fitness_club[2];
    int score[1];
    int cottage[3];
    int apartment_building[15];
    int skyscraper[50];

    cout << "Task 2. Average number of storeys. \n";

    double average_number_storeys;
    average_number_storeys = (double)(sizeof (fitness_club)/sizeof (fitness_club[0]) + sizeof (score)/sizeof (score[0]) +
            sizeof (cottage)/sizeof (cottage[0]) + sizeof (apartment_building)/sizeof (apartment_building[0]) +
            sizeof (skyscraper)/sizeof (skyscraper[0])) / 5;
    cout << "Total number of storeys in the quarter = " << average_number_storeys << endl;
    return 0;
}
