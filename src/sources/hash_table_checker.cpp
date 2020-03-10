#include "hash_table_checker.h"

// hash function, returns the hash of the given string
uint64_t hashTableChecker::hash(const std::string& word) {
  uint64_t hash = 0;
  int seed = 1;

  for (auto ch : word) {
    seed *= kHashSeed;
    hash += int64_t(ch - 'a') * seed;
  }

  return (hash % kArraySize);
}

// adds words into hash table
void hashTableChecker::add(const File& file) {
  timer->startTimer();

  for (const auto& word : file.getWords()) {
    uint64_t index = hash(word);

    if (dictionaryWords.at(index).empty()) {
      dictionaryWords.at(index).insert(dictionaryWords.at(index).begin(), word);
    } else {
      auto p = dictionaryWords.at(index).begin();

      while (p != dictionaryWords.at(index).end() && word > *p) {
          ++p;
      }

      dictionaryWords.at(index).insert(p, word);
    }
  }

    addingTime += timer->getPassedTime();
}

// checks words from the file
void hashTableChecker::check(const File& file) {
  timer->startTimer();

  for (const auto& word : file.getWords()) {
    uint64_t index = hash(word);
    if (dictionaryWords.at(index).empty()) {
      incorrectWords++;
    } else {
      auto p = dictionaryWords.at(index).begin();
      while (p != dictionaryWords.at(index).end() && *p != word) {
          p++;
      }
      if (p == dictionaryWords.at(index).end()) {
          incorrectWords++;
      }
    }
  }

  checkedWords += file.getWords().size();
  checkingTime += timer->getPassedTime();
}

hashTableChecker::hashTableChecker() {
    structureName = "hash_table";
}