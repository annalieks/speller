#include "vector_checker.h"
#include <algorithm>

// adds words into vector
void VectorChecker::add(const File& file) {
  timer->startTimer();

  dictionaryWords = file.getWords();

  addingTime += timer->getPassedTime();
}

// checks words from file
void VectorChecker::check(const File& file) {
  timer->startTimer();

  for (const auto& word : file.getWords()) {
    if (!std::binary_search(dictionaryWords.begin(), dictionaryWords.end(),
                            word)) {
        incorrectWords++;
        writeIncorrectWords(word, file.getFileName());
    }
  }
  incorrectWordsFile.close();

  checkedWords += file.getWords().size();
  checkingTime += timer->getPassedTime();
}

VectorChecker::VectorChecker() {
    structureName = "std::vector";
}
