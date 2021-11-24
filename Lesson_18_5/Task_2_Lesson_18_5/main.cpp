#include <iostream>

using namespace std;

int rec(int n);

int main()
{
    int n;
    cin >> n;
    cout << rec(n) << endl;
    return 0;
}

int rec(int n)
{
    if(n == 0){
        return 1;
    } else if(n < 0){
        return 0;
    }
    return rec(n - 1) + rec(n - 2) + rec(n - 3);
}
