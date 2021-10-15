#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Task_2. Fractional stitcher." << endl;
    string c;
    int k;
    cin >> k;
    c = to_string(k) + ".";
    cin >> k;
    c += to_string(k);
    cout << c << endl;
    return 0;
}
