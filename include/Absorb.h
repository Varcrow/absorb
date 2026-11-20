#pragma once

#include "SM2Deck.h"
#include <map>

class Absorb {
public:
  Absorb();
  ~Absorb();

  void listDecks();
  SM2Deck* getDeck(std::string /*name*/);

private:
  std::map<std::string, SM2Deck> m_decks;
};
