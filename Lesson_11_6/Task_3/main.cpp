#include <iostream>
#include <string>

using namespace std;

string find_ip_x(string str, int start)
{
  string ip;
  for(int i = start; i < str.length() && str[i] != '.'; i++)
  {
    ip += str[i];
  }
  return ip;
}

bool Corrected(string ip)
{
  //bool correct = true;
  if(ip.length() > 3 || ip.length() == 0){
    return false;
  }
  for(int i = 0; i < ip.length(); i++)
  {
    if(ip[i] < '0' || ip[i] > '9' || (ip[0] == '0' && ip.length() > 1) || (i != 0 && ip[i - 1] == '0' && ip[i] == '0')){
      return false;
    }
  }
  int number = 0;
  for(int j = 0; j < ip.length(); j++)
  {
      number *= 10;
      number += ip[j] - '0';
  }
  if(number > 255){
    return false;
  }
  return true;
}

int main() {
  cout << "Task 3. IP address validation\n";
  string ip, ip_1, ip_2, ip_3, ip_4;
  cout << "Input IP address\n";
  cin >> ip;

  ip_1 = find_ip_x(ip, 0);
  ip_2 = find_ip_x(ip, ip_1.length() + 1);
  ip_3 = find_ip_x(ip, ip_1.length() + ip_2.length() + 2);
  ip_4 = find_ip_x(ip, ip_1.length() + ip_2.length() + ip_3.length() + 3);

  bool correct = (ip_1.length() + ip_2.length() + ip_3.length() + ip_3.length() + 3) == ip.length()
        && Corrected(ip_1) && Corrected(ip_2) && Corrected(ip_3) && Corrected(ip_4);

  cout << (correct ? "Yes\n" : "No\n");
}
