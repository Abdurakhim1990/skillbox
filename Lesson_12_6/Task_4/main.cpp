#include <iostream>

using namespace std;

int main()
{
    float frequency[10];
    cout << "Task 4. Radio receiver" << endl;
    for(int i = 0; i < 10; i++){
        cout << "Input the frequency of the " << i + 1 << " channel: ";
        cin >> frequency[i];
    }
    cout << "Select a channel: ";
    int channel;
    cin >> channel;
    if(channel > 10 || channel < 0){
        cout << "Wrong channel!" << endl;
    } else if(channel == 0){
        cout << "Receiver Off." << endl;
    } else {
        cout << "Channel " << channel << ". Frequency " << frequency[channel - 1] << endl;
    }
    return 0;
}
