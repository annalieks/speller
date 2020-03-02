#ifndef SPELLER_CHECKER_H
#define SPELLER_CHECKER_H

#include <string>
#include <vector>
#include <fstream>
#include <chrono>

class Checker
{
protected:
    unsigned long addTime = 0;
    unsigned long checkTime = 0;
    unsigned long checkedWords = 0;
    unsigned long incorrectWords = 0;
    std::ofstream outFile;
    std::string outFilePath;

public:
    void add(const std::vector<std::string>& values);
    void check(std::vector<std::string>& values, const std::string& filePath);

    virtual void addWords(const std::vector<std::string>& values) = 0;
    virtual void checkWords(std::vector<std::string>& values) = 0;

    static void writeIncorrectWord(const std::string& val, std::ofstream& file);

    void printCheckInfo();

    unsigned long getAddTime();
    unsigned long getCheckTime();
    unsigned long getCheckedWords();
    unsigned long getIncorrectWords();

};

#endif //SPELLER_CHECKER_H
