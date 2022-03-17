#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
//    time_t t = time(nullptr);
//    tm* local = localtime(&t);
//    cout << local->tm_hour << ":" << local->tm_min << endl;
//    cout << asctime(local) << endl;

//    cout << put_time(local, "%y/%m/%d") << endl;
//    cout << put_time(local, "%H:%M:%S") << endl;

//    tm local_get = *localtime(&t);
//    cin >> get_time(&local_get, "%H:%M");
//    cout << asctime(&local_get) << endl;

    time_t a = time(nullptr);
    int foo;
    cin >> foo;
    time_t b = time(nullptr);

    double d = difftime(b, a);
    d *= 10;
    time_t f = b + (time_t)d;
    tm* local_future = localtime(&f);
    cout << asctime(local_future) << endl;

    return 0;
}
