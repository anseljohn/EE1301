// EE 1301 
// HW 3A
// John Anselmo
// ansel054

// This program prints a each number, that number times until the maximum number they give, within bounds [-50, 50]

#include <iostream>
using namespace std;

int main() {
    // Defaulting input
    int input = -51;

    while (input != 0) {
        cout << "Enter an integer from -50 to 50: ";
        cin >> input;
        while (input < -50 || input > 50) {
            cin.clear();
            cout << endl << "Error: not between -50 and 50" << endl;
            cout << "Enter an integer from -50 to 50: ";
            cin >> input;    
        }

        // If it's positive, start at 1 then 22 then 333 up to n n times
        if (input > 0) {
            for (int i = 1; i <= input; i++) {
                for (int j = 0; j < i; j++) {
                    cout << i;
                }
                cout << endl;
            }
        } else { // If it's negative, start at n n times, then n-1 n-1 times, etc down to 1
            for (int i = -input; i >= 1; i--) {
                for (int j = i; j > 0; j--) {
                    cout << i;
                }
                cout << endl;
            }
        }
    }

    // once while loop exits (input == 0) say goodbye!
    cout << "Goodbye." << endl;
    return 0;
}