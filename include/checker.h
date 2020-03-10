#ifndef SPELLER_CHECKER_H
#define SPELLER_CHECKER_H

#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <memory>
#include "timer.h"
#include "file.h"

class Checker
{
protected:
    std::string structureName;
    std::unique_ptr<Timer> timer;
    unsigned long addTime = 0;
    unsigned long checkTime = 0;
    unsigned long checkedWords = 0;
    unsigned long incorrectWords = 0;

public:
    Checker();
    virtual ~Checker() = default;

    virtual void add(const File& file) = 0;
    virtual void check(const File& file) = 0;
    virtual void printCheckInfo();
};

#endif //SPELLER_CHECKER_H
