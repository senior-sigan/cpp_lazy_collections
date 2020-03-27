#include "no_next_error.hpp"

namespace coll {
template<typename Iterator, typename TMapper>
class MapIter;
template<typename Iterator, typename TPredicate>
class FilterIter;

template<typename Iterator, typename TMapper>
class MapIter {
  Iterator prev_;
  TMapper mapper_;

 public:
  MapIter(Iterator prev, TMapper mapper) : prev_(prev), mapper_(mapper) {}

  auto next() {
    return mapper_(prev_->next());
  }

#include "coll_mixin.hpp"
};

template<typename Iterator, typename TPredicate>
class FilterIter {
  Iterator prev_;
  TPredicate predicate_;

 public:
  FilterIter(Iterator prev, TPredicate predicate): prev_(prev), predicate_(predicate) {}

  auto next() {
    while (true) {
      auto item = prev_->next();
      if (predicate_(item)) {
        return item;
      }
    }
  }

#include "coll_mixin.hpp"
};
}
