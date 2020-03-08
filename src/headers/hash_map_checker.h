#ifndef SPELLER_HASH_MAP_CHECKER_H
#define SPELLER_HASH_MAP_CHECKER_H

#include "Checker.h"
#include <unordered_set>

class hashMapChecker : public Checker
{
private:
    std::unordered_set<std::string> dictionaryWords;

public:
    hashMapChecker();
    ~hashMapChecker() final = default;
    void addWords(const File& file) final;
    void checkWords(const File& file) final;
};

#endif //SPELLER_HASH_MAP_CHECKER_H
