#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void voice() = 0;
};

class Dog : virtual public Animal
{
public:
    virtual void voice()
    {
        cout << "Bark!" << endl;
    }
};

class Cat : virtual public Animal
{
public:
    virtual void voice()
    {
        cout << "Meow!" << endl;
    }
};

class CatDot : virtual public Cat, virtual public Dog
{
public:
    virtual void voice()
    {
        cout << "BarkMeow!" << endl;
    }

};

int main()
{
    Animal* arr[4];
    arr[0] = new Cat();
    arr[1] = new Dog();
    arr[2] = new CatDot();
    arr[3] = new Dog();
    for(int i = 0; i < 4; ++i){
        arr[i]->voice();
    }

    return 0;
}
