#include "SM2Deck.h"
#include "SM2Card.h"
#include <fstream>
#include <iostream>

SM2Deck::SM2Deck(const std::filesystem::path &file) : m_file(file) { load(); }

void SM2Deck::load() {
  std::ifstream in(m_file);
  if (!in.is_open())
    return;

  std::getline(in, m_name);

  std::string question, answer;
  while (std::getline(in, question, '|')) {
    int repetitions, interval;
    float easeFactor;
    std::int64_t dueSecs;
    char sep;

    std::getline(in, answer, '|');
    if (!(in >> repetitions >> sep >> interval >> sep >> easeFactor >> sep >>
          dueSecs))
      break;
    in >> std::ws;

    SM2Card card(question, answer, repetitions, interval, easeFactor,
                 SM2Card::TimePoint(std::chrono::seconds(dueSecs)));

    m_cards.push_back(std::move(card));
  }
}

void SM2Deck::save() {
  std::ofstream out(m_file, std::ios::trunc);
  if (!out.is_open())
    return;

  out << m_name << '\n';
  for (const auto &card : m_cards) {
    out << card.getQuestion() << '|' << card.getAnswer() << '|'
        << card.getRepetitions() << ',' << card.getInterval() << ','
        << card.getEaseFactor() << ','
        << std::chrono::duration_cast<std::chrono::seconds>(
               card.getDueDate().time_since_epoch())
               .count()
        << '\n';
  }
}

void SM2Deck::debug() {
  for (const auto& card : m_cards) {
    std::cout << card.getQuestion() << " | " << card.getAnswer() << std::endl;
  }
}
