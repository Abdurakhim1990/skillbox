#include <iostream>

using namespace std;

class Animal
{
public:
    void setAge(int _age)
    {
        if(_age >=0 && _age < 30)
            age = _age;
        else
            cout << "Incorrect age" << endl;
    }

    int getAge()
    {
        return age;
    }

protected:
    string name;
    int age;
};

class Dog : virtual public Animal
{
public:
    Dog(){}
    Dog(int _age, string _name)
    {
        name = _name;
        if(_age >=0 && _age < 30)
            age = _age;
        else
            cout << "Incorrect age" << endl;
    }

    void barkAge()
    {
        for(int i = 0; i < age; ++i){
            cout << "Bark! ";
        }
        cout << endl;
    }
private:

};

class Cat : virtual public Animal
{
public:
    Cat(){}
    Cat(int _age, string _name)
    {
        name = _name;
        if(_age >=0 && _age < 30)
            age = _age;
        else
            cout << "Incorrect age" << endl;
    }

    void meowAge()
    {
        for(int i = 0; i < age; ++i){
            cout << "Meow! ";
        }
        cout << endl;
    }
};

class CatDog : public Dog, public Cat
{
public:
    CatDog(int _age, string _name)
    {
        name = _name;
        if(_age >=0 && _age < 30)
            age = _age;
        else
            cout << "Incorrect age" << endl;
    }
};

int main()
{
    CatDog d(10, "Sharik");
    d.barkAge();
    d.setAge(5);
    d.meowAge();
    return 0;
}
