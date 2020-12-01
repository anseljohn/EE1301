// EE 1301 
// HW 6A
// John Anselmo
// ansel054

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*******************************
 *          DIE CODE           *
 *******************************/
class Die {
    public:
        Die();
        Die(int pMinRoll, int pMaxRoll);
        int roll();

    private:
        int mMinRoll;
        int mMaxRoll;
};

Die::Die() {
    mMinRoll = 1;
    mMaxRoll = 6;
}

Die::Die(int pMinRoll, int pMaxRoll) {
    mMinRoll = pMinRoll;
    mMaxRoll = pMaxRoll;
}

int Die::roll() {
    return rand()%(mMaxRoll - mMinRoll + 1) + mMinRoll;
}

/*******************************
 *         END DIE CODE        *
 *******************************/

int main() {
    srand(time(NULL));

    int inputMinRoll;
    int inputMaxRoll;
    cout << "Let's set up a die to roll. What are the minimum and maximum\nvalues for this die?" << endl;
    cout << "Minimum Value: ";
    cin >> inputMinRoll;
    cout << "Maximum Value: ";
    cin >> inputMaxRoll;

    Die mDie(inputMinRoll, inputMaxRoll);

    cout << "\nThe die is rolled 10 times. The results of those rolls are:\n";
    for (int i = 0; i < 8; i++) {
        cout << "Roll #" << (i + 1) << " was: " << mDie.roll() << endl;
    }
    cout << "Roll #9 was: " << mDie.roll();


    return 0;
}