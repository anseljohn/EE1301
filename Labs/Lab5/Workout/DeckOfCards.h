#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

class DeckOfCards {
    public:
        DeckOfCards();
        int dealCard();
        void shuffle();

    private:
        int deck[52];
        int nextCardIndex;
        const int deckN = 51;
};

#endif
