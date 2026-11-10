#pragma once

#include <filesystem>
#include <vector>
#include "SM2Card.h"

/*
 Author: Ethan Minns

 Description: A class that handles loading a single file of SM2 flashcard data into memory.
 Class also handles shuffling and retrieving next card in queue when studying.
  */

class SM2Deck {
public:
  SM2Deck();
  SM2Deck(std::filesystem::path& /*file*/);

  void load();
  void save();
  void debug();

private:
  std::string m_deckName;
  std::filesystem::path m_file;
  std::vector<SM2Card> m_allCards;
  std::vector<SM2Card> m_dueCards;
};
