#include <iostream>
#include <string>

using namespace std;

string EncryptCaesar(string str, int shift)
{
  shift %= 26;
  for(int i = 0; i < str.length(); i++)
  {
    if(str[i] >= 'a' && str[i] <= 'z'){
      str[i] += shift;
      if(shift > 0 && (str[i] > 'z' || str[i] < 0)){
        str[i] += 'a' - 'z' - 1;
      } else if(shift < 0 && (str[i] < 'a' || str[i] < 0)){
        str[i] += 'z' - 'a' + 1;
      }
    } else if(str[i] >= 'A' && str[i] <= 'Z'){str[i] += shift;
      if(shift > 0 && (str[i] > 'Z' || str[i] < 0)){
        str[i] += 'A' - 'Z' - 1;
      } else if(shift < 0 && (str[i] < 'A' || str[i] < 0)){
        str[i] += 'Z' - 'A' + 1;
      }
    }
  }
  return str;
}

string DecryptCaesar(string str, int shift)
{
  return EncryptCaesar(str, -shift);
}

int main() {
  cout << "Task 1. Implementation of the Caesar cipher\n";
  string text;
  cout << "Input text\n";
  getline(cin, text);
  int shift;
  cout << "Input shift\n";
  cin >> shift;

  text = EncryptCaesar(text, shift);
  cout << "\n" << text << "\n\n";
  text = DecryptCaesar(text, shift);
  cout << text << "\n";
}
