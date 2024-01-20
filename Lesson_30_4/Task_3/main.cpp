#include <iostream>
#include <vector>
//#include <initializer_list>
#include <cpr/cpr.h>

using namespace std;


void PostRequest(map<string, string> &args)
{
    vector<cpr::Pair> post_req;
    for(auto it = args.begin(); it != args.end(); ++it){
        post_req.push_back(cpr::Pair(it->first, it->second));
    }
    auto response = cpr::Post(cpr::Url("https://www.httpbin.org/post"),
                              cpr::Payload(post_req.begin(), post_req.end())).text;
    cout << response << endl;
}

void GetRequest(map<string, string> &args)
{
    string get_req = "https://www.httpbin.org/get?";
    for(auto it = args.begin(); it != args.end(); ++it)
        get_req += (it->first + "=" + it->second + "&");
    get_req[get_req.length() - 1] = '\0';
    auto response = cpr::Get(cpr::Url(get_req)).text;
    cout << response << endl;
}

int main()
{
    string arg, val;
    map<string, string> args;
    cout << "Input ARGUMENT and VALUE" << endl;
    getline(cin, arg);
    do {
        getline(cin, val);
        args.insert(pair<string, string>(arg, val));
        cout << "Input ARGUMENT and VALUE" << endl;
        getline(cin, arg);
    } while (arg != "post" && arg != "get");

    if(arg == "post"){
        PostRequest(args);
    } else {
        GetRequest(args);
    }
    return 0;
}

