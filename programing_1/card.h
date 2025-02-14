#ifndef CARD_H
#define CARD_H

class Card {
private:
    char suit;
    char rank;

public:
    Card(char s, char r); // Constructor to create a Card
                          // sets the suit and rank
    Card();               // default Card constructor needed for array
    void displayCard();   // display the Card
                          // example: AC, 10S, KD
    int compareCard(Card other);
};

#endif // CARD_H