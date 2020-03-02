#ifndef SPELLER_HASHMAPCHECKER_H
#define SPELLER_HASHMAPCHECKER_H

#include "Checker.h"
#include <unordered_set>

class HashMapChecker : public Checker
{
private:
    std::unordered_set<std::string> dictionaryWords;

public:
    void addWords(const std::vector<std::string>& values) final;
    void checkWords(std::vector<std::string>& values) final;
};

#endif //SPELLER_HASHMAPCHECKER_H
