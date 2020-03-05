#include "../includes/CheckWords.h"
#include <iostream>

// writes incorrect word to the file
void CheckWords::writeIncorrectWord(const std::string& val, std::ofstream& file)
{
    file << val << std::endl;
}

unsigned long CheckWords::getAddTime()
{
    return addTime;
}

unsigned long CheckWords::getCheckTime()
{
    return checkTime;
}

unsigned long CheckWords::getCheckedWords()
{
    return checkedWords;
}

unsigned long CheckWords::getIncorrectWords()
{
    return incorrectWords;
}

// prints info about passed time and processed words
void CheckWords::printCheckInfo()
{
    std::cout << getAddTime() << " ";
    std::cout << getCheckTime() << " ";
    std::cout << getCheckedWords() << " ";
    std::cout << getIncorrectWords() << " ";
}

// checks words from file
void CheckWords::check(std::vector<std::string> &values, const std::string &filePath)
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
void CheckWords::add(const std::vector<std::string> &values)
{
    // start timer
    auto start = std::chrono::system_clock::now();

    addWords(values);

    // end timer
    auto end = std::chrono::system_clock::now();
    addTime += std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

