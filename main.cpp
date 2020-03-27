#include <iostream>

#include "array.h"

using std::function;

int main() {
  Array<int>::make(10, [](int i) { return i; }).iter().foreach ([](int x) { std::cout << x << std::endl; });

  std::cout << "====" << std::endl;
  Array<int>::make(10, [](int i) { return i; })
      .iter()
      .map([](int x) { return x * 2; })
      .map([](int x) { return (float) x * 3.1f; })
      .foreach ([](float x) { std::cout << x << std::endl; });

  std::cout << "====" << std::endl;
  Array<float>::of({1.0, 2.0, 3.0, 4.0, 5.0, 6.0})
      .iter()
      .filter([](float x) { return x < 4.0; })
      .map([](float x) { return int(x + 2); })
      .filter([](int x) { return x % 2 == 1; })
      .filter([](int x) { return true; })
      .foreach ([](int x) { std::cout << x << std::endl; });

  std::cout << "====" << std::endl;
  Array<int>::of({1, 2, 3, 4, 5, 6, 8, 9}).iter().filter([](int x) { return x % 2 == 0; }).foreach ([](float x) {
    std::cout << x << std::endl;
  });

  std::cout << "====" << std::endl;
}