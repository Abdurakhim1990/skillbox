#include <iostream>

using namespace std;

template<typename T>
void input(T array[8])
{
    std::cout << "Fill the array (8):";
    for (int i = 0; i < 8; ++i)
    {
        cin >> array[i];
    }
    cout << endl;
}

template<typename T>
T average(T array[8])
{
    T aver = 0;
    for (int i = 0; i < 8; ++i)
    {
        aver +=  array[i];
    }
    return aver /= 8;
}

int main()
{
    double arr[8];
    input(arr);
    cout << average(arr);
    return 0;
}
