//
// Created by SM Mashuque on 10/14/18.
//

#include <map>
#include "Hand.h"

using std::cout;
using std::cin;
using std::endl;
using std::get;
using std::getline;


Hand::Hand(DeckOfCards &d) {
  for (int i = 0; i < 5; i++) {
    Card card = d.dealCard();
    this->hand.push_back(card);
  }
}

bool Hand::pair() {
  for (const auto &pair: this->faceCount) {
    if ( pair.second == 2 ) { return true; }
  }
  return false;
}

bool Hand::twoPair() {
  int pairs = 0;
  for (const auto &pair: this->faceCount) {
    if ( pair.second == 2 ) { pairs ++; }
  }
  return pairs == 2;
}

bool Hand::triple() {
  for (const auto &pair: this->faceCount) {
    if ( pair.second == 3 ) { return true; }
  }
  return false;
}

bool Hand::quad() {
  for (const auto &pair: this->faceCount) {
    if ( pair.second == 4 ) { return true; }
  }
  return false;
}

bool Hand::flush() {
  return this->suitsCount.size() == 1;
}

bool Hand::straight() {
  vector<int> data;
  for (auto card: this->hand) {
    data.push_back(card.face);
  }
  std::sort(data.begin(), data.end());
  for (int i = 0; i < this->hand.size()-1; i++) {
      if ( ( data[i+1] - data[i] ) != 1 ) { return false; }
  }
  return true;
}

bool Hand::straightFlush() {
  return this->straight() && this->flush();
}

string Hand::evalHand() {
  for (auto card: this->hand) {
    this->faceCount[ card.faces[card.face] ] ++;
  }
  for (auto card: this->hand) {
    this->suitsCount[ card.suits[card.suit] ] ++;
  }
  if (this->quad()) { return std::string("Four of a Kind!"); }
  else if (this->straightFlush()) { return std::string("Straight Flush!"); }
  else if (this->flush()) { return std::string("Flush!"); }
  else if (this->straight()) { return std::string("Straight!"); }
  else if (this->triple()) { return std::string("Three of a Kind!"); }
  else if (this->twoPair()) { return std::string("Two Pairs"); }
  else if (this->pair()) { return std::string("A Pair"); }
  else { return std::string("Only a high card"); }
}


void test_straight() {
  DeckOfCards deck;
  deck.shuffle();
  Hand hand(deck);
  vector<Card> hand2 = {Card(0,1), Card(1,1), Card(2,1), Card(3,1), Card(4,3)};
  hand.hand = hand2;
  std::string handName = hand.evalHand();
  cout << "Testing a straight hand: \n";
  string cards_in_hand = "";
  for (auto card: hand.hand) {
    cards_in_hand = cards_in_hand + card.faces[card.face] + " of " + card.suits[card.suit] + ", ";
  }
  cout << cards_in_hand << endl;
  cout << "Value of hand " << " is: " << handName << "\n\n";
}

void test_flush() {
  DeckOfCards deck;
  deck.shuffle();
  Hand hand(deck);
  vector<Card> hand2 = {Card(0,0), Card(1,0), Card(2,0), Card(9,0), Card(4,0)};
  hand.hand = hand2;
  std::string handName = hand.evalHand();
  cout << "Testing a Flush hand: \n";
  string cards_in_hand = "";
  for (auto card: hand.hand) {
    cards_in_hand = cards_in_hand + card.faces[card.face] + " of " + card.suits[card.suit] + ", ";
  }
  cout << cards_in_hand << endl;
  cout << "Value of hand " << " is: " << handName << "\n\n";
}

void test_staight_flush() {
  DeckOfCards deck;
  deck.shuffle();
  Hand hand(deck);
  vector<Card> hand2 = {Card(0,0), Card(1,0), Card(2,0), Card(3,0), Card(4,0)};
  hand.hand = hand2;
  std::string handName = hand.evalHand();
  cout << "Testing a Straight Flush hand: \n";
  string cards_in_hand = "";
  for (auto card: hand.hand) {
    cards_in_hand = cards_in_hand + card.faces[card.face] + " of " + card.suits[card.suit] + ", ";
  }
  cout << cards_in_hand << endl;
  cout << "Value of hand " << " is: " << handName << "\n\n";
}

void test_quad() {
  DeckOfCards deck;
  deck.shuffle();
  Hand hand(deck);
  vector<Card> hand2 = {Card(0,1), Card(0,2), Card(0,3), Card(0,0), Card(4,3)};
  hand.hand = hand2;
  std::string handName = hand.evalHand();
  cout << "Testing a Four of a Kind hand: \n";
  string cards_in_hand = "";
  for (auto card: hand.hand) {
    cards_in_hand = cards_in_hand + card.faces[card.face] + " of " + card.suits[card.suit] + ", ";
  }
  cout << cards_in_hand << endl;
  cout << "Value of hand " << " is: " << handName << "\n\n";
}

void test_triple() {
  DeckOfCards deck;
  deck.shuffle();
  Hand hand(deck);
  vector<Card> hand2 = {Card(5,1), Card(5,2), Card(5,3), Card(3,1), Card(4,3)};
  hand.hand = hand2;
  std::string handName = hand.evalHand();
  cout << "Testing a Three of a Kind hand: \n";
  string cards_in_hand = "";
  for (auto card: hand.hand) {
    cards_in_hand = cards_in_hand + card.faces[card.face] + " of " + card.suits[card.suit] + ", ";
  }
  cout << cards_in_hand << endl;
  cout << "Value of hand " << " is: " << handName << "\n\n";
}

void test_two_pairs() {
  DeckOfCards deck;
  deck.shuffle();
  Hand hand(deck);
  vector<Card> hand2 = {Card(5,1), Card(5,2), Card(10,3), Card(10,1), Card(4,3)};
  hand.hand = hand2;
  std::string handName = hand.evalHand();
  cout << "Testing a Two Pairs: \n";
  string cards_in_hand = "";
  for (auto card: hand.hand) {
    cards_in_hand = cards_in_hand + card.faces[card.face] + " of " + card.suits[card.suit] + ", ";
  }
  cout << cards_in_hand << endl;
  cout << "Value of hand " << " is: " << handName << "\n\n";
}

