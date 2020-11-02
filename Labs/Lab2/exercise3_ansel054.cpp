#include <iostream>
using namespace std;

int main() {
    int int1;
    int int2;
    char op;
    int computed;

    cout << "Enter a simple equation: ";
    cin >> int1 >> op >> int2;
    if (op == '+') {
        computed = int1 + int2;
    } else if (op == '-') {
        computed = int1 - int2;
    } else if (op == '/') {
        computed = int1 / int2;
    } else if (op == '*') {
        computed = int1 * int2;
    } else {
        cout << "Ain't that good of a calculator :(" << endl;
    }
    
    cout << int1 << op << int2 << " = " << computed << endl;
    return 0;
}