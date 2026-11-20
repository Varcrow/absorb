#pragma once

#include "SM2Deck.h"
#include <map>

class Absorb {
public:
  Absorb();
  ~Absorb();

  SM2Deck *getDeck(std::string /*name*/);

  void listDecks();

private:
  std::map<std::string, SM2Deck> m_decks;
};
