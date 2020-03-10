#include "checker.h"
#include <iostream>

// prints info about passed time and processed words
void Checker::printCheckInfo() {
  std::cout << structureName << " ";
  std::cout << addingTime << " ";
  std::cout << checkingTime << " ";
  std::cout << checkedWords << " ";
  std::cout << incorrectWords << "\n";
}

Checker::Checker() {
  timer = std::make_unique<Timer>();
}

// writes incorrect words to the file
void Checker::writeIncorrectWords(const std::string& word, const std::string& fileName) {
    // open file if it is not open
    if (!incorrectWordsFile.is_open()) {
        try {
            incorrectWordsFile.open("../incorrect/" + fileName,
                                    std::ios::trunc | std::ios::out | std::ios::ate);
        } catch (const std::ifstream::failure &e) {
            std::cout << "Could not open the file" << std::endl;
        }
    }
    // write word into file if it is open
    if(incorrectWordsFile.is_open()) {
        incorrectWordsFile << word << std::endl;
    }
}

Checker::~Checker() {
    if(incorrectWordsFile.is_open()) {
        incorrectWordsFile.close();
    }
}