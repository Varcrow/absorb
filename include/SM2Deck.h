#pragma once

#include <filesystem>
#include <vector>
#include "SM2Card.h"

class SM2Deck {
public:
  SM2Deck();
  SM2Deck(std::filesystem::path& /*file*/);

  void load();
  void save();

private:
  std::string m_deckName;
  std::filesystem::path m_file;
  std::vector<SM2Card> m_allCards;
  std::vector<SM2Card> m_dueCards;
};
