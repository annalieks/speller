#ifndef SPELLER_HASHMAPCHECKER_H
#define SPELLER_HASHMAPCHECKER_H

#include "Checker.h"
#include <unordered_set>

class HashMapChecker : public Checker
{
private:
    std::unordered_set<std::string> dictionaryWords;

public:
    HashMapChecker();
    ~HashMapChecker() = default;
    void addWords(const File& file) final;
    void checkWords(const File& file) final;
};

#endif //SPELLER_HASHMAPCHECKER_H
