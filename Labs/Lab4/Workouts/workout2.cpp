#include <iostream>
using namespace std;

void minutesToTime(int minutes, int &hours, int &mins);

int main() {

    char cont = 'y';
    int inputMins = 0;
    int hours = 0;
    int minutes = 0;

    while (cont == 'y') {
        cout << "Enter a number of minutes: ";
        cin >> inputMins;
        minutesToTime(inputMins, hours, minutes);
        cout << "HR:MIN = " << hours << ":";

        if (minutes == 0) {
            cout << "00" << endl;
        } else if (minutes < 10) {
            cout << "0" << minutes << endl;
        } else {
            cout << minutes << endl;
        }
        
        //<< ":" << minutes << endl;
        cout << "Continue? (yY/nN): ";
        cin >> cont;
        cont = tolower(cont);
    }


    return 1;
}


// This function requires reference parameters because they need to modify the actual value
void minutesToTime(int minutes, int &hours, int &mins) {
    hours = minutes / 60;
    mins = minutes - (60 * hours);
}