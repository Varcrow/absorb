#include <iostream>
#include "SM2Card.h"

int main() {
  SM2Card test{"question", "answer"};

  std::cout << test.getQuestion() << std::endl;
  std::cout << test.getAnswer() << std::endl;
  std::cout << test.getEaseFactor() << std::endl;

  test.recalculate(3);

  std::cout << test.getQuestion() << std::endl;
  std::cout << test.getAnswer() << std::endl;
  std::cout << test.getEaseFactor() << std::endl;

  return 0;
}
