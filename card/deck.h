#pragma once
#ifndef DECK_H
#define DECK_H

#include <vector>
#include <stack>
#include <string>
#include "card.h"

class CardDeck {
public:
    CardDeck();
    void shuffle();
    Card* getCard();

private:
    std::vector<Card*> allCards;
    std::stack<Card*> shuffledDeck;
};

#endif
