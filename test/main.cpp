#include <exception>
#include <iostream>

void functionWithException(bool b) {
  if (b) {
    std::cout << "No exceptions thrown here" << std::endl;
  } else {
    throw std::runtime_error("This is a runtime error!");
  }
}

void foo(int a) {
  if (a > 0) {
    std::cout << "Num is positive!" << std::endl;
  } else {
    throw std::runtime_error("Num is below 0, Not allowed!");
    a = 0;
  }
}

int main() {
  try {
    functionWithException(true);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    functionWithException(false);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    foo(15);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    foo(-1);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
