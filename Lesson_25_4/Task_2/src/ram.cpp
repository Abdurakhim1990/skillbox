#include "ram.h"

int buffer[8];

void write(int numb, int count)
{
    buffer[count] = numb;
}

int read(int cout)
{
    return buffer[cout];
}
