#ifndef SPELLER_HASH_MAP_CHECKER_H
#define SPELLER_HASH_MAP_CHECKER_H

#include <unordered_set>
#include "checker.h"

class hashMapChecker : public Checker {
 private:
  std::unordered_set<std::string> dictionaryWords;

 public:
  hashMapChecker();
  ~hashMapChecker() final = default;

  void add(const File& file) final;
  void check(const File& file) final;
};

#endif  // SPELLER_HASH_MAP_CHECKER_H
