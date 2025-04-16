#include "war.h"
#include "deck.h"
#include <iostream>
#include <string>


WarGame::WarGame() {
    dealCards();
}

void WarGame::dealCards() {
    CardDeck deck;
    deck.shuffle();
    std::cout << "   Deck shuffled\n";


    int playerCount = 0;
int computerCount = 0;

for (int i = 0; i < 52; i++) {
    Card* card = deck.getCard();
    if (!card) {
        std::cerr << "NULL card at index " << i << "!\n";
        break;
    }

    if (i % 2 == 0) {
        std::cout << "\nplayer gets: " << card->display() << "\n";
        playerDeck.push(card);
        playerCount++;
    } else {
        std::cout << "Computer gets: " << card->display() << "\n";
        computerDeck.push(card);
        computerCount++;
    }
}

std::cout << "\nTotal  cards  dealt: " << (playerCount + computerCount) << "\n";
std::cout << " Player got: " << playerCount << " cards\n";
std::cout << " Computer got: " << computerCount << " cards\n";
}





void WarGame::startGame() {
    std::string input;
    while (!playerDeck.empty() && !computerDeck.empty()) {
        playTurn();

        std::cout << "\n  Continue? (y/n): ";
        std::getline(std::cin, input);
        if (input != "y" && input != "Y") {
        std::cout << "\n    ⚀⚁⚂⚃⚄⚅\n";
            std::cout << "You quit the game.\n";
            std::cout << "You have " << playerDeck.size() << " cards.\n";
            std::cout << "Computer has " << computerDeck.size() << " cards.\n";
    
            return;
        }
    }

    if (playerDeck.empty())
        std::cout << "\ncomputer wins the game!\n";
    else
        std::cout << "\n ˗ˏˋ ★ ˎˊ˗ YOU WIN THE GAME  ˗ˏˋ ★ ˎˊ˗ \n";
}

void WarGame::playTurn() {
    if (playerDeck.empty() || computerDeck.empty()) return;

    Card* playerCard = playerDeck.front(); playerDeck.pop();
    Card* computerCard = computerDeck.front(); computerDeck.pop();

    std::cout << "\nyou played: ";
    playerCard->print();
    std::cout << "computer played: ";
    computerCard->print();

    std::vector<Card*> pile = { playerCard, computerCard };

    int result = playerCard->compareValue(computerCard);

    if (result > 0) {
        std::cout << "✮you WIN this round✮\n";
        collectCards(playerDeck, pile);
    }
    else if (result < 0) {
        std::cout << "computer wins this round\n";
        collectCards(computerDeck, pile);
    }
    else {
        std::cout << "    WAR!\n";
        handleWar(pile);
    }
}

void WarGame::handleWar(std::vector<Card*>& warPile) {
    if (playerDeck.size() < 2 || computerDeck.size() < 2) {
        std::cout << "not enough cards\n";
        return;
    }

    warPile.push_back(playerDeck.front()); playerDeck.pop(); // face-down
    warPile.push_back(computerDeck.front()); computerDeck.pop();

    Card* playerCard = playerDeck.front(); playerDeck.pop();
    Card* computerCard = computerDeck.front(); computerDeck.pop();

    warPile.push_back(playerCard);
    warPile.push_back(computerCard);

    std::cout << "\nyou played war: ";
    playerCard->print();
    std::cout << "computer played war: ";
    computerCard->print();

    int result = playerCard->compareValue(computerCard);

    if (result > 0) {
        std::cout << "YOU WIN\n";
        collectCards(playerDeck, warPile);
    }
    else if (result < 0) {
        std::cout << "computer wins the war\n";
        collectCards(computerDeck, warPile);
    }
    else {
        std::cout << "tie! the war is still on\n";
        handleWar(warPile);
    }
}

void WarGame::collectCards(std::queue<Card*>& winner, std::vector<Card*>& pile) {
    for (Card* c : pile) {
        winner.push(c);
    }
    pile.clear();
}
