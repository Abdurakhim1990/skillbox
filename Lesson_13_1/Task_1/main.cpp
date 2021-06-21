#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Input counter number " << endl;
    int N;
    cin >> N;
    vector<int> vect[N];
    for(int i = 0; i < N; i++){
        cin >> vect[i];
    }

    return 0;
}
