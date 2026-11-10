#include "SM2.h"
#include <iostream>

SM2::SM2() {
  for (const auto& entry : std::filesystem::directory_iterator{"data"}) {
    if (!entry.is_regular_file())
      continue;

    SM2Deck deck(entry.path());
    m_decks.emplace(deck.getName(), std::move(deck));
  }
}

void SM2::listDecks() {
  for (auto& key : m_decks) {
    std::cout << key.first << std::endl;
  }
}
