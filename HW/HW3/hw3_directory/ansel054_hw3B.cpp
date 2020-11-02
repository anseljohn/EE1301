// EE 1301 
// HW 3B
// John Anselmo
// ansel054

// This program steps iterations amount of times, randomly stepping [-updateSizeInput, updateSizeInput] size steps

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int randWalk(int oldValue, int updateSize);

int main() {
    srand(time(NULL));
    int initVal = -1;
    int iterations;
    int updateSizeInput; // The inputed update size

    cout << "Please enter an initial integer value in the range [0,255]: ";
    cin >> initVal;
    while (initVal < 0 || initVal > 255) {
        cout << "Value must be between 0 and 255. Please enter an initial value in the range [0,255]: ";
        cin >> initVal;
    }

    cout << "Please enter the desired number of iterations: ";
    cin >> iterations;
    cout << "Please enter the size of each possible update for each iteration: ";
    cin >> updateSizeInput;

    for (int i = 0 ; i < iterations; i++) {
        cout << "Value at iteration # " << (i + 1) << " is: " << randWalk(initVal, updateSizeInput) << endl;
    }

    return 0;
}

// int oldValue: initial value on initial call, but the previous value on subsequent calls
// int updateSize: the negative min and positive max random number to be added/subtracted from old value
// output: newValue, the oldValue + random number from -updateSize to +updateSize
int randWalk(int oldValue, int updateSize) {
    int newValue = oldValue + (rand() % (2 * updateSize + 1) - updateSize);
    if (newValue > 255) {
        newValue = 255;
    } else if (newValue < 0) {
        newValue = 0;
    }
    return newValue;
}