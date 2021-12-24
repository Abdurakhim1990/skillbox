#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int>  anagram(string str);

int main()
{
    cout << "Task 3. Anagrams." << endl;
    string str_1, str_2;
    cout << "Input first and second words: ";
    cin >> str_1 >> str_2;
    cout << (anagram(str_1) == anagram(str_2) ? "Anagram" : "Not anogram") << endl;
    return 0;
}

map<char, int>  anagram(string str)
{
    map<char, int> anagram;
    for(auto c : str)
        anagram[c] += 1;
    return anagram;
}
