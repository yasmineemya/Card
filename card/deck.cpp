#include "deck.h"
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>


CardDeck::CardDeck() {
    std::string suits[] = { "club", "diamond", "heart", "spade" };
    std::string values[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10",
                           "Jack", "Queen", "King", "Ace" };

    for (const std::string& suit : suits) {
        for (const std::string& rank : values) {
            allCards.push_back(new Card(rank, suit));
        }
    }
}

/**CardDeck::~CardDeck() {
    for (Card* card : allCards) {
        delete card;
    }
}**/

void CardDeck::shuffle() {
    while (!shuffledDeck.empty()) {
        shuffledDeck.pop();
    }

    std::vector<Card*> mixed = allCards;
    std::shuffle(mixed.begin(), mixed.end(), std::default_random_engine(std::time(nullptr)));

    for (Card* card : mixed) {
        shuffledDeck.push(card);
    }
    std::cout << "\nShuffled deck size: " << shuffledDeck.size() << std::endl;

}

Card* CardDeck::getCard() {
    if (shuffledDeck.empty()) return nullptr;
    Card* top = shuffledDeck.top();
    shuffledDeck.pop();
    return top;
}
