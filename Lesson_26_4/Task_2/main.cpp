#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class PhoneBook
{
    string number = "";
    string username = "";

public:

    void setNumber(string num)
    {
        number = num;
    }

    void setUsername(string name)
    {
        username = name;
    }

    string getNumber()
    {
        return number;
    }

    string getUsername()
    {
        return username;
    }
};

class PhoneControl
{
    bool checkPhoneNumber(string numb)
    {
        if(numb.size() != 12) return false;
        if(numb[0] != '+' || numb[1] != '7') return false;
        for(int i = 2; i < numb.size(); ++i)
        {
            if(numb[i] < '0' || numb[2] > '9') return false;
        }
        return true;
    }

public:
    PhoneBook addToBook()
    {
        PhoneBook phoneBook;
        string str;
        cout << "Input name for new contact: -- ";
        cin >> str;
        phoneBook.setUsername(str);
        cout << "Input phone number for new contact (+7<10 digits>): -- ";
        cin >> str;
        while (!checkPhoneNumber(str))
        {
            cout << "Please enter a valid phone number (+7<10 digits>): -- ";
            cin >> str;
        }
        phoneBook.setNumber(str);
        return phoneBook;
    }

    void callImitation(string number, string name)
    {
        cout << "\n\tCALL!!!\n " << number << name << endl << endl;
    }

    void smsImitation(string number, string name)
    {
        string message;
        cout << "Enter messages to send" << endl;
        cin.ignore(numeric_limits<int>::max(), '\n');
        getline(cin, message);

        cout << "\n\tSMS!!!\n " << number << name << endl;
        cout << "<< " << message << " >>" << endl << endl;
    }

    bool searchNumberInList(vector <PhoneBook>& vecPhonebook, string& name, int& num)
    {
        bool num_ok = false;
        for(int i = 0; num_ok == false && i < vecPhonebook.size(); ++i)
        {
            num = i;
            num_ok = vecPhonebook[i].getUsername() == name;
        }
        return num_ok;
    }

    void callToContact(vector <PhoneBook> vecPhonebook)
    {
        cout << "Enter a contact name or phone number: ";
        string contact;
        cin >> contact;
        int index_contact = 0;
        if(checkPhoneNumber(contact) == true){
            callImitation(contact, "");
        } else if(searchNumberInList(vecPhonebook, contact, index_contact)){
            callImitation(vecPhonebook[index_contact].getNumber(),
                          " (" + vecPhonebook[index_contact].getUsername() + ")");
        } else{
            cout << "No such contact\n" << endl;
        }
    }

    void smsToContact(vector <PhoneBook> vecPhonebook)
    {
        cout << "Enter a contact name or phone number: ";
        string contact;
        cin >> contact;
        int index_contact = 0;
        if(checkPhoneNumber(contact) == true){
            smsImitation(contact, "");
        } else if(searchNumberInList(vecPhonebook, contact, index_contact)){
            smsImitation(vecPhonebook[index_contact].getNumber(),
                          " (" + vecPhonebook[index_contact].getUsername() + ")");
        } else{
            cout << "No such contact\n" << endl;
        }
    }

public:
    static void controlMenu()
    {
        vector <PhoneBook> vecPhonebook;
        string com = "";
        cout << "Input command: ";
        cin >> com;
        PhoneControl phoneControl;

        while(com != "exit")
        {
            if(com == "add"){
                vecPhonebook.push_back(phoneControl.addToBook());
            } else if(com == "call"){
                phoneControl.callToContact(vecPhonebook);
            } else if(com == "sms"){
                phoneControl.smsToContact(vecPhonebook);
            }
            cout << "Input command: ";
            cin >> com;
        }
    }
};

int main()
{
    PhoneControl::controlMenu();

    return 0;
}
