#include "checker.h"
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

Checker::Checker()
{
    timer = std::make_unique<Timer>();
}

