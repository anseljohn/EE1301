#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "DeckOfCards.h"
using namespace std;

DeckOfCards::DeckOfCards() {
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }
    shuffle();

    nextCardIndex = 0;
}

int DeckOfCards::dealCard() {
    if (nextCardIndex > 51) {
        shuffle();
        nextCardIndex = 0;
    }

    int nextCard = deck[nextCardIndex];
    nextCardIndex++;

    return deck[nextCardIndex];
}

void DeckOfCards::shuffle() {
    for (int i = 51; i >= 1; i--) {
        int replaceIndex = rand() % 51;
        int holder = deck[i];
        deck[i] = deck[replaceIndex];
        deck[replaceIndex] = holder;
    }
}