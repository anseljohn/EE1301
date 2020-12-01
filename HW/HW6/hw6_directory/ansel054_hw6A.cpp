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
    srand(time(NULL));
    return rand()%(mMaxRoll - mMinRoll + 1) + mMinRoll;
}

/*******************************
 *         END DIE CODE        *
 *******************************/

int main() {

    int inputMinRoll;
    int inputMaxRoll;
    cout << "Let's set up a die to roll. What are the minimum and maximum\nvalues for this die?" << endl;
    cout << "Minimum: ";
    cin >> inputMinRoll;
    cout << "Maximum: ";
    cin >> inputMaxRoll;

    Die mDie(inputMinRoll, inputMaxRoll);

    cout << "The die is rolled 10 times. The results of those rolls are:";
    for (int i = 0; i < 9; i++) {
        cout << "Roll #" << (i + 1) << " was: " << mDie.roll() << endl;
    }
    cout << "Roll #9 was: " << mDie.roll();


    return 0;
}