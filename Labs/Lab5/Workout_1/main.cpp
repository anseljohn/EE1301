#include <iostream>
#include "DeckOfCards.cpp"
using namespace std;

void displayHand(int pHand[], int pCardCount);
int main() {

    DeckOfCards deck;
    int hand[4] = {0};

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            hand[j] = deck.dealCard();
        }
        displayHand(hand, 4);
        cout << endl;
    }


    return 0;
}

void displayHand(int pHand[], int pCardCount) {
    for (int i = 0; i < pCardCount; i++) {
        // 0 1 2 3 4 5 6 7 8  9  10 11 12 13 14 15 16 . . . 51
        // A 2 3 4 5 6 7 8 9 10	  J	 Q  K  A  2  3	4 . . .	K

        int card = pHand[i] % 13;
        string printed;
        if (card == 0) {
            printed = "A";
        } else if (card == 10) {
            printed = "J";
        } else if (card == 11) {
            printed = "Q";
        } else if (card == 12) {
            printed = "K";
        } else {
            printed = to_string(card);
        }
        cout << printed << " ";
    }
}