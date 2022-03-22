#include "gpu.h"

void consoleOutput(void)
{
    for(int i = 0; i < 8; ++i){
        cout << read(i) << "  ";
    }
    cout << endl;
}
