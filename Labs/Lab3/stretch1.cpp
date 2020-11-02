#include <iostream>
using namespace std;

int main() {

    for (int i = 1; i < 11; i++) {
        cout << i * 10 << " ";
        for (int j = 9; j > 0; j--) {
            if (i * j < 10) {
                cout << " ";
            }
            cout << i * j << " ";
            if (j == 1) {
                cout << endl;
            }
        }
    }


    return 0;
}