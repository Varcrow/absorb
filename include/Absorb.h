#pragma once

#include "SM2Deck.h"
#include <map>

class Absorb {
public:
  Absorb();
  ~Absorb();

  void listDecks();

private:
  std::map<std::string, SM2Deck> m_decks;
};
