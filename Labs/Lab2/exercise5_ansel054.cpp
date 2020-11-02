#include <iostream>
using namespace std;

int main() {
    int hoursWorked;
    int dependents;
    double pay = 0.0;
    const float BASE_RATE = 16.78;

    cout << "Hours worked: ";
    cin >> hoursWorked;
    cout << "Number of dependents: ";
    cin >> dependents;

    if (hoursWorked > 40) {
        pay += BASE_RATE * 40;
        hoursWorked -= 40;
        pay += 1.5 * BASE_RATE * hoursWorked;
    } else {
        pay += BASE_RATE * hoursWorked;
    }

    cout << hoursWorked << endl;

    cout << "Ideal total pay: $" << pay << endl;
    cout << "Social security witholding: $" << pay*0.06 << endl;
    cout << "Federal income witholding: $" << pay*0.14 << endl;
    cout << "State income witholding: $" << pay*0.05 << endl;
    cout << "Union dues witholding: 10" << endl;

    pay = pay * (1.0 - 0.06 - 0.14 - 0.05) - 10;

    if (dependents >= 3) {
        pay -= 35;
        cout << "Dependent healthcare witholding: $35" << endl;
    }
    cout << "Net pay: " << pay << endl;
    return 0;
}