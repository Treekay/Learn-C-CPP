 #include "deck-of-cards.hpp"
#include <vector>
#include "card.hpp"
#include <iostream>
using namespace std;

DeckOfCards::DeckOfCards(){
  currentCard = 0;
  int index, poi;
  for (poi = 0; poi < 4; poi++) {
  	for (index = 0; index < 13; index++){
  		deck.push_back(Card(index, poi));
  	}
  }
}

Card DeckOfCards::dealCard(){
  if (moreCards()) return deck[currentCard++];
  else return deck[currentCard];
}

bool DeckOfCards::moreCards() const{
  if (currentCard < 52) return true;
  else return false;
} 