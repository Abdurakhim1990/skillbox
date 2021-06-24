#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int max = 0, second = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            second = max;
            max = arr[i];
        }
    }
    cout << "Second number " << second << endl;
    return 0;
}
