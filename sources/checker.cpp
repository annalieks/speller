#include "../includes/Checker.h"
#include <iostream>

// writes incorrect word to the file
void Checker::writeIncorrectWord(const std::string& val, std::ofstream& file)
{
    file << val << std::endl;
}

unsigned long Checker::getAddTime()
{
    return addTime;
}

unsigned long Checker::getCheckTime()
{
    return checkTime;
}

unsigned long Checker::getCheckedWords()
{
    return checkedWords;
}

unsigned long Checker::getIncorrectWords()
{
    return incorrectWords;
}

// prints info about passed time and processed words
void Checker::printCheckInfo()
{
    std::cout << getCheckTime() << " ";
    std::cout << getCheckedWords() << " ";
    std::cout << getIncorrectWords() << " ";
}

// checks words from file
void Checker::check(std::vector<std::string> &values, const std::string &filePath)
{
    outFilePath = filePath;
    outFile.open(filePath);

    if(!outFile)
    {
        std::cerr << "Unable to open file";
        exit(1);
    }
    // start timer
    auto start = std::chrono::system_clock::now();

    checkWords(values);

    checkedWords += values.size();

    // end timer
    auto end = std::chrono::system_clock::now();
    checkTime += std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    outFile.close();
}

// adds words to data structure
void Checker::add(const std::vector<std::string> &values)
{
    // start timer
    auto start = std::chrono::system_clock::now();

    addWords(values);

    // end timer
    auto end = std::chrono::system_clock::now();
    addTime += std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

