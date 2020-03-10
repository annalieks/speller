#ifndef SPELLER_CHECKER_H
#define SPELLER_CHECKER_H

#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include "file.h"
#include "timer.h"

class Checker {
 protected:
  std::string structureName;
  std::ofstream incorrectWordsFile;
  std::unique_ptr<Timer> timer;
  uint64_t addingTime = 0;
  uint64_t checkingTime = 0;
  uint64_t checkedWords = 0;
  uint64_t incorrectWords = 0;

 public:
  Checker();
  virtual ~Checker();

  virtual void add(const File& file) = 0;
  virtual void check(const File& file) = 0;
  virtual void writeIncorrectWords(const std::string& word, const std::string& fileName);
  virtual void printCheckInfo();
};

#endif  // SPELLER_CHECKER_H
