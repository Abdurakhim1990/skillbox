#include <iostream>

using namespace std;

void Revers(int * rev, int size_rev);

int main()
{
    int mas[10] = {1, 2, 3, 4, 5, 6, 7 , 8, 9, 0};
    Revers(mas, sizeof (mas)/sizeof (int));
    for(int i = 0; i < sizeof (mas)/sizeof (int); ++i){
        cout << *(mas + i) << " ";
    }
    return 0;
}

void Revers(int * rev, int size_rev)
{
    int temp;
    for(int i = 0; i < size_rev/2; ++i){
        temp = *(rev + i);
        *(rev + i) = *(rev + size_rev - i - 1);
        *(rev + size_rev - i - 1) = temp;
    }
}
