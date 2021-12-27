#include <iostream>

using namespace std;

#define SPRING
//#define SUMMER
//#define AUTUMN
//#define WINTER

int main()
{
    cout << "Task 3. Conclusion of the time of year" << endl;
#ifdef SPRING
    cout << "SPRING" << endl;
#endif
#ifdef SUMMER
    cout << "SUMMER" << endl;
#endif
#ifdef AUTUMN
    cout << "AUTUMN " << endl;
#endif
#ifdef WINTER
    cout << "WINTER" << endl;
#endif
    return 0;
}
