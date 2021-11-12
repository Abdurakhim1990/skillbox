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
    for(int i = 0; i < strlen(str_a) - strlen(str_b) && overlap == false; ++i){
        if(*(str_a + i) == *(str_b + j)){
            j++;
            overlap = j == strlen(str_b);
        }
    }
    return overlap;
}
