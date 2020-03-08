#ifndef SPELLER_HASH_MAP_CHECKER_H
#define SPELLER_HASH_MAP_CHECKER_H

#include "Checker.h"
#include <unordered_set>

class hash_map_checker : public Checker
{
private:
    std::unordered_set<std::string> dictionaryWords;

public:
    hash_map_checker();
    ~hash_map_checker() final = default;
    void addWords(const File& file) final;
    void checkWords(const File& file) final;
};

#endif //SPELLER_HASH_MAP_CHECKER_H
