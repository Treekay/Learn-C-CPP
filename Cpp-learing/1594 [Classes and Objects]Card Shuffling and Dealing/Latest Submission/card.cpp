 #include "card.hpp"
#include <iostream>
#include <string>
using namespace std;

const char *Card::faceNames[13] = {"Ace", "Deuce", "Three", "Four",
 "Five", "Six", "Seven","Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const char *Card::suitNames[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

Card::Card(int cardFace, int cardSuit){
  face = cardFace;
  suit = cardSuit;
}

std::string Card::toString() const{
  std::string poi;
  poi += Card::faceNames[face];
  poi += " of ";
  poi += Card::suitNames[suit];
  return poi;
}

int Card::getFace() const{
  return face;
}
int Card::getSuit() const{
  return suit;
}