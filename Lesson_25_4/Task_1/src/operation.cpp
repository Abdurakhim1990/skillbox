#include "operation.h"

Line Gash;

void scalpel(void)
{
    cout << "===========================================\n\n";
    cout << "Opening coordinates for the scalpel" << endl;
    inputCoord(Gash.Start);
    cout << "Final coordinates for the scalpel" << endl;
    inputCoord(Gash.End);
    cout << "The cut has been made.\n" << endl;
}

void hemostat(void)
{
    Input Hemostat;
    cout << "===========================================\n\n";
    do{
        cout << "Opening coordinates for the Hemostat" << endl;
        inputCoord(Hemostat);
    } while(!(Hemostat.x >= min(Gash.Start.x, Gash.End.x) && Hemostat.x <= max(Gash.Start.x, Gash.End.x) &&
             Hemostat.y >= min(Gash.Start.y, Gash.End.y) && Hemostat.y <= max(Gash.Start.y, Gash.End.y)));
    cout << "Hemostat installed.\n" << endl;
}

void tweezers(void)
{
    Input Tweezers ;
    cout << "===========================================\n\n";
    do{
        cout << "Opening coordinates for the Hemostat" << endl;
        inputCoord(Tweezers);
    } while(!(Tweezers.x >= min(Gash.Start.x, Gash.End.x) && Tweezers.x <= max(Gash.Start.x, Gash.End.x) &&
             Tweezers.y >= min(Gash.Start.y, Gash.End.y) && Tweezers.y <= max(Gash.Start.y, Gash.End.y)));
    cout << "Tweezers installed.\n" << endl;
}

void suture(void)
{
    Line Suture;
    cout << "===========================================\n\n";
    do{
        cout << "Opening coordinates for the suture" << endl;
        inputCoord(Suture.Start);
        cout << "Final coordinates for the suture" << endl;
        inputCoord(Suture.End);
    } while(!((Suture.Start.x == Gash.Start.x && Suture.Start.y == Gash.Start.y &&
              Suture.End.x == Gash.End.x && Suture.End.y == Gash.End.y) ||
              (Suture.Start.x == Gash.End.x && Suture.Start.y == Gash.End.y &&
              Suture.End.x == Gash.Start.x && Suture.End.y == Gash.Start.y)));
    cout << "Operation completed." << endl;
}
