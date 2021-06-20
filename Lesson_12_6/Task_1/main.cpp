#include <iostream>

using namespace std;

int main()
{
    bool tiny[1];
    bool small[2];
    bool middle[3];
    bool large[4];
    cout << "Task 1. Ships in the \"Sea battle\" \n";
    cout << "Tiny ship size - " << sizeof(tiny)/sizeof (tiny[0]) << endl;
    cout << "Small ship size - " << sizeof(small)/sizeof (small[0]) << endl;
    cout << "Medium ship size - " << sizeof(middle)/sizeof (middle[0]) << endl;
    cout << "Large ship size - " << sizeof(large)/sizeof (large[0]) << endl;
    return 0;
}
