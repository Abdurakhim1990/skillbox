#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

using namespace std;

auto unifidedNumber = [](vector<int> vec)
{
    unordered_set<int> uni_num;
    for(auto val : vec){
        int count = 0;
        for(auto v1 : vec)
            if(val == v1)
                ++count;
        if(count == 1)
            uni_num.insert(val);
    }
    cout << endl;
    unique_ptr<vector<int>> un_vec(make_unique<vector<int>>(uni_num.begin(), uni_num.end()));
    return un_vec;
};

int main()
{
    vector<int> vect{1, 2, 3, 4, 5, 3, 1, 8};
    unique_ptr<vector<int>> unif_numb = unifidedNumber(vect);

    for(auto val : vect)
        cout << val << " ";
    cout << endl;

    for(auto val : *unif_numb)
        cout << val << " ";
    cout << endl;

    return 0;
}
