//
// Created by SM Mashuque on 10/14/18.
//
//#include <string>
//#include <iostream>
#include "Card.h"
//using std::string;
//using std::ostream;

Card::Card(int face, int suit) {
  this->face = face;
  this->suit = suit;
}

string Card::faces[13] = {"A", "2", "3", "4", "5", "6",
                          "7", "8", "9", "10", "J", "Q", "K"};
string Card::suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

ostream& operator<<(ostream &os, const Card &card) {
  return os << Card::faces[card.face] << " of " << Card::suits[card.suit] << "\n";
}
