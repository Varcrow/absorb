#pragma once

#include "SM2Deck.h"
#include <map>

class SM2 {
public:
  SM2();

  void listDecks();

private:
  std::map<std::string, SM2Deck> m_decks;
};
