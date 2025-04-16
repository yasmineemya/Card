// card.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "deck.h"
#include "war.h"

int main() {
    std::cout << "\n   starting game";
    std:: cout<< "\n      🃁🃜🃚🃖🂭🂺  \n";

    WarGame game;
    game.startGame();
    return 0;
}

    /**CardDeck deck;

    std::cout << "1st Shuffle:\n";
    deck.shuffle();
    for (int i = 0; i < 10; ++i) {
        Card* card = deck.getCard();
        if (card) {
            std::cout << card->display() << std::endl;
        }
    }

    std::cout << "\n2nd Shuffle:\n";
    deck.shuffle();
    for (int i = 0; i < 10; ++i) {
        Card* card = deck.getCard();
        if (card) {
            std::cout << card->display() << std::endl;
        }
    }**/





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
