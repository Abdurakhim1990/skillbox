#include <iostream>

using namespace std;

void Swap(int * a, int * b);

int main()
{
    int a = 10;
    int b = 20;
    Swap(&a, &b);
    cout << a << " " << b << endl;
    return 0;
}

void Swap(int * a, int * b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
