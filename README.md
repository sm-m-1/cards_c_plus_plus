# cards_c_plus_plus

In this project, I create a program in C++ to create
  a deck of cards, shuffle it, and deal hands in the game of poker.
  Then evaluate the value of the poker hand.

  There are three classes that make this program function. They are:
  1. Class Card
  
     - This class represents a single card.
     It has two int data members face and suit.
     It has two static arrays of strings representing the faces and suits.
     I also had to overload the << operator to allow streaming of card
     in the form of "face of suit".
     
  2. Class DeckOfCards
  
     - This class is a deck and holds 52 cards.
     It implements a shuffle function to suffle the deck using
     std::random_device, std::mt19937, std::uniform_int_distribution.
     It implements a dealCard function that returns the top most
     card in the deck.
     
  3. Class Hand
  
     - This class represents a hand of five cards.
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
  
 | Hand   |      Count      |  Probability |
 |:----------|:-------------|:------|
 | A Pair |  41780 | 41.78%|
 | Two Pairs | 4668 | 4.668%     |
 | Three of a kind |    2154   |   2.154% |
 | Straight |    383   |   0.383%  |
 | Flush |    232   |   0.232%    |
 | Four of a Kind |    24   |   0.024%     |
 | Straight Flush |    3   |   0.003%      |

  These values match closely to those shown at:
  https://en.wikipedia.org/wiki/Poker_probability
