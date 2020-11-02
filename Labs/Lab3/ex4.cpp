#include <iostream>
#include <math.h>  
using namespace std;

double genNewGuess(double n, double oldGuess);
double babylonianRoot(double n);

int main() {
    int n;
    char cont = 'y';

    while (cont == 'y') {
        cout << "Enter a positive integer for square root: ";
        cin >> n;
        if (n <= 0) {
            cout << "\nNon-positive number entered...\nTerminating program...\n" << endl;
            return 0;
        }
        cout << "Square root of " << n << " is " << babylonianRoot(n) << endl;
        cout << "Continue? (yY/nN): ";
        cin >> cont;
        cont = tolower(cont);
    }


    return 0;
}

double genNewGuess(double n, double oldGuess) {
    return ( oldGuess + n / oldGuess ) / 2;
}

double babylonianRoot(double n) {
    double oldGuess;
    double newGuess;
    double error;

    oldGuess = n/2.0;
    newGuess = genNewGuess(n, oldGuess);
    error = abs(newGuess - oldGuess);
    while (error > 0.01 * genNewGuess(n, newGuess)) {
        error = abs(newGuess - genNewGuess(n, newGuess));
        newGuess = genNewGuess(n, newGuess);
    }

    return newGuess;
}