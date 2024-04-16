#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Message
{
    T data;

    Message(char* inData): data(inData)
    {}

    void print() const
    {
        cout << data << endl;
    }
};

int main()
{
    Message<string> m("Hello, Skillbox");
    m.print();
    return 0;
}

//template<typename T1, typename  T2>

//T1 maxx(T1 a, T2 b)
//{
//    return a > b ? a : b;
//}

//template<typename T>

//T maxx(const vector<T> &v)
//{
//    if(v.size() == 0){
//        throw invalid_argument("'v' can't be empty!");
//    }
//    T m = v[0];
//    for(int i = 0; i < v.size(); ++i){
//        if(v[i] > m){
//            m = v[i];
//        }
//    }
//    return m;
//}

//int main()
//{
//    vector<double> test = {10.5, 19.1, 7.0};
//    cout << "Result: " << maxx(test) << endl;
//    return 0;
//}
