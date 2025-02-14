#include <iostream>
#include "deck.h"
#include <array>

using namespace std;

Deck::Deck()
{
    currentCard = 0;
    char suits[] = {'C', 'S', 'D', 'H'};
    char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    int sizeOfsuits = sizeof(suits) / sizeof(suits[0]);
    int sizeOfranks = sizeof(ranks) / sizeof(ranks[0]);
    int index = 0;

    for (int i = 0; i < sizeOfsuits; i++)
        for (int j = 0; j < sizeOfranks; j++)
        {
            {
                cards[index++] = Card(suits[i], ranks[j]);
            };
        };
}
void Deck::displayDeck()
{
    for (int i = 0; i < 52; i++)
    {
        cards[i].displayCard();

        if (i == 12 || i == 25 || i == 38 || i == 51)
        {
            cout << endl;
        }
        else
        {
            cout << ", ";
        }
    };
}
void Deck::shuffle()
{
    srand(time(NULL));
    for (int i = 0; i < 52; i++)
    {
        int randomIndex = i + (rand() % (52 - i));
        Card temp = cards[i];
        cards[i] = cards[randomIndex];
        cards[randomIndex] = temp;
    }
}
Card Deck::deal()
{
    if (currentCard < 52)
    {
        return cards[currentCard++];
    }
    else
    {
        return Card();
    }
}