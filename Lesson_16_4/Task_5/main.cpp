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

int SensorProcessing(int time, int t_out, int t_home, string sen_mov, string light_home, int* state_machine)
{
    int light_temp = 0;
    if(*state_machine & (1 << EATING_AT_HOME)){
        if(t_out < 0){
            *state_machine |= (1 << WATER_HEATING);
        } else if(t_out > 5){
            *state_machine &= ~(1 << WATER_HEATING);
        }
        if(t_home < 22){
            *state_machine |= (1 << INDOOR_HEATING);
        } else if(t_home >= 25){
            *state_machine &= ~(1 << INDOOR_HEATING);
        }
        if(sen_mov == "yes" && (time > 16 || time < 5)){
            *state_machine |= (1 << LIGHT_IN_GARDEN);
        } else{
            *state_machine &= ~(1 << LIGHT_IN_GARDEN);
        }
        if(t_home >= 30){
            *state_machine |= (1 << INDOOR_CONDITIONER);
        } else if(t_home <= 25){
            *state_machine &= ~(1 << INDOOR_CONDITIONER);
        }
        if(light_home == "on"){
            *state_machine |= (1 << LIGHT_IN_HOUSE);
            if(time < 16){
                light_temp = 5000;
            } else if(time > 20){
                light_temp = 2700;
            } else{
                light_temp = -575 * time + 14200;
            }
        } else{
            *state_machine &= ~(1 << LIGHT_IN_HOUSE);
        }
    } else{
        *state_machine = 0;
    }
    return light_temp;
}

void ProcessStatusOutput(int state_machine, int light_temp)
{
    cout << "===================================\n";
    if(state_machine & (1 << EATING_AT_HOME)){
        cout << "Whole house circuit breaker is on.\n";
    } else{
        cout << "Whole house circuit breaker is off!\n";
    }
    if(state_machine & (1 << LIGHT_IN_HOUSE)){
        cout << "The lights in the house are on!\n";
        cout << "\tColor temperature is " << light_temp << endl;
    } else{
        cout << "The lights in the house are off!\n";
    }
    if(state_machine & (1 << LIGHT_IN_GARDEN)){
        cout << "The lights in the garden are on!\n";
    } else{
        cout << "The lights in the garden are off!\n";
    }
    if(state_machine & (1 << INDOOR_HEATING)){
        cout << "Heating in the room is on!\n";
    } else{
        cout << "Heating in the room is off!\n";
    }
    if(state_machine & (1 << WATER_HEATING)){
        cout << "The heating of the water supply from the well is turned on!\n";
    } else{
        cout << "The heating of the water supply from the well is turned off!\n";
    }
    if(state_machine & (1 << INDOOR_CONDITIONER)){
        cout << "Indoor air conditioner is on!\n";
    } else{
        cout << "Indoor air conditioner is off!\n";
    }
    cout << "======================================\n";
    cout << "======================================\n\n\n";
}

int main()
{
    cout << "Task 5. Smart House" << endl;
    int temp_out;
    int temp_home;
    string sens_mov;
    string light_home;
    int time_clock = 0;
    string input_data;
    int state_of_machine = 1 << EATING_AT_HOME;
    for(int i = 0; i < 48; i++){
        time_clock = i%24;
        cout <<"Input data on the " << i/24 + 1 << " day at " << time_clock << ":00 o'clock to format:" << endl;
        cout << "TemperOut -> TemperHome -> SenseMovem (yes/no) -> LightInTheHome (on/off)" << endl;
        getline(cin, input_data);
        stringstream data_stream(input_data);
        data_stream >> temp_out >> temp_home >> sens_mov >> light_home;
        int light_temp = SensorProcessing(time_clock, temp_out, temp_home, sens_mov, light_home, &state_of_machine);
        ProcessStatusOutput(state_of_machine, light_temp);
    }
    return 0;
}
