#include <iostream>
#include <string>

using namespace std;

bool CorrektNumber(string number)
{
  bool real = true;
  bool firstPoint = false;
  for(int i = 0; i < number.length() && real == true; i++)
  {
    if((number[i] < '0' || number[i] > '9')
        && number[i] != '.' && number[0] != '-'){
      real = false;
      break;
    }
    if(number[i] == '.'){
      if(firstPoint){
        real = false;
        break;
      } else{
        firstPoint = true;
      }
    }
  }
  if(real && ((number[0] == '-' && firstPoint
      && number.length() < 3) || (number[0] == '-'
      && number.length() < 2) || (firstPoint
      && number.length() < 2) || number.length() < 1)){
    real = false;
  }
  return real;
}

string FindNumber(string str, int start)
{
  string num;
  for(int i = start; i < str.length() && str[i] != '.'; i++){
      num += str[i];
  }
  return num;
}

char SymbolMantissa(string str, int index)
{
    return str.length() > index ? str[index] : '0';
}

string RealNumber(string str)
{
    string num;
    bool start_null = true;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '-')
        {
            num += str[i];
        } else if(!(start_null == true && str[i] == '0')){
            num += str[i];
            start_null = false;
        }
    }
    return num;
}

string RevertWord(string str)
{
    string mantis;
    for(int i = 0; i < str.length(); i++){
        mantis += str[str.length() - 1 - i];
    }
    return mantis;
}

string RealMantissa(string str)
{
    str = RevertWord(str);
    str = RealNumber(str);
    return RevertWord(str);
}

int main()
{
  string number_1, number_2;
  cout << "Task 4. Comparison of long real numbers.\n";
  cout << "Input two the real number: ";
  cin >> number_1 >> number_2;
  if(CorrektNumber(number_1) && CorrektNumber(number_2)){
    string intNumber_1, mantNumber_1;
    string intNumber_2, mantNumber_2;
    intNumber_1 = FindNumber(number_1, 0);
    mantNumber_1 = FindNumber(number_1, intNumber_1.length() + 1);
    intNumber_2 = FindNumber(number_2, 0);
    mantNumber_2 = FindNumber(number_2, intNumber_2.length() + 1);
    intNumber_1 = RealNumber(intNumber_1);
    intNumber_2 = RealNumber(intNumber_2);
    mantNumber_1 = RealMantissa(mantNumber_1);
    mantNumber_2 = RealMantissa(mantNumber_2);
    if(mantNumber_1.length() == 0 && mantNumber_2.length() == 0 && (intNumber_1.length() == 1 && intNumber_1[0] == '-'
            || intNumber_1.length() == 0) && (intNumber_2.length() == 1 && intNumber_2[0] == '-' || intNumber_2.length() == 0)){
        cout << "Equal\n";
    } else if(intNumber_1[0] != '-' && (intNumber_1.length() > intNumber_2.length() || intNumber_2[0] == '-')){
        cout << "More\n";
    } else if(intNumber_2[0] != '-' && (intNumber_1.length() < intNumber_2.length() || intNumber_1[0] == '-')){
        cout << "Less\n";
    } else if(intNumber_1[0] != '-' && intNumber_2[0] != '-'){
        if(intNumber_1.length() < intNumber_2.length()){
            cout << "More\n";
        } else if(intNumber_1.length() > intNumber_2.length()){
            cout << "Less\n";
        } else
        for(int i = 0; i < intNumber_1.length(); i++){
            if(intNumber_1[i] > intNumber_2[i]){
                cout << "Less\n";
                return 0;
            } else if(intNumber_1[i] < intNumber_2[i]){
                cout << "More\n";
                return 0;
            }
        }
        for(int i = 0; i < mantNumber_1.length() || i < mantNumber_2.length(); i++){
            if(SymbolMantissa(mantNumber_1, i) > SymbolMantissa(mantNumber_2, i)){
                cout << "Less\n";
                return 0;
            } else if(SymbolMantissa(mantNumber_1, i) < SymbolMantissa(mantNumber_2, i)){
                cout << "More\n";
                return 0;
            }
        }
        cout << "Equal\n";
    } else{
        for(int i = 0; i < intNumber_1.length(); i++){
            if(intNumber_1[i] > intNumber_2[i]){
                cout << "More\n";
                return 0;
            } else if(intNumber_1[i] < intNumber_2[i]){
                cout << "Less\n";
                return 0;
            }
        }
        for(int i = 0; i < mantNumber_1.length() || i < mantNumber_2.length(); i++){
            if(SymbolMantissa(mantNumber_1, i) > SymbolMantissa(mantNumber_2, i)){
                cout << "More\n";
                return 0;
            } else if(SymbolMantissa(mantNumber_1, i) < SymbolMantissa(mantNumber_2, i)){
                cout << "Less\n";
                return 0;
            }
        }
        cout << "Equal\n";
    }
  } else{
    cout << "Numbers are not correct\n";
  }
  return 0;
}
