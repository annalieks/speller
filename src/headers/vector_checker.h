#ifndef SPELLER_VECTOR_CHECKER_H
#define SPELLER_VECTOR_CHECKER_H

#include "checker.h"

class VectorChecker : public Checker {
 private:
  std::vector<std::string> dictionaryWords;

 public:
  VectorChecker();
  ~VectorChecker() final = default;

  void add(const File& file) final;
  void check(const File& file) final;
};

#endif  // SPELLER_VECTOR_CHECKER_H
