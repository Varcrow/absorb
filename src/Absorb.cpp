#include "Absorb.h"
#include "SM2Deck.h"

Absorb::Absorb() {
  for (const auto &entry : std::filesystem::directory_iterator{"data"}) {
    if (!entry.is_regular_file())
      continue;

    SM2Deck deck(entry.path());
    m_decks.insert({deck.getName(), std::move(deck)});
  }
}

Absorb::~Absorb() {
  for (auto &deck : m_decks) {
    deck.second.save();
  }
}

void Absorb::listDecks() {
  for (auto &deck : m_decks) {
    deck.second.print();
  }
}

void Absorb::printDeck(std::string name) {
  auto it = m_decks.find(name);
  if(it != m_decks.end()) {
    it->second.listCards();
  }
}
