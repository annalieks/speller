#ifndef SPELLER_VECTOR_CHECKER_H
#define SPELLER_VECTOR_CHECKER_H

#include "Checker.h"

class vector_checker : public Checker
{
private:
    std::vector<std::string> dictionaryWords;

public:
    vector_checker();
    ~vector_checker() final = default;

    void addWords(const File& file) final;
    void checkWords(const File& file) final;
};

#endif //SPELLER_VECTOR_CHECKER_H
