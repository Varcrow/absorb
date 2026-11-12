#include "Absorb.h"
#include "SM2Deck.h"
#include <iostream>

Absorb::Absorb() {
  for (const auto& entry : std::filesystem::directory_iterator{"data"}) {
    if (!entry.is_regular_file())
      continue;

    SM2Deck deck(entry.path());
    m_decks.insert({deck.getName(), std::move(deck)});
  }
}

Absorb::~Absorb() {
  for (auto& deck : m_decks) {
    deck.second.save();
  }
}

void Absorb::listDecks() {
  for (auto& deck : m_decks) {
    std::cout << deck.second.getName() << std::endl;
  }
}
