#ifndef SPELLER_HASH_TABLE_CHECKER_H
#define SPELLER_HASH_TABLE_CHECKER_H

#include "Checker.h"
#include <list>
#include <cmath>
#include <array>

class hashTableChecker : public Checker
{
private:
    static const int kArraySize = 100000;
    static const int kHashSeed = 199;
    static unsigned long hash(const std::string& word);

    std::array<std::list<std::string>, kArraySize> dictionaryWords;

public:
    hashTableChecker();
    ~hashTableChecker() final = default;
    void addWords(const File& file) final;
    void checkWords(const File& file) final;
};

#endif //SPELLER_HASH_TABLE_CHECKER_H
