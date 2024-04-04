#include <iostream>

using namespace std;

class Toy
{
public:
    Toy(string _name) : name(_name){};
    Toy() : Toy("SomeToy"){};
private:
    string name;
};

class smart_ptr_toy
{
private:
    Toy* obj;
public:
    smart_ptr_toy()
    {
        obj = new Toy("SomeName");
    }

    smart_ptr_toy(string name)
    {
        obj = new Toy(name);
    }

    smart_ptr_toy(const smart_ptr_toy& oth)
    {
        obj = new Toy(*oth.obj);
    }

    smart_ptr_toy& operator=(const smart_ptr_toy& oth)
    {
        if(this == &oth)
            return *this;
        if(obj != nullptr)
            delete obj;
        obj = new Toy(*oth.obj);
        return *this;
    }

    ~smart_ptr_toy(){delete obj;};
};

class Dog
{
public:
    Dog(string _name, string toyname, int _age) : name(_name), lovelyToy(toyname)
    {
        if(_age >= 0 && _age < 30){
            age = _age;
        }
    };

    Dog(string _name) : Dog(_name, "SomeToy", 0){};
    Dog(int _age) : Dog("Snow", "SomeToy", _age){};
    Dog() : Dog("Snow", "SomeToy", 0){};

private:
    string name;
    int age;
    smart_ptr_toy lovelyToy;
};


int main()
{
    Dog d("Druzhok", "Ball", 3);
    Dog q(d);
    return 0;
}
