#include <iostream>
#include <cstring>

using namespace std;

bool substr(char * str_a, char * str_b);

int main()
{
    char a[] = "Hello world";
    char b[] = "wor";
    char c[] = "banana";
    std::cout << substr(a,b) << " " << substr(a,c);
    return 0;
}

bool substr(char * str_a, char * str_b)
{
    int j = 0;
    bool overlap = false;
    for(int i = 0; i < strlen(str_a) && overlap == false; ++i){
        overlap = (*(str_a + i) == *(str_b + j)? ++j : j = 0) == strlen(str_b);
    }
    return overlap;
}
