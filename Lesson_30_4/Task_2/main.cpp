#include <iostream>
#include <cpr/cpr.h>

using namespace std;

string getHead(string &str)
{
    int begin = 0;
    int len = 0;

    begin = str.find("<h1>") + 4;
    len = str.find("</h1>") - begin;

    return str.substr(begin, len);
}

int main()
{
    string resp = cpr::Get(cpr::Url("http://httpbin.org/html")).text;
    cout << getHead(resp) << endl;
    return 0;
}
