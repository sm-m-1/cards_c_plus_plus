/*
  Created by SM Mashuque on 9/1/18

  In this project, I create a program in C++ to create
  a deck of cards, shuffle it, and deal hands in the game of poker.
  Then evaluate the value of the poker hand. We have skipped full house
  and royal flush hand for this assignment.

  There are three classes that make this program function. They are:
  1. Class Card
  2. Class DeckOfCards
  3. Class Hand

  1. Class Card: this class represents a single card.
  It has two int data members face and suit.
  It has two static arrays of strings representing the faces and suits.
  We also had to overload the << operator to allow streaming of card
  in the form of "face of suit".

  2. Class DeckOfCards: this class is a deck and holds 52 cards.
  It implements a shuffle function to suffle the deck using
  std::random_device, std::mt19937, std::uniform_int_distribution.
  It implements a dealCard function that returns the top most
  card in the deck.
  This class also implements a function called moreCards that
  keeps track of how many cards are left in the deck and will
  throw exception if the user is trying to deal a card from a
  deck where there are no cards left.

  3. Class Hand: this class represents a hand of five cards.
  This is the class that does the evaluation and calculations
  to figure out the best value of the five card hand: they are -
  A pair, Two pair, Three of a Kind, Straight, Flush, Four of a
  Kind, Straight Flush.

  I have written some ad-hoc tests for this program. The ad-hoc
  test functions live in the file "hand.cpp"

  I have also written a evaluation program to test the poker
  program. It basically deals 100k hands and counts the number
  of times a hand was seen. Just run the main program to see the output.
  I have also copy pasted the results below.

  My program benchmark closely follow the probabilities shown
  at Wikipedia.

  After dealing 100k hands.

  Hand value: A Pair, count: 41780             - 41.78%
  Hand value: Flush!, count: 232               - 0.232%
  Hand value: Four of a Kind!, count: 24       - 0.024%
  Hand value: Only a high card, count: 50756   - 50.756%
  Hand value: Straight Flush!, count: 3        - 0.003%
  Hand value: Straight!, count: 383            - 0.383%
  Hand value: Three of a Kind!, count: 2154    - 2.154%
  Hand value: Two Pairs, count: 4668           - 4.668%

  These values match closely to those shown at:
  https://en.wikipedia.org/wiki/Poker_probability
 */



#include <iostream>
#include <map>
#include "Card.h"
#include "DeckOfCards.h"
#include "Hand.h"

using std::cout;
using std::cin;
using std::endl;
using std::get;
using std::getline;

void create_deck_and_deal_ten_random_hands() {
  DeckOfCards deck;
  deck.shuffle();
  for (int i = 0; i < 10; i ++) {
    Hand hand(deck);
    std::string handName = hand.evalHand();
    cout << "The current hand is: \n";
    string cards_in_hand = "";
    for (auto card: hand.hand) {
      cards_in_hand = cards_in_hand + card.faces[card.face] + " of " + card.suits[card.suit] + ", ";
    }
    cout << cards_in_hand << endl;
    cout << "Value of hand " << i + 1<<" is: " << handName << "\n\n";
  }
}

void create_deck_and_do_benchmark() {
  std::map<string, int> handValueCount;
  for (int i = 0; i< 100000; i++) {
      DeckOfCards deck;
      deck.shuffle();
      Hand hand(deck);
      std::string handName = hand.evalHand();
      handValueCount[handName] ++;
  }
  cout << "Finished dealing 100k hands.\n\n";
  cout << "Showing results below.\n";
  for (const auto &pair: handValueCount) {
    cout << "Hand value: " << pair.first << ", count: " << pair.second << " - " << (pair.second/1000.0) << "%" << endl;
  }
}

int main() {

  cout << "BEGIN RANDOM TESTING OF A HAND FROM A DECK\n\n";
  create_deck_and_deal_ten_random_hands();

  cout << "BEGIN SOME AD-HOC TESTING FOR SANITY CHECK\n\n";
  test_two_pairs();
  test_triple();
  test_straight();
  test_flush();
  test_quad();
  test_staight_flush();

  cout << "BEGIN BENCHMARKING DEALING 100k HANDS.\n\n";
  create_deck_and_do_benchmark();
  return 0;
}

