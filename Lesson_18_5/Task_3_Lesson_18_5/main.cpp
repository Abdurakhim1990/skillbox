#include <iostream>

using namespace std;

int rec(int n, int step);

int main()
{
    int n;
    cin >> n;
    int step;
    cin >> step;
    cout << rec(n, step) << endl;
    return 0;
}

int rec(int n, int step)
{
    int a = 0;
    if(n == 0){
        return 1;
    } else if(n < 0){
        return 0;
    }
    for(int i = step; i > 0; --i){
        a += rec(n - i, step);
    }
    return a;
}
