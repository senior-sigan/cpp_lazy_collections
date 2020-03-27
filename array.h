#include <functional>

#include "array_iter.hpp"

template<typename T>
class Array {
 private:
  const T *const array_;
  const int len_;

  Array(T *data, int len) : array_(data), len_(len) {}

 public:
  template<typename TInitializer>
  static Array<T> make(int n, TInitializer init) {
    auto data = new T[n];

    for (int i = 0; i < n; i++) {
      data[i] = init(i);
    }

    return Array(data, n);
  }

  static Array<T> of(std::initializer_list<T> elements) {
    auto data = new T[elements.size()];
    int i = 0;
    for (auto el : elements) {
      data[i] = el;
      i++;
    }

    return Array(data, i);
  }

  int len() const {
    return len_;
  }

  auto iter() {
    return ArrayIter(this);
  }

  auto get(int i) const {
    return array_[i];
  }

  ~Array() {
    delete[] array_;
  }
};