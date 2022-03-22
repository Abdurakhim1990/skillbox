#include "cpu.h"

void compute(void)
{
    int sum = 0;
    for(int i = 0; i < 8; ++i){
        sum += read(i);
    }
    cout << "Sum = " << sum << endl;
}
