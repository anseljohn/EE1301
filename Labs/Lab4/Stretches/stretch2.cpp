#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cout << "Error: besides ./call, there should be one string argument." << endl;
    } else {
        string toSwap = argv[1];
        int size = toSwap.size();
        char beginning = toSwap[0];
        toSwap[0] = toSwap[size - 1];
        toSwap[size - 1] = beginning;
        cout << toSwap << endl;
    }


    return 1;
}