// Name: Hoang Do
// Class (CECS 325-01)
// Project Name (Prog 2 – More War)
// Due Date (02/25/2025)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program
#include <iostream>
#include <vector>
#include <random>
using namespace std;

class Card
{
private:
    char suit, rank;

public:
    Card(char, char);
    void displayCard();
    int compareCard(Card);
};

Card::Card(char s, char r)
{
    suit = s;
    rank = r;
}
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
class Deck
{
private:
    vector<Card> deck;
    int currentCard;
    
public:
    Deck();
    void displayDeck();
    void shuffle();
    bool isEmpty();
    Card deal();
};
Deck::Deck()
{
    currentCard = 0;
    char suits[] = {'C', 'S', 'D', 'H'};
    char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

    for (char suit : suits)
    {
        for (char rank : ranks)
        {
            deck.push_back(Card(suit, rank));
        }
    }
}
void Deck::displayDeck()
{
    for (int i = 0; i < 52; i++)
    {
        deck[i].displayCard();

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
        Card temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}
bool Deck::isEmpty()
{
    return deck.empty();
}
Card Deck::deal()
{
    if (currentCard < 52)
    {
        deck.pop_back();
        return deck[currentCard++];
    }
    else
    {   
        string str = "Deck is empty";
        throw string(str);
    }
}
int main()
{
    Deck d;

    string firstPlayer;
    string secondPlayer;
    int games;
    int card1_win = 0;
    int card1_lose = 0;
    int card2_win = 0;
    int card2_lose = 0;
    int tie = 0;

    cout << "Enter the name of the first player: ";
    cin >> firstPlayer;
    cout << "Enter the name of the second player: ";
    cin >> secondPlayer;
    cout << endl;
    cout << "How many games will they play? ";
    cin >> games;
    cout << "Original Deck:" << endl;
    d.displayDeck();
    d.shuffle();
    cout << endl;
    cout << "Shuffle Deck:" << endl;
    d.displayDeck();
    cout << endl;
    for (int i = 0; i < games; i++)
    {
        try
        {
            Card card1 = d.deal();
            Card card2 = d.deal();
            cout << "Game " << i + 1 << endl;
            cout << "--------" << endl;
            cout << firstPlayer << " => ";
            card1.displayCard();
            cout << endl;
            cout << secondPlayer << " => ";
            card2.displayCard();
            cout << endl;
            if (card1.compareCard(card2) == 1)
            {
                cout << firstPlayer << " => Winner" << endl;
                card1_win += 1;
                card2_lose += 1;
                cout << endl;
            }
            else if (card1.compareCard(card2) == -1)
            {
                cout << secondPlayer << " => Winner" << endl;
                card2_win += 1;
                card1_lose += 1;
                cout << endl;
            }
            else
            {
                cout << "Tie game" << endl;
                cout << endl;
                tie += 1;
            }
        }
        catch (string str)
        {
            if (d.isEmpty() == true)
            {
                cerr << "Exception -  " << str << endl;
                break;
            }
        }
    }
    cout << endl;
    cout << "-------Final Stats--------" << endl;
    cout << "\t" << firstPlayer << " vs.\t" << secondPlayer << endl;
    cout << "Wins\t" << card1_win << "\t\t" << card2_win << endl;
    cout << "Lose\t" << card1_lose << "\t\t" << card2_lose << endl;
    cout << "Tie\t" << tie << "\t\t" << tie << endl;
    return 0;
}
