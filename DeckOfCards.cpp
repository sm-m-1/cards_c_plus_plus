//
// Created by SM Mashuque on 10/14/18.
//
#include <random>

#include "DeckOfCards.h"
#include <time.h>


DeckOfCards::DeckOfCards() {
  size_t faces_count = 13;
  size_t suits_count = 4;
  for (int i = 0; i < suits_count; i++) {
    for (int j = 0; j < faces_count; j++) {
      Card c(j, i);
      this->deck.push_back(c);
    }
  }
  this->currentCard = 0;
}

Card DeckOfCards::dealCard() {
  // return the card in current card position and increment currentcard.
  if ( !this->moreCards() ) {
    throw std::runtime_error("There are no more cards left to deal in the Deck");
  }
  return this->deck[this->currentCard++];
}

bool DeckOfCards::moreCards() {
  return this->currentCard < this->deck.size();
}

void DeckOfCards::shuffle() {
  // best method for generating random numbers?
  std::random_device random_device;
  std::mt19937 random_generator(random_device());
  std::uniform_int_distribution<int> distribution2(0,51);

  for (int i = 0; i < this->deck.size(); i++) {
    int rand_i = distribution2(random_generator);
    Card temp = this->deck[i];
    this->deck[i] = this->deck[rand_i];
    this->deck[rand_i] = temp;
  }
  this->currentCard = 0;
}


