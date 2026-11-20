#include "Absorb.h"
#include "SM2Deck.h"
#include <print>

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
  // Due cards: absorb due
  // Display deck names and number of cards due. "{deckname} : {num due}"
  //
  // Study: absorb study {deck}
  // Begin the study loop

  if (argc < 2) {
    std::println("Help message here");
    return 1;
  }

  Absorb a;
  std::string cmd{std::string(argv[1])};

  if (cmd == "add") {
    std::println("Looking to add card.");
  } else if (cmd == "remove") {
    std::println("Looking to remove card.");
  } else if (cmd == "view") {
    if (argc < 3) {
      a.listDecks();
      return 0;
    }

    SM2Deck* deck{a.getDeck(argv[2])};

    if (!deck) {
      std::println("Deck {} does not exist.", argv[2]);
      return 1;
    }

    deck->listCards();

  } else if (cmd == "due") {
    a.listDueCounts();
  } else if (cmd == "study") {
    std::println("Looking to study.");
  }

  return 0;
}
