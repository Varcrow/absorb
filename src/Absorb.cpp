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

SM2Deck *Absorb::getDeck(std::string name) {
  auto it = m_decks.find(name);
  return it != m_decks.end() ? &it->second : nullptr;
}

void Absorb::listDecks() {
  for (auto &deck : m_decks) {
    deck.second.print();
  }
}