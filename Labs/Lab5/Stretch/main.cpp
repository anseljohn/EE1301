#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "Bug.h"
using namespace std;

int main() {
    srand(time(NULL));

    Bug myBug;
    int moves;

    cout << "How many moves?>> ";
    cin >> moves;

    for (int i = 0; i < moves; i++) {
        if (rand() % 2 == 0) {
            myBug.turn();
        }

        myBug.move();
    }
    
    return 0;
}