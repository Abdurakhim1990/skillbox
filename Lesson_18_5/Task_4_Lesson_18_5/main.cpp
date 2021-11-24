#include <iostream>

using namespace std;

void Evendigits(long long n, int & ans);

int main()
{
    int ans = 0;
    long long n = 1223372036854775806;
    Evendigits(n, ans);
    cout << ans << endl;
    return 0;
}

void Evendigits(long long n, int & ans)
{
    ans += (n%10 + 1)%2;
    if(n >= 10){
        Evendigits(n/10, ans);
    }
}
