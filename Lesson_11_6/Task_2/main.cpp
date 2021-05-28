#include <iostream>
#include <string>

using namespace std;

string FirstEmail(string email)
{
  string f_email;
  for(int i = 0; i < email.length() && email[i] != '@'; i++)
  {
      f_email += email[i];
  }
  return f_email;
}

string SecondEmail(string email, int start_pos)
{
  string s_email;
  for(int i = (++start_pos); i < email.length(); i++)
  {
      s_email += email[i];
  }
  return s_email;
}

bool EmailCorrect(string str)
{
    string f_email = FirstEmail(str);
    string s_email = SecondEmail(str, f_email.length());

    if(f_email.length() < 1 || f_email.length() > 64 || s_email.length() < 1 || s_email.length() > 63){
        return false;
    }

    bool point = false;
    for(int i = 0; i < f_email.length(); i++)
    {
        if(!((f_email[i] >= 'a' && f_email[i] <= 'z') || (f_email[i] >= 'A' && f_email[i] <= 'Z')
            || f_email[i] == '`' || f_email[i] == '.' || f_email[i] == '!' || f_email[i] == '#'
            || f_email[i] == '$' || f_email[i] == '%' || f_email[i] == '&' || f_email[i] == '\''
            || f_email[i] == '*' || f_email[i] == '+' || f_email[i] == '-' || f_email[i] == '/'
            || f_email[i] == '=' || f_email[i] == '?' || f_email[i] == '^' || f_email[i] == '_'
            || f_email[i] == '{' || f_email[i] == '}' || f_email[i] == '|' || f_email[i] == '~'
            || (f_email[i] >= '0' && f_email[i] <= '9'))){
            return false;
        }
        if(f_email[i] == '.'){
            if(i == 0 || i == (f_email.length() - 1) || point){
                return false;
            }
            point = true;
        } else{
            point = false;
        }
    }

    for(int i = 0; i < s_email.length(); i++)
    {
        if(!((s_email[i] >= 'a' && s_email[i] <= 'z') || (s_email[i] >= 'A' && s_email[i] <= 'Z')
            || s_email[i] == '-' || s_email[i] == '.' || (s_email[i] >= '0' && s_email[i] <= '9'))){
            return false;
        }
        if(s_email[i] == '.'){
            if(i == 0 || i == (s_email.length() - 1) || point){
                return false;
            }
            point = true;
        } else{
            point = false;
        }
    }
    return true;
}

int main() {
  cout << "Task 2. Checking the correctness of the email address\n";
  string email;
  cout << "Input email\n";
  cin >> email;

  bool correct = EmailCorrect(email);

  cout << (correct == true ? "Yes" : "No") << "\n";
}
