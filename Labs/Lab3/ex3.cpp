#include <iostream>
#include <math.h>  
using namespace std;

double genNewGuess(double n, double oldGuess);

int main() {
    int n;
    double oldGuess;
    double newGuess;
    double error;

    cout << "Enter a positive integer for square root: ";
    cin >> n;
    if (n <= 0) {
        cout << "\nNon-positive number entered...\nTerminating program...\n" << endl;
        return 0;
    }

    oldGuess = n/2.0;
    newGuess = genNewGuess(n, oldGuess);
    error = abs(newGuess - oldGuess);
    while (error > 0.01 * genNewGuess(n, newGuess)) {
        error = abs(newGuess - genNewGuess(n, newGuess));
        newGuess = genNewGuess(n, newGuess);

        cout << newGuess << endl;
    }

    cout << "Final answer: " << newGuess << endl;

    cout << "Actual answer: " << sqrt(n) << endl;

    return 0;
}

double genNewGuess(double n, double oldGuess) {
    return ( oldGuess + n / oldGuess ) / 2;
}