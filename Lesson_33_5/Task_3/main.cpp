#include <iostream>
#include <vector>

using namespace std;

template<typename K, typename V>
struct RegistryPair
{
    K key;
    V val;

    RegistryPair(K k, V v) : key(k), val(v){}
};

template<typename K, typename V>
class Registry
{
private:
    vector<RegistryPair<K, V>> elem;

public:
    void add(K key, V val)
    {
//        for(int i = 0; i < elem.size(); ++i){
//            if(elem[i][0] == key){
//                elem[i].push_back(val);
//                return;
//            }
//        }
        RegistryPair<K, V> vec = {key, val};
        elem.push_back(vec);
    }

    void remove(K key)
    {
        int i = 0, j = 0;
        for(; i < elem.size(); ++i, ++j){
            if(elem[i].key == key){
                --j;
            } else {
                if(i != j){
                    elem[j] = elem[i];
                }
            }
        }
        while(i != j){
            elem.pop_back();
            ++j;
        }
    }

    void print()
    {
        for(int i = 0; i < elem.size(); ++i){
            cout << "Key = " << elem[i].key << " Value = " << elem[i].val << endl;
        }
    }

    vector<V> find(K key)
    {
        vector<V> vec;
        for(int i = 0; i < elem.size(); ++i){
            if(elem[i].key == key){
                vec.push_back(elem[i].val);
            }
        }
        return vec;
    }
};

int main()
{
    Registry<int, double>registry;
    int key = 1;
    double val = 10.2;
    registry.add(key, val);
    registry.print();
    cout << endl;

    key = 2;
    val = 20.8;
    registry.add(key, val);
    registry.print();
    cout << endl;

    key = 3;
    val = 30.5;
    registry.add(key, val);
    registry.print();
    cout << endl;

    key = 1;
    val = 40.4;
    registry.add(key, val);
    registry.print();
    cout << endl;

    key = 2;
    val = 50.3;
    registry.add(key, val);
    registry.print();
    cout << endl;

    key = 1;
    vector<double> vec_1 = registry.find(key);
    cout << "For key " << key << " - ";
    for(auto i = 0; i < vec_1.size(); ++i){
        cout << vec_1[i] << " ";
    }
    cout << endl;
    cout << endl;

    key = 1;
    registry.remove(key);
    registry.print();
    cout << endl;

    key = 3;
    registry.remove(key);
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
