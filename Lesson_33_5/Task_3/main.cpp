#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Registry
{
private:
    vector<vector<T>> reg;

public:
    void add(T key, T val)
    {
        for(int i = 0; i < reg.size(); ++i){
            if(reg[i][0] == key){
                reg[i].push_back(val);
                return;
            }
        }
        vector<T> vec = {key, val};
        reg.push_back(vec);
    }

    void remove(T key)
    {
        int i = 0, j = 0;
        for(; i < reg.size(); ++i, ++j){
            if(i != j){
                reg[j] = reg[i];
            } else if(reg[i][0] == key){
                --j;
            }
        }
        if(i != j)
            reg.pop_back();
    }

    void print()
    {
        for(int i = 0; i < reg.size(); ++i){
            for(int j = 0; j < reg[i].size(); ++j){
                cout << reg[i][j] << " ";
            }
            cout << endl;
        }
    }

    vector<T> find(T key)
    {
        for(int i = 0; i < reg.size(); ++i){
            if(reg[i][0] == key){
                return reg[i];
            }
        }
        vector<T> vec;
        return vec;
    }
};

int main()
{
    Registry<int>registry;
    int key = 1;
    int val = 10;
    registry.add(key, val);
    registry.print();
    cout << endl;

    key = 2;
    val = 20;
    registry.add(key, val);
    registry.print();
    cout << endl;

    key = 3;
    val = 30;
    registry.add(key, val);
    registry.print();
    cout << endl;

    key = 1;
    val = 40;
    registry.add(key, val);
    registry.print();
    cout << endl;

    key = 2;
    val = 50;
    registry.add(key, val);
    registry.print();
    cout << endl;

    vector<int> vec_1 = registry.find(1);
    for(auto i = 0; i < vec_1.size(); ++i){
        cout << vec_1[i] << " ";
    }
    cout << endl;
    cout << endl;

    registry.remove(1);
    registry.print();
    cout << endl;
    return 0;
}

/*
int main()
{
    Registry<string>registry;
    string key = "Key";
    string val = "Val";
    registry.add(key, val);
    registry.print();
    cout << endl;

    key = "Key_1";
    val = "Val_1";
    registry.add(key, val);
    registry.print();
    cout << endl;

    key = "Key_2";
    val = "Val_2";
    registry.add(key, val);
    registry.print();
    cout << endl;

    key = "Key";
    val = "Val_2";
    registry.add(key, val);
    registry.print();
    cout << endl;

    key = "Key_1";
    val = "Val_6";
    registry.add(key, val);
    registry.print();
    cout << endl;

    vector<string> vec_1 = registry.find("Key_6");
    for(auto i = 0; i < vec_1.size(); ++i){
        cout << vec_1[i] << " ";
    }
    cout << endl;
    cout << endl;

    registry.remove("Key");
    registry.print();
    cout << endl;
    return 0;
}
*/
