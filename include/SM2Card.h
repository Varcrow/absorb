#pragma once
#include <chrono>
#include <string>

/*
  Author: Ethan Minns

  Description: Class provided for holding and modifying loaded flashcard data that uses
  the SM2 algorithm
*/

class SM2Card {
public:
  using Clock = std::chrono::system_clock;
  using TimePoint = Clock::time_point;

  SM2Card(std::string /*question*/, std::string /*answer*/);
  SM2Card(std::string /*question*/, std::string /*answer*/, int /*repetitions*/,
          int /*interval*/, float /*easeFactor*/, TimePoint /*dueDate*/);

  void recalculate(int /*quality*/);
  bool isDue(TimePoint now = Clock::now()) const { return m_dueDate <= now; }

  std::string getQuestion() const { return m_question; }
  std::string getAnswer() const { return m_answer; }
  int getRepetitions() const { return m_repetitions; }
  int getInterval() const { return m_interval; }
  float getEaseFactor() const { return m_easeFactor; }
  TimePoint getDueDate() const { return m_dueDate; }

private:
  std::string m_question;
  std::string m_answer;
  int m_repetitions;
  int m_interval;
  float m_easeFactor;
  TimePoint m_dueDate;
};
