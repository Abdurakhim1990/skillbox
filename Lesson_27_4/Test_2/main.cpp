#include <iostream>

using namespace std;

class Monster
{
public:
    string name = "uncnown";
    double attackDamage = 10;
    double health = 100;

    void attack()
    {
        cout << name << " is attacking: " << attackDamage << endl;
    }
};

class FlyingMonster: public Monster
{
public:
    double flightSpeed = 50;

    void fly()
    {
        cout << name << " is flying: " << flightSpeed << endl;
    }


};

class ShootingMonster: public Monster
{
public:
    double attackRange = 30;

    void shoot()
    {
        attack();
        cout << name << " shooting: " << attackRange << endl;
    }
};


int main()
{
    FlyingMonster* flyingMonster = new FlyingMonster();
    flyingMonster->fly();
    flyingMonster->attack();
    delete flyingMonster;
    ShootingMonster* shootingMonster = new ShootingMonster();
    shootingMonster->shoot();
    delete shootingMonster;
    return 0;
}
