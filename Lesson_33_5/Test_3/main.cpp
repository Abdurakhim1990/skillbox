#include <iostream>
#include <boost/asio.hpp>

using namespace std;

int main()
{
    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
    t.wait();
    cout << "Hello, Skillbox!" << endl;
    return 0;
}
