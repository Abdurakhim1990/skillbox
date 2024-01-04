#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <cstdlib>

using namespace std;

mutex order_access, cooking_access, courier_access, cout_access;

const string foods[] = {"PIZZA", "SOUP", "STEAK", "SALAD", "SUSHI"};

void ordering_food(string order_num)
{
    order_access.lock();
    srand(time(NULL));
    int my_time = rand()%6 + 5;
    cout_access.lock();
    cout << order_num << ". Order in progress!!! " << my_time << " sec\n";
    cout_access.unlock();
    this_thread::sleep_for(chrono::seconds(my_time));
    order_access.unlock();
    cout_access.lock();
    cout << order_num << ". Order is accepted!!!\n";
    cout_access.unlock();
    srand(time(NULL));
    string name_food = foods[rand()%5];

    cooking_access.lock();
    srand(time(NULL));
    my_time = rand()%11 + 5;
    cout_access.lock();
    cout << order_num << ". Cooking the dish " << name_food << "!!! " << my_time << " sec\n";
    cout_access.unlock();
    this_thread::sleep_for(chrono::seconds(my_time));
    cooking_access.unlock();
    cout_access.lock();
    cout << order_num << ". " << name_food << " is ready!!!\n";
    cout_access.unlock();

    courier_access.lock();
    my_time = 30;
    cout_access.lock();
    cout << order_num << ". Courier delivery " << name_food << "!!! " << my_time << " sec\n";
    cout_access.unlock();
    this_thread::sleep_for(chrono::seconds(my_time));
    courier_access.unlock();
    cout_access.lock();
    cout << order_num << ". " << name_food << " order completed !!!\n\n";
    cout_access.unlock();
}

int main()
{
    thread order1(ordering_food, "Order #1");
    thread order2(ordering_food, "Order #2");
    thread order3(ordering_food, "Order #3");
    thread order4(ordering_food, "Order #4");
    thread order5(ordering_food, "Order #5");
    thread order6(ordering_food, "Order #6");
    thread order7(ordering_food, "Order #7");
    thread order8(ordering_food, "Order #8");
    thread order9(ordering_food, "Order #9");
    thread order10(ordering_food, "Order #10");

    order1.detach();
    order2.detach();
    order3.detach();
    order4.detach();
    order5.detach();
    order6.detach();
    order7.detach();
    order8.detach();
    order9.detach();
    //order10.detach();

    if(order1.joinable()) order1.join();
    if(order2.joinable()) order2.join();
    if(order3.joinable()) order3.join();
    if(order4.joinable()) order4.join();
    if(order5.joinable()) order5.join();
    if(order6.joinable()) order6.join();
    if(order7.joinable()) order7.join();
    if(order8.joinable()) order8.join();
    if(order9.joinable()) order9.join();
    if(order10.joinable()) order10.join();
    return 0;
}
