#include "SM2Deck.h"
#include <iostream>
#include <filesystem>

int main() {
  std::filesystem::path data = "data/CapitalCities.txt";
  SM2Deck test(data);

  return 0;
}
