//
// Created by SM Mashuque on 10/14/18.
//

#ifndef A6_CARD_H
#define A6_CARD_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Card {
public:
    // constructor
    Card(int face, int suit);
    // member variables
    int face;
    int suit;
    static string faces[13];
    static string suits[4];
    friend ostream& operator<<(ostream&, const Card&);
};
//static string suits[4] = {"hearts", "diamonds", "clubs", "spades"};

#endif //A6_CARD_H
