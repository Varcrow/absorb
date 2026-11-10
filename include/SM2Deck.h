#pragma once

#include "SM2Card.h"
#include <filesystem>
#include <vector>

/*
 Author: Ethan Minns

 Description:
 A class that handles loading a single file of SM2 flashcard data into memory.
 Class also handles shuffling and retrieving next card in queue when studying.
*/

class SM2Deck {
public:
  SM2Deck(const std::filesystem::path & /*file*/);

  void load();
  void save();
  void debug();

  std::string getName() const { return m_name; }

private:
  std::string m_name;
  std::filesystem::path m_file;
  std::vector<SM2Card> m_cards;
};
