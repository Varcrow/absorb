#include "SM2Card.h"
#include <cmath>

SM2Card::SM2Card(std::string question, std::string answer)
    : m_question(question), m_answer(answer), m_repetitions(0), m_interval(0),
      m_easeFactor(2.5f), m_dueDate(Clock::now()) {}

SM2Card::SM2Card(std::string question, std::string answer, int repetitions,
                 int interval, float easeFactor, TimePoint dueDate)
    : m_question(question), m_answer(answer), m_repetitions(repetitions),
      m_interval(interval), m_easeFactor(easeFactor), m_dueDate(dueDate) {}

void SM2Card::recalculate(int quality) {
  if (quality >= 3) {
    if (m_repetitions == 0) {
      m_interval = 1;
    } else if (m_repetitions == 1) {
      m_interval = 6;
    } else {
      m_interval = static_cast<int>(round(m_interval * m_easeFactor));
      ++m_repetitions;
    }
  } else {
    m_repetitions = 0;
    m_interval = 1;
  }

  m_easeFactor += 0.1f - (5 - quality) * (0.08f + (5 - quality) * 0.02f);
  m_easeFactor = std::max(1.3f, m_easeFactor);
  m_dueDate = Clock::now() + std::chrono::hours(24 * m_interval);
}
