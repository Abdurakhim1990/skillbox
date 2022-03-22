#include "kbd.h"

void inputNumbers(void)
{
    int number;
    for(int i = 0; i < 8; ++i){
        cout << "Input " << i << " element" << endl;
        cin >> number;
        write(number, i);
    }
}
