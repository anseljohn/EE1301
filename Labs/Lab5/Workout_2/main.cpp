#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


double *momentum(double velocity[3], double mass);
double *randVec();

int main () {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        double *momentums;
        double velocity[3] = {0};
        double mass = rand() % 100;

        cout << "V: {";
        for (int i = 0; i < 2; i++) {
            velocity[i] = rand() % 50;
            cout << velocity[i] << " ";
        }
        velocity[2] = rand() % 50;
        cout << velocity[2] << "}\nM: ";

        cout << mass << endl;

        momentums = momentum(velocity, mass);
    
        for ( int i = 0; i < 3; i++ ) {
            cout << *(momentums + i) << endl;
        }
        cout << endl << endl;
    }
 
   return 0;
}

double *momentum(double velocity[3], double mass) {
    double momentum[3];
    for (int i = 0; i < 3; i++) {
        momentum[i] = velocity[i] * mass;
    }

    return momentum;
}

double *randVec() {
    double velocities[3];
    for (int i = 0; i < 3; i++) {
        velocities[i] = (rand() % 200) - 100;
    }
    
    return velocities;
}