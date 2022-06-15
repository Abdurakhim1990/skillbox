#include "window.h"

using namespace std;

bool Window::setCoord(vector <int> v_c)
{
    if((v_coord[0] + v_c[0]) >= 0 && (v_coord[1] + v_c[1]) >= 0 &&
            (v_coord[0] + v_c[0]) < 80 && (v_coord[1] + v_c[1]) < 50){
        v_coord[0] += v_c[0];
        v_coord[1] += v_c[1];
        return true;
    }
    return false;
}

bool Window::setSize(vector <int> l_w)
{
    if(l_w[0] > 0 && l_w[1] > 0){
        v_length_width = l_w;
        return true;
    }
    return false;
}

vector <int> Window::getCoordWindow()
{
    return v_coord;
}

vector <int> Window::getSizeWindow()
{
    return v_length_width;
}

void Window::Move()
{
    cout << "Enter new window offset coordinates (X and Y)" << endl;
    vector <int> v_c = {0, 0};
    cin >> v_c[0] >> v_c[1];
    while(setCoord(v_c) != true){
        cout << "Enter valid window offset coordinates (X and Y)" << endl;
        cin >> v_c[0] >> v_c[1];
    }
    cout << "New window coordinates (" << getCoordWindow()[0] << "; " << getCoordWindow()[1] << ")" << endl;
}

void Window::Resize()
{
    cout << "Enter new window size (length and width)" << endl;
    vector <int> v_l_w = {0, 0};
    cin >> v_l_w[0] >> v_l_w[1];
    while(setSize(v_l_w) != true){
        cout << "Enter new window size (length and width)" << endl;
        cin >> v_l_w[0] >> v_l_w[1];
    }
    cout << "New window size (" << getSizeWindow()[0] << "; " << getSizeWindow()[1] << ")" << endl;
}

void Window::controlMonitor()
{
    string com = "";
    cout << "Enter command: ";
    cin >> com;
    Window *window = new Window;

    while(com != "close")
    {
        if(com == "move"){
            window->Move();
        } else if(com == "resize"){
            window->Resize();
        } else if(com == "display"){
            Monitor::display(window->v_coord, window->v_length_width);
        }
        cout << "Enter command: ";
        cin >> com;
    }
    delete window;
}
