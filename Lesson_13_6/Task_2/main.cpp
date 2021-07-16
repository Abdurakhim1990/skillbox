#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Task 2" << endl;
    vector<float> price_vector{12.5, 8.4, 10.6, 3.1, 2.5, 3.9, 6};
    vector<int> shopping_vector{6, 1, 3, 6};
    float sum_cost = 0;
    for(int i = 0; i < shopping_vector.size(); i++){
        sum_cost += price_vector[shopping_vector[i]];
    }
    cout << "Total cost is " << sum_cost;
    return 0;
}
