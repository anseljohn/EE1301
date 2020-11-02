// EE 1301 
// HW 2A
// John Anselmo
// ansel054

#include <iostream>
#include <string>

using namespace std;

int main() { // a-z = 97-122 A-Z = 65-90
    string in;
    char cVal;

    cout << "Enter input >> ";
    cin >> in;
    cVal = in.at(0);

    if (in.length() > 1) {
        cout << "INPUT TOO LONG" << endl;
    } else if (cVal >= '0' && cVal <= '9') {
        cout << "DIGIT 0-9" << endl;
    } else if (cVal >= 'a' && cVal <= 'z') {
        cout << "LOWER CASE ALPHABETICAL CHAR" << endl;
    } else if (cVal >= 'A' && cVal <= 'Z') {
        cout << cVal << " UPPER CASE ALPHABETICAL CHAR" << endl;
    } else {
        cout << "NEITHER DIGIT NOR ALPHABETICAL CHAR" << endl;
    }

    return 0;
}