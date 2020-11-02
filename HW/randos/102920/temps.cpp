#include <iostream>
using namespace std;

int main() {
    int amountTemps;
    int min = 0;
    int max = 0;
    int avg = 0;
    double avgChange = 0;

    cout << "How many temperatures do you want to enter? ";
    cin >> amountTemps;
    int temps[amountTemps];

    cout << "Enter four daily temps (-40 to 120), separated by whitespace:\n";
    for (int i = 0; i < amountTemps; i++) {
        cin >> temps[i];
    }

    min = temps[0];
    max = min;
    
    for (int i = 0; i < amountTemps; i++) {
        if (temps[i] > max) {
            max = temps[i];
        }

        if (temps[i] < min) {
            min = temps[i];
        }

        avg += temps[i];
    }
    avg /= amountTemps;

    for (int i = 1; i < amountTemps; i++) {
        avgChange += temps[i] - temps[i - 1];
    }

    avgChange /= amountTemps - 1;

    cout << "Max: " << max << "\nMin: " << min << "\nAvg: " << avg << "\nAverage Change: " << avgChange << endl;

    return 0;
}