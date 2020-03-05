#ifndef SPELLER_CHECKWORDS_H
#define SPELLER_CHECKWORDS_H

#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include "Checker.h"

class CheckWords : public Checker
{
protected:
    unsigned long addTime = 0;
    unsigned long checkTime = 0;
    unsigned long checkedWords = 0;
    unsigned long incorrectWords = 0;
    std::ofstream outFile;
    std::string outFilePath;

public:
    void add(const std::vector<std::string>& values) final;
    void check(std::vector<std::string>& values, const std::string& filePath) final;

    virtual void addWords(const std::vector<std::string>& values) = 0;
    virtual void checkWords(std::vector<std::string>& values) = 0;

    static void writeIncorrectWord(const std::string& val, std::ofstream& file);

    virtual void printCheckInfo();

    unsigned long getAddTime();
    unsigned long getCheckTime();
    unsigned long getCheckedWords();
    unsigned long getIncorrectWords();
};

#endif //SPELLER_CHECKWORDS_H
