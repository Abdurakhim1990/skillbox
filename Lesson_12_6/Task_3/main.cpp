#include <iostream>

using namespace std;

int main()
{
    cout << "Task 3. Level of self-isolation" << endl;
    int number_residents[5];
    int total_number;
    cout << "Input the total number of people in the house: ";
    cin >> total_number;
    int sum = 0;
    for(int i = 0; i < sizeof (number_residents)/sizeof (number_residents[0]); i++)
    {
        cout << "Input the number of people on the " << i + 1 << " floor: ";
        cin >> number_residents[i];
        sum += number_residents[i];
    }
    cout << "The general level of self-isolation in the house = " << (double)(sum * 100) / total_number << endl;
    return 0;
}
