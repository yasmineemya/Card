#pragma once
#ifndef WAR_H
#define WAR_H

#include "deck.h"
#include <queue>
#include <vector>



class WarGame {
public:
    WarGame();
    void startGame();

private:

    std::queue<Card*> playerDeck;
    std::queue<Card*> computerDeck;

    void dealCards();
    void playTurn();
    void handleWar(std::vector<Card*>& warPile);
    void collectCards(std::queue<Card*>& winner, std::vector<Card*>& pile);

};

#endif
