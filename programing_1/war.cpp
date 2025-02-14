/*
    Name: Hoang Do
    ID: 032917233
    Date: 02/13/2025
    Programing assignment 1: One Card War
*/

#include "deck.h"
#include "card.h"
#include <iostream>

using namespace std;

int main()
{
    Deck d;
    
    string firstPlayer;
    string secondPlayer;
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
    
    cout << "Original Deck:" << endl;
    d.displayDeck();
    d.shuffle();
    cout << endl;
    cout << "Shuffle Deck:" << endl;
    d.displayDeck();
    cout << endl;

    for (int i = 0; i < 26; i++)
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
    cout << endl;
    cout << "-------Final Stats--------" << endl;
    cout << "\t" << firstPlayer << " vs.\t" << secondPlayer << endl;
    cout << "Wins\t" << card1_win << "\t\t" << card2_win << endl;
    cout << "Lose\t" << card1_lose << "\t\t" << card2_lose << endl;
    cout << "Tie\t" << tie << "\t\t" << tie << endl;
    return 0;
}