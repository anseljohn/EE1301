#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int i;
    cout << "You typed the following on the command-line:" << endl;
    for (i = 0; i < argc ; i++) {
            cout << argv[i] << ", ";
    }
    cout << endl;
}
