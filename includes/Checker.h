#ifndef SPELLER_CHECKER_H
#define SPELLER_CHECKER_H

#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include "../includes/File.h"

class Checker
{
protected:
    std::string structureName;
    unsigned long addTime = 0;
    unsigned long checkTime = 0;
    unsigned long checkedWords = 0;
    unsigned long incorrectWords = 0;

    virtual void addWords(const File& file) = 0;
    virtual void checkWords(const File& file) = 0;

public:
    void add(const File& file);
    void check(const File& file);
    void printCheckInfo();
};

#endif //SPELLER_CHECKER_H
