#pragma once

#include "no_next_error.hpp"
#include "coll.h"

template<typename TArray>
class ArrayIter {
 private:
  TArray *array_;
  int idx_ = 0;

 public:
  explicit ArrayIter(TArray *array) : array_(array) {}

  auto next() {
    if (idx_ >= array_->len()) throw NoNextError();
    idx_++;
    return array_->get(idx_ - 1);
  }

#include "coll_mixin.hpp"
};