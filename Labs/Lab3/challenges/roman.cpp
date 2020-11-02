#include <iostream>
using namespace std;

// I = 1
// V = 5
// X = 10
// L = 50
// C = 100
// D = 500
// M = 1000


int main() {
    const int I = 1;
    const int V = 5;
    const int X = 10;
    const int L = 50;
    const int C = 100;
    const int D = 500;
    const int M = 1000;

    int input;
    int remaining;
    int get(int input);

    cout << "Enter a number from 1 to 999: ";
    cin >> input;
    if (input < 1 || input > 999) {
        cout << "Invalid input" << endl;
        return 0;
    }

    while(remaining != 0) {
        remaining = input - get(input);
    }


}

int get(int input) {

    // If the value of the number is in [900,999] output “CM” 
    if (input >= 900 && input <= 999) {
        cout << "CM";
        return 900;
    } else if (input >= 500 && input <= 899) {    // If the value is in [500,899] output “D”
        cout << "D";
        return 500;
    } else if (input >= 100 && input <= 399) {    // If the value is in [400,499] output “CD” 
        cout << "C";
        return 400;
    } else if (input >= 90 && input <= 99) {      // If the value is in [90,99] output “XC”  
        cout << "XC";
        return 90;
    } else if (input >= 50 && input <= 89) {      // If the value is in [50,89] output “L”
        cout << "L";
        return 50;
    } else if (input >= 40 && input <= 49) {      // If the value is in [40,49] output “XL” 
        cout << "XL";
        return 40;
    } else if (input >= 10 && input <= 39) {      // If the value is in [10,39] output “X” 
        cout << "X";
        return 10;
    } else if (input == 9) {                      // If the value is 9, output “IX”
        cout << "IX";
        return 9;
    } else if (input >= 5 && input <= 8) {        // If the value is in [5,8] output “V” 
        cout << "V";
        return ;
    } else if (input == 4) {                      // If the value is 4, output “IV”
        cout << "IV";
        return 4;
    } else if (input >= 1 && input <= 3) {        // If the value is in [1,3], output “I”
        cout << "I";
        return 1;
    }
    return 0;
}