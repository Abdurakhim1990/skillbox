#include <iostream>
#include <fstream>

using namespace std;

void Collector(int * bill, int size);
void Client(int * bill, int size);

int main()
{
    cout << "Task 4. Implementing ATM Simulation." << endl;
    int bills[5] {0, 0, 0, 0, 0};

    ifstream in_atm("../Task_4_Lesson_20_5/atm.bin", ios::binary);
    if(in_atm.is_open()){
        in_atm.read((char*) bills, sizeof (bills));
    }
    in_atm.close();

    char operation;
    cout << "Input: \"+\" for Collector or \"-\" for Client." << endl;
    cin >> operation;
    if(operation == '+'){
        Collector(bills, sizeof (bills)/sizeof (int));
    } else if(operation == '-'){
        Client(bills, sizeof (bills)/sizeof (int));
    }

    ofstream out_atm("../Task_4_Lesson_20_5/atm.bin", ios::binary);
    out_atm.write((char*) bills, sizeof (bills));
    out_atm.close();

    return 0;
}

void Collector(int * bill, int size)
{
    int numb_bills = 0;
    for(int i = 0; i < size; ++i){
        numb_bills += bill[i];
    }
    for(int i = 0; numb_bills < 1000; ++i){
        i %= size;
        int temp = rand() % (1001 - numb_bills);
        numb_bills += temp;
        bill[i] += temp;
    }
}

void Client(int * bill, int size)
{
    int withdrawal_amount;
    int atm_amount = 0;
    do{
        cout << "Enter the amount to withdraw: ";
        cin >> withdrawal_amount;
    } while(withdrawal_amount%100 != 0 || withdrawal_amount < 0);

    int mass[size];
    for(int i = 0; i < size; ++i){
        atm_amount += ((i==0) *100 * bill[i]) + ((i==1) * 500 * bill[i]) + ((i==2) * 1000 * bill[i])
                + ((i==3) * 2000 * bill[i]) + ((i==4) * 5000 * bill[i]);
        mass[i] = bill[i];
    }

    if(atm_amount >= withdrawal_amount){
        for(int i = size - 1; i >= 0;){
            int bank_note = (i==4) * 5000 + (i==3) * 2000 + (i==2) * 1000
                    + (i==1) * 500 + (i==0) * 100;
            if((withdrawal_amount < bank_note) || withdrawal_amount == 0 || mass[i] == 0){
                --i;
            } else{
                withdrawal_amount -= bank_note;
                --mass[i];
            }
        }
        if(withdrawal_amount == 0){
            for(int i = 0; i < size; ++i){
                bill[i] = mass[i];
            }
        } else{
            cout << "Operation not possible" << endl;
        }
    } else{
        cout << "Operation not possible" << endl;
    }
}
