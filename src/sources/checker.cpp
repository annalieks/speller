#include "Checker.h"
#include "timer.h"
#include <iostream>

// prints info about passed time and processed words
void Checker::printCheckInfo()
{
    std::cout << structureName << " ";
    std::cout << addTime << " ";
    std::cout << checkTime << " ";
    std::cout << checkedWords << " ";
    std::cout << incorrectWords << "\n";
}

// checks words from file
void Checker::check(const File& file)
{
    timer timer;
    timer.startTimer();

    checkWords(file);

    checkedWords += file.getWords().size();

    checkTime += timer.getPassedTime();
}

// adds words to data structure
void Checker::add(const File& file)
{
    timer timer;
    timer.startTimer();

    addWords(file);

    addTime += timer.getPassedTime();
}

