#include <iostream>
#include <string>
#include <sstream>

using namespace std;

enum avtomats{
    EATING_AT_HOME,
    HOUSE_SOCKETS,
    LIGHT_IN_HOUSE,
    LIGHT_IN_GARDEN,
    INDOOR_HEATING,
    WATER_HEATING,
    INDOOR_CONDITIONER
};

int main()
{
    cout << "Task 5. Smart House" << endl;
    int temp_out;
    int temp_home;
    string sens_mov;
    string light_home;
    int time_clock = 0;
    string input_data;
    int state_of_machine = 0;
    for(time_clock = 0; time_clock < 5/*24*/; time_clock++){
        cout << "Input to format: TemperOut -> TemperHome -> SenseMovem (yes/no) -> LightInTheHome (on/off)" << endl;
        cin >> input_data;
        stringstream data_stream(input_data);
        data_stream >> temp_out >> temp_home >> sens_mov >> light_home;
    }
    return 0;
}
