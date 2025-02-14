#include "card.h"
#include <iostream>
#include <string>

using namespace std;

Card::Card()
{
    suit = ' ';
    rank = ' ';
}
Card::Card(char s, char r)
{
    suit = s;
    rank = r;
};

void Card::displayCard()
{
    cout << (rank == 'T' ? "10" : string(1, rank));
    cout << (suit == 'C'   ? "\u2663" // Unicode for ♣
             : suit == 'D' ? "\u2666" // Unicode for ♦
             : suit == 'H' ? "\u2665" // Unicode for ♥
                           : "\u2660");
}
int Card::compareCard(Card other)
{
    string ranks = "A23456789TJQK";
    int currentRank = ranks.find(rank) + 1;
    int otherRank = ranks.find(other.rank) + 1;
    if (currentRank > otherRank)
    {
        return 1;
    }
    else if (currentRank < otherRank)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}