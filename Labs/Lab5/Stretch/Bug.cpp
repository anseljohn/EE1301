#include <iostream>
#include "Bug.h"

using namespace std;

// Constructors
Bug::Bug() {
    position = 0;
    dir = 1;
}

Bug::Bug(int pPosition) {
    position = pPosition;
    dir = 1;
}


// Functions
void Bug::move() {
    position += dir;
    display();
}

void Bug::turn() {
    dir *= -1;
}

void Bug::display() {
    cout << "position = " << position << ", direction = " << dir << endl;
}