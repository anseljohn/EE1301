#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "DeckOfCards.h"
using namespace std;

DeckOfCards::DeckOfCards() {
    srand(time(NULL));
    for (int i = 0; i <= deckN; i++) {
        deck[i] = i;
    }
    shuffle();

    nextCardIndex = 0;
}

int DeckOfCards::dealCard() {
    if (nextCardIndex > deckN) {
        shuffle();
        nextCardIndex = 0;
    }

    return deck[nextCardIndex];
}

void DeckOfCards::shuffle() {
    for (int i = deckN; i >= 1; i--) {
        int replaceIndex = rand() % deckN;
        int holder = deck[i];
        deck[i] = deck[replaceIndex];
        deck[replaceIndex] = holder;
    }
}