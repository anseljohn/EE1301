// EE 1301 
// HW 2B
// John Anselmo
// ansel054

#include <iostream>
#include <string>
using namespace std;

char apFromBool(bool ap);

int main() {
    int time;
    char morningOrNight;
    bool isNight;
    int tTime;
    char forwardOrBackward;

    int twelves;
    int trueTime;
    bool trueIsNight; // 0 = am | 1 = pm

    cout << "Enter the current time (A for AM, P for PM): ";
    cin >> time >> morningOrNight;
    morningOrNight = tolower(morningOrNight);

    cout << "How many hours forward or backward do you want to move the clock" << endl << "(F for forward, B for backward): ";
    cin >> forwardOrBackward >> tTime;
    forwardOrBackward = tolower(forwardOrBackward);

    // I chose to convert whether it was am or pm in order to set it equal to the opposite in case
    // it was going forward or back in an odd multiple of 12 (2AM + 1(12) = 2PM, 2AM + 2(12) = 2AM still)
    isNight = morningOrNight == 'p';
    
    // if we go forward then we should add the time travelling, if backward then we should subtract
    // (but take the abs value because the modulo gives the actual time and it can't be negative!)
    if (tTime % 12 != 0) {
        if (forwardOrBackward == 'f') {
            tTime += time;
        } else if (forwardOrBackward == 'b') {
            tTime -= time;
        }
    }

    // Only mod 12 if greater than 12 so noon and 12am don't become 0
    if (tTime % 12 == 0) {
        trueTime = time;
    } else if (tTime > 12) {
        trueTime = tTime % 12;
    } else {
        trueTime = tTime;
    }

    // This part is why I used a boolean for whether it was morning or night
    twelves = tTime / 12;
    if (twelves % 2 == 1) {
        cout << endl << endl << twelves << endl << endl;
        trueIsNight = !isNight;
    } else {
        trueIsNight = isNight;
    }

    cout << "New time: " << trueTime << " " << apFromBool(trueIsNight) << "M" << endl;
    return 0;
}

// I didn't want a random if statement and an extra variable so I just used a method
// to directly use it in the final cout
char apFromBool(bool ap) {
    if (ap) {
        return 'P';
    } else {
        return 'A';
    }
}