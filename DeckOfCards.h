//
// Created by SM Mashuque on 10/14/18.
//
#include <vector>
#include <random>
#include "Card.h"
using std::vector;

#ifndef A6_DECKOFCARDS_H
#define A6_DECKOFCARDS_H


class DeckOfCards {

public:
    // constructor
    DeckOfCards();

    // member variables.
    vector<Card> deck;
    int currentCard;
    void shuffle();
    Card dealCard();
    bool moreCards();
};


#endif //A6_DECKOFCARDS_H
