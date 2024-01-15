#include <iostream>
#include <string>
#include <cpr/cpr.h>

using namespace std;

void displResponce(cpr::Response resp)
{
    cout << resp.text << endl;
}

void comGet(void)
{
    cpr::Response resp = cpr::Get(cpr::Url("https://www.httpbin.org/get"));
    displResponce(resp);
}

void comPost(void)
{
    cpr::Response resp = cpr::Post(cpr::Url("https://www.httpbin.org/post"));
    displResponce(resp);
}

void comPut(void)
{
    cpr::Response resp = cpr::Put(cpr::Url("https://www.httpbin.org/put"));
    displResponce(resp);
}

void comDelete(void)
{
    cpr::Response resp = cpr::Delete(cpr::Url("https://www.httpbin.org/delete"));
    displResponce(resp);
}

void comPatch(void)
{
    cpr::Response resp = cpr::Patch(cpr::Url("https://www.httpbin.org/patch"));
    displResponce(resp);
}

int main()
{
    string command;

    do {
        cout << "Input command: \"get\", \"post\", \"put\", \"delete\", \"patch\" or \"exit\"" << endl;
        cin >> command;
        if(command == "get"){
            comGet();
        } else if(command == "post"){
            comPost();
        } else if(command == "put"){
            comPut();
        } else if(command == "delete"){
            comDelete();
        } else if(command == "patch"){
            comPatch();
        }
    } while (command != "exit");
    return 0;
}
