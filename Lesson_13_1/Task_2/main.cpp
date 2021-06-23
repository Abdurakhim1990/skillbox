#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[n];
    }
    float real;
    for(int i = n; i > 0; i--){
        real = arr[n-1];
        cout << real << " ";
    }
    return 0;
}
