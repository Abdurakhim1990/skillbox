#include <iostream>
#include <map>

using namespace std;

bool anagram(string str_a, string str_b);
string Streamline(string str);

int main()
{
    cout << "Task 3. Anagrams." << endl;
    string str_1, str_2;
    cout << "Input first and second words: ";
    cin >> str_1 >> str_2;
    if(anagram(str_1, str_2))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}

bool anagram(string str_a, string str_b)
{
    return Streamline(str_a) == Streamline(str_b);
}

string Streamline(string str)
{
    map<char, int> anagram;
    for(int i = 0; i < str.length(); ++i){
        map<char, int>::iterator it = anagram.find(str[i]);
        int count = 1;
        if(it != anagram.end()){
            count = it->second;
            anagram.erase(it);
            ++count;
        }
        anagram.insert(pair<char, int> (str[i], count));
    }
    str = "";
    for(map<char, int>::iterator it = anagram.begin(); it != anagram.end(); ++it){
        int count = it->second;
        while(count > 0){
            str += it->first;
            --count;
        }
    }
    return str;
}
