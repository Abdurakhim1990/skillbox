#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Input counter number " << endl;
    int N;
    cin >> N;
    vector<int> vect(N);
    int average = 0;
    for(int i = 0; i < N; i++){
        cin >> vect[i];
        average += vect[i];
    }
    average /= N;
    cout << "Averange = " << average << endl;
    return 0;
}
