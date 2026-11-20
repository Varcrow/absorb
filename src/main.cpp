#include "Absorb.h"
#include <print>

void addCard(int &argc, char **&argv, Absorb &absorb);
void removeCard(int &argc, char **&argv, Absorb &absorb);
void view(int &argc, char **&argv, Absorb &absorb);
void study(int &argc, char **&argv, Absorb &absorb);

int main(int argc, char **argv) {
  // Different Commands
  //
  // Help: absorb | absorb help
  // Display list off commands, their descriptiosn and examples
  //
  // Add deck: absorb add {deck}
  // Prompt user if they would like to create deck
  //
  // Add card: absorb add {deck} {question} {answer}
  // If deck doesnt exist ask if user wants to create it and append card.
  // Otherwise just append card to deck.
  //
  // Remove card: absorb remove {deck} {id}
  // Display cards answer and question then prompt confirmation
  //
  // View cards: absorb view {deck}
  // Displays all cards in their deck in a fashion like "{id}. {question} |
  // {answer}"
  //
  // Study: absorb study {deck}
  // Begin the study loop

  if (argc < 2) {
    std::println("Help message here");
    return 1;
  }

  Absorb absorb;
  std::string cmd{std::string(argv[1])};

  if (cmd == "add") {
    addCard(argc, argv, absorb);
  } else if (cmd == "remove") {
    removeCard(argc, argv, absorb);
  } else if (cmd == "view") {
    view(argc, argv, absorb);
  } else if (cmd == "study") {
    study(argc, argv, absorb);
  }

  return 0;
}

void addCard(int &argc, char **&argv, Absorb &absorb) {}

void removeCard(int &argc, char **&argv, Absorb &absorb) {}

void view(int &argc, char **&argv, Absorb &absorb) {
  if (argc < 3) {
    absorb.listDecks();
    return;
  }
  absorb.printDeck(argv[2]);
}

void study(int &argc, char **&argv, Absorb &absorb) {}
