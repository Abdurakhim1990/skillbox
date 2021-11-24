#include <iostream>
#include <vector>

using namespace std;

void Swapvec(vector<int>& vec_1, int* vec_2);

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    int b[] = {2, 4, 6, 8, 10, 12};
    Swapvec(a, b);

    for(int i = 0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < a.size(); ++i){
        cout << b[i] << " ";
    }
    return 0;
}

void Swapvec(vector<int>& vec, int* mas)
{
    int temp;
    for(int i = 0; i < vec.size(); ++i){
        temp = vec[i];
        vec[i] = mas[i];
        mas[i] = temp;
    }
}

