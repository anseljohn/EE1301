#include <iostream>
#include <math.h> 
using namespace std;

int main() {
    double restLength;
    double velocity;
    double relativeLength;
    const double LIGHT_SPEED = 3e10;

    cout << "Enter resting length: ";
    cin >> restLength;
    cout << "Enter velocity: ";
    cin >> velocity;
    
    relativeLength = restLength * pow(1-((pow(velocity, 2))/(pow(LIGHT_SPEED, 2))), 0.5);
    cout << "Relative Length: " << relativeLength << endl;
    return 0;
}