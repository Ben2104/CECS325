#ifndef DECK_H
#define DECK_H

#include "card.h"

class Deck {
private:
    Card cards[52];
    int currentCard;

public:
    Deck(); // Constructor which creates a deck of 52 Cards
    Card deal(); // Deal a Card
    void displayDeck(); // Show all the Cards in the Deck
    void shuffle(); // Shuffle all the Cards in the Deck
};

#endif // DECK_H