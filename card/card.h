#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    Card(const std::string& value, const std::string& suit);
    std::string display() const;

    void print() const;
    int compareValue(Card* other) const;

private:
    std::string value;
    std::string suit;
};

#endif
