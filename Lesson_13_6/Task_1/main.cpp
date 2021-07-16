#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Tast 1" << endl;
    cout << "Input vector size: ";
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cout << "Input " << i + 1 << " element for vector: ";
        cin >> vec[i];
    }
    int m;
    cout << "Input comparison number: ";
    cin >> m;
    int finish_size = 0;
    for(int i = 0; i < n; i++){
        if(vec[i] != m){
            vec[finish_size] = vec[i];
            finish_size++;
        }
    }
    vec.resize(finish_size);
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    return 0;
}
