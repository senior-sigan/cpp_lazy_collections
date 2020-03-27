// NO HEADER GUARD!!

// THIS IS MIXIN!!


template<typename TMapper_>
auto map(TMapper_ mapper) {
  return coll::MapIter<decltype(this), decltype(mapper)>(this, mapper);
}

template<typename TFilter>
auto filter(TFilter predicate) {
  return coll::FilterIter<decltype(this), decltype(predicate)>(this, predicate);
}

template<typename TUnoFunction>
void foreach (TUnoFunction action) {
  while (true) {
    try {
      action(this->next());
    } catch (const NoNextError& er) {
      return; // it's ok.
    }
  }
}