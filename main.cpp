/*
  Created by SM Mashuque on 9/1/18
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

