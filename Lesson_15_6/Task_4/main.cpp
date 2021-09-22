#include <iostream>
#include <vector>

using namespace std;

// Вариант №1
int main()
{
    cout << "Task 4" << endl;
    vector<int> vec = {-100,-50, -5, 1, 10, 15};
    //vector<int> vec = {-100,-50, -40, -25, -15, -5};
    //vector<int> vec = {2, 10, 35, 51, 110, 150};
    int start = 0, end = 1;
    for(int i = 0; vec[i] < 0 && i < vec.size() - 1; i++){
        start = i;
        end = i + 1;
    }
    for(int i = 0; i < vec.size(); i++){
        if(abs(vec[start]) < abs(vec[end])) {
            cout << vec[start] << " ";
            start--;
        } else{
            cout << vec[end] << " ";
            end++;
        }
    }
    return 0;
}

/*
// Вариант №2 Если необходимо сохранить отсортированный массив
int main()
{
    cout << "Task 4" << endl;
    vector<int> vec = {-100,-50, -5, 1, 10, 15};
    //vector<int> vec = {-100,-50, -40, -25, -15, -5};
    //vector<int> vec = {2, 10, 35, 51, 110, 150};
    vector<int> mass(vec.size());
    int start = 0, end = 1;
    for(int i = 0; vec[i] < 0 && i < vec.size() - 1; i++){
        start = i;
        end = i + 1;
    }
    for(int i = 0; i < vec.size(); i++){
        if(abs(vec[start]) < abs(vec[end])) {
            mass[i] = vec[start];
            start--;
        } else{
            mass[i] = vec[end];
            end++;
        }
        cout << mass[i] << " ";
    }
    return 0;
}
*/

/*
// Вариант №3 Для вывода в порядке убывания можно было реализовать в одном цикле for и без вспомогательного массива
int main()
{
    cout << "Task 4" << endl;
    vector<int> vec = {-100,-50, -5, 1, 10, 15};
    //vector<int> vec = {-100,-50, -40, -25, -15, -5};
    //vector<int> vec = {2, 10, 35, 51, 110, 150};vector<int> mass(vec.size());
    vector<int> mass(vec.size());
    int start = 0, end = vec.size() - 1;
    for(int i = vec.size() - 1; i >= 0; i--){
        if(abs(vec[start]) > abs(vec[end])) {
            mass[i] = vec[start];
            start++;
        } else{
            mass[i] = vec[end];
            end--;
        }
    }
    for(int i = 0; i < vec.size(); i++){
        cout << mass[i] << " ";
    }
    return 0;
}
*/
