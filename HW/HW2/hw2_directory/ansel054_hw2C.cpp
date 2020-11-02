// EE 1301 
// HW 2C
// John Anselmo
// ansel054

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
bool allMatch(int array[4]);

int main() {

    // Keeping track of the four numbers in an array
    int max;
    int nums [4] = {0, 0, 0, 0};
    srand(time(NULL)); // Make sure to seed!

    while (max != -1) {
        cout << "How many values do you want on each wheel? ";
        cin >> max;
        while (max < 1) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please use an acceptable input." << endl;
            cout << "How many values do you want on each wheel? ";
            cin >> max;
        }

        // Calculate 4 random numbers from 1 - max
        cout << "The wheels spin to give: ";
        for (int i = 0; i < 4; i++) {
            nums[i] = (rand() % max + 1);
            cout << nums[i] << " ";
        }
        cout << " ";
        if (allMatch(nums)) {
            cout << "Eureka!";
        } else {
            cout << "You lose.";
        }
        cout << endl;

    }
    cout << "OK, goodbye." << endl;

    return 0;
}

bool allMatch(int array[4]) {
    int comparison = array[0];
    for (int i = 1; i < 3; i++) {
        if (array[i] != comparison) {
            return false;
        }
    }
    return true;
}