#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    cout << "Task_3. Calculator." << endl;
    string text;
    double num_1 = 0;
    double num_2 = 0;
    char action = 0;
    cout << "Enter string for calculator: ";
    cin >> text;
    stringstream textstream(text);
    textstream >> num_1 >> action >> num_2;
    double result;
    result = ((action == '+') * (num_1 + num_2) + (action == '-') * (num_1 - num_2) +
            (action == '*') * (num_1 * num_2) + (action == '/') * (num_1 / num_2));
    cout << result << endl;
    return 0;
}
