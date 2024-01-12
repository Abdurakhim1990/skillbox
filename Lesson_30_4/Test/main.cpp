#include <iostream>
#include <cpr/cpr.h>

//using namespace std;


int main()
{
//    cpr::Response r = cpr::Get(cpr::Url("https://www.httpbin.org/headers"),
//                               cpr::Header({{"user-agent", "Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36"
//                                             " (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 OPR/95.0.0.0"},
//                                           {"Accept", "text/html"}}));

    std::string name, city;
    std::cin >> name >> city;
    cpr::Response r = cpr::Post(cpr::Url("https://www.httpbin.org/post"),
                                cpr::Payload({{"name", name/*.c_str()*/}, {"city", city/*.c_str()*/}}));
    std::cout << r.text << std::endl;
    return 0;
}
