#ifndef SPELLER_VECTORCHECKER_H
#define SPELLER_VECTORCHECKER_H

#include "CheckWords.h"

class VectorChecker : public CheckWords
{
private:
    std::vector<std::string> dictionaryWords;
    static long binarySearch(const std::string& word, const std::vector<std::string>& dictWords);

public:
    void addWords(const std::vector<std::string>& values) final;
    void checkWords(std::vector<std::string>& values) final;
};

#endif //SPELLER_VECTORCHECKER_H
