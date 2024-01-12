#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <cstdlib>
#include <vector>

using namespace std;

mutex order_access, cooking_access, cout_access;

vector<string> orders;
vector<string> delivery;

const string foods[] = {"PIZZA", "SOUP", "STEAK", "SALAD", "SUSHI"};

void ordering_food()
{
    srand(time(NULL));
    int my_time = rand()%6 + 5;
    this_thread::sleep_for(chrono::seconds(my_time));
    srand(time(NULL));
    int order = rand()%5;
    static int num = 1;
    string s_num = " . ";
    s_num[0] = (char)(num + '0');
    order_access.lock();
    orders.push_back(s_num + foods[order]);
    order_access.unlock();
    cout_access.lock();
    cout << orders.back() << " ordered" << endl;
    cout_access.unlock();
    ++num;
}

void cooking()
{
    if(!orders.empty()){
        srand(time(NULL));
        int my_time = rand()%11 + 5;
        order_access.lock();
        string order = orders[0];
        int ORDER_SIZE = orders.size();
        for(size_t t = 0; ORDER_SIZE > 1 && t < ORDER_SIZE - 1; ++t){
            orders[t] = orders[t + 1];
        }
        orders.pop_back();
        order_access.unlock();
        this_thread::sleep_for(chrono::seconds(my_time));
        cooking_access.lock();
        delivery.push_back(order);
        cooking_access.unlock();
        cout_access.lock();
        cout << order << " is ready!" << endl;
        cout_access.unlock();
    }
}

void courier(int& counter)
{
    if(!delivery.empty()){
        cooking_access.lock();
        string order = delivery[0];
        int DELIV_SIZE = delivery.size();
        for(size_t t = 0; DELIV_SIZE > 1 && t < DELIV_SIZE - 1; ++t){
            delivery[t] = delivery[t + 1];
        }
        delivery.pop_back();
        cooking_access.unlock();
        this_thread::sleep_for(chrono::seconds(30));
        cout_access.lock();
        cout << order << " delivered!" << endl;
        cout_access.unlock();
        ++counter;
    }
}

int main()
{
    int counter = 0;
    while (counter < 10) {
        thread order(ordering_food);
        thread kitch(cooking);
        kitch.detach();
        thread cour(courier, std::ref(counter));

        order.join();
        if(kitch.joinable()) kitch.join();
        cour.join();
    }
    cout << "The END" << endl;
    return 0;
}
