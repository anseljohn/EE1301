// EE 1301 
// HW 3C
// John Anselmo
// ansel054

// This program runs various wheel count and maximum number slot machines 1,000,000 times to calculate simulated probability vs the theoretical

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

int spin(int max, int wheelCount);

int main() {
    srand(time(NULL));
    int N = 1000000; // As per the instructions, run each pair of (wheelcount, max) N times!
    int wins = 0; // wins defaults to 0, as soon as there is one, it increments

    //w = 3, 4, 5, 6 and d = 9, 12, 15, ..., 27.
    // start at 3, increment by 1 until 6
    for (int wheelCount = 3; wheelCount <= 6; wheelCount++) {
        // Start at 9, increment by 3 until 27!
        for (int max = 9; max <= 27; max += 3) {
            for (int i = 0; i < N; i++) {
                if (spin(max, wheelCount)) { // Since spin returns 1 when winning
                    wins++;
                }
            }

            // Formatting for output readability.
            cout << "w=" << wheelCount << ", d=" << max << ": Simulated probability = m/n = "
            << fixed << setprecision(4) << (((double) wins) / ((double)N)) * 100.0 << "%."  // Almost forgot to multiply by 100 for %!
            << " Theoretical probability: " << fixed << setprecision(6) << 100.0 * (max / pow(max, wheelCount)) << "%." << endl;
            wins = 0;
        }
    }


    return 0;
}


// int max: the outer bounds for the random number
// int wheelCount: the number of wheels on the mation
// output: 0 (false), 1 (true): 0 when losing (not matching), 1 when winning (all matching)
// spin(int max, int wheelCount): spins wheelCount wheels from 1 to max. If all wheelCount wheels match, return 1, else, return 0
int spin(int max, int wheelCount) {
    int nums[wheelCount];
    for (int i = 0; i < wheelCount; i++) {
        nums[i] = (rand() % max + 1);
    }

    int comparison = nums[0];
    for (int i = 1; i < wheelCount; i++) {
        if (nums[i] != comparison) {
            return false;
        }
    }
    return true;
}