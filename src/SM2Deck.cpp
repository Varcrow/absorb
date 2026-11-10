#include "SM2Deck.h"
#include <fstream>
#include <sstream>

SM2Deck::SM2Deck() {}

SM2Deck::SM2Deck(std::filesystem::path& file) : m_file(file) {
  load();
}

void SM2Deck::load() {
  std::string input;
  std::string question;
  std::string answer;
  float easeFactor;
  int repetitions;
  int interval;

  std::ifstream in(m_file);
  if (!in.is_open())
    return; // Handle this better later

  std::getline(in, input);
  m_deckName = input;

  while (!in.eof()) {
  }

}

void SM2Deck::save() {

}
