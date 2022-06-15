#include <iostream>

using namespace std;

class PlaneControl
{
    double leftAileron = 0;
    double rightAileron = 0;

public:
    void turnLeft()
    {
        leftAileron -= 30;
        rightAileron += 30;
    }

    void turnRight()
    {
        leftAileron += 30;
        rightAileron -= 30;
    }

private:
    double elevator = 0;

public:
    void setElevator(double value)
    {
        if(value < -30) value = -30;
        if(value > 30) value = 30;
        if(value == elevator) return;
        elevator = value;
    }

    double getLeftAileron()
    {
        return leftAileron;
    }

    double getRightAileron()
    {
        return rightAileron;
    }

    double getElevator()
    {
        return elevator;
    }

    static void showInfo(PlaneControl* planeControl)
    {
        cout << "Left aileron: " << planeControl->leftAileron << " right aileron: " <<
                planeControl->rightAileron << " elevator: " << planeControl->elevator << endl;
    }
};

//void showInfo(PlaneControl* planeControl)
//{
//    cout << "Left aileron: " << planeControl->getLeftAileron() << " right aileron: " <<
//            planeControl->getRightAileron() << " elevator: " << planeControl->getElevator() << endl;
//}

//void showInfo(PlaneControl* planeControl)
//{
//    cout << "Left aileron: " << planeControl->leftAileron << " right aileron: " <<
//            planeControl->rightAileron << " elevator: " << planeControl->elevator << endl;
//}

int main()
{
    PlaneControl* planeControl = new PlaneControl();
    planeControl->turnLeft();
    planeControl->setElevator(13.5);
    PlaneControl::showInfo(planeControl);
    delete planeControl;
    planeControl = nullptr;
    return 0;
}


/*
struct robot_t
{
    int health;
    int damage;
    int speed;

    void attack()
    {
        cout << "Attack: " << damage << endl;
    }

    void take_damage()
    {
        cout << "Damaged: " << health << endl;
    }

    void move()
    {
        cout << "Moving: " << speed << endl;
    }
};



int main()
{
    robot_t* robot = new robot_t{50, 100, 10};
    robot->attack();
    delete robot;
    return 0;
}*/
