#ifndef SPELLER_VECTORCHECKER_H
#define SPELLER_VECTORCHECKER_H

#include "Checker.h"

class VectorChecker : public Checker
{
private:
    std::vector<std::string> dictionaryWords;

public:
    VectorChecker();
    ~VectorChecker() = default;

    void addWords(const File& file) final;
    void checkWords(const File& file) final;
};

#endif //SPELLER_VECTORCHECKER_H
