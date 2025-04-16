#include "card.h"
#include <iostream>

Card::Card(const std::string& value, const std::string& suit)
    : value(value), suit(suit) {}

std::string Card::display() const {
    return value + " of " + suit;
}

void Card::print() const {
    std::cout << display() << std::endl;
}

int Card::compareValue(Card* other) const {
    auto toInt = [](const std::string& val) -> int {
        if (val == "2") return 2;
        if (val == "3") return 3;
        if (val == "4") return 4;
        if (val == "5") return 5;
        if (val == "6") return 6;
        if (val == "7") return 7;
        if (val == "8") return 8;
        if (val == "9") return 9;
        if (val == "10") return 10;
        if (val == "Jack") return 11;
        if (val == "Queen") return 12;
        if (val == "King") return 13;
        if (val == "Ace") return 14;
        return 0;
        };

    return toInt(this->value) - toInt(other->value);
}
