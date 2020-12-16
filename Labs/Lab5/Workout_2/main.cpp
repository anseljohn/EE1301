#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


double *momentum(double velocity[3], double mass);
double *randVec();

int main () {
    srand(time(NULL));
    // for (int i = 0; i < 10; i++) {
        double *momentums = momentum(randVec(), (rand() % 9) + 1);
        for ( int i = 0; i < 3; i++ ) {
            cout << *(momentums + i) << endl;
        }
        delete[] momentums;
        cout << endl << endl;
    // }
 
   return 0;
}

double *momentum(double velocity[], double mass) {
    double momentum[3];
    for (int i = 0; i < 3; i++) {
        double vel = velocity[i];
        momentum[i] = vel * mass;
        cout << momentum[i] << endl;
    }

    return momentum;
}

double *randVec() {
    double *velocities[3];
    for (int i = 0; i < 3; i++) {
        velocities[i] = (rand() % 200) - 100;
    }

    return velocities;
}