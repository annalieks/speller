#ifndef SPELLER_HASHTABLECHECKER_H
#define SPELLER_HASHTABLECHECKER_H

#include "Checker.h"
#include <list>
#include <cmath>

class HashTableChecker : public Checker
{
private:
    static const int SIZE = 100000;
    static unsigned long hash(const std::string& word);

    std::list<std::string> dictionaryWords[SIZE];

public:
    HashTableChecker();
    ~HashTableChecker() = default;
    void addWords(const File& file) final;
    void checkWords(const File& file) final;
};

#endif //SPELLER_HASHTABLECHECKER_H
