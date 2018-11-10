//
// Created by SM Mashuque on 10/14/18.
//
#include "DeckOfCards.h"
#ifndef A6_HAND_H
#define A6_HAND_H


class Hand {
public:
    Hand(DeckOfCards &d);

    vector<Card> hand;
    std::map<string, int> faceCount;
    std::map<string, int> suitsCount;
    bool pair();
    bool twoPair();
    bool triple();
    bool quad();
    bool flush();
    bool straight();
    bool straightFlush();
    string evalHand();
};

void test_straight();
void test_flush();
void test_quad();
void test_triple();
void test_two_pairs();
void test_staight_flush();

#endif //A6_HAND_H
