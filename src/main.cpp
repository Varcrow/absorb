#include <iostream>
#include <filesystem>
#include <fstream>

int main() {
  std::filesystem::path data = "data";

  for (const auto& entry : std::filesystem::directory_iterator{data}) {
    std::ofstream out(entry.path());

    out << "TESTING";
  }

  return 0;
}
