#ifndef SPELLER_HASH_TABLE_CHECKER_H
#define SPELLER_HASH_TABLE_CHECKER_H

#include <array>
#include <list>
#include "checker.h"

class hashTableChecker : public Checker {
 private:
  static const int kArraySize = 100000;
  static const int kHashSeed = 199;
  static uint64_t hash(const std::string& word);

  std::array<std::list<std::string>, kArraySize> dictionaryWords;

 public:
  hashTableChecker();
  ~hashTableChecker() final = default;

  void add(const File& file) final;
  void check(const File& file) final;
};

#endif  // SPELLER_HASH_TABLE_CHECKER_H
