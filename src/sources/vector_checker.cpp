#include <algorithm>
#include "vector_checker.h"

// adds words into vector
void VectorChecker::add(const File& file)
{
    timer->startTimer();

    dictionaryWords = file.getWords();

    addTime += timer->getPassedTime();
}

// checks words from file
void VectorChecker::check(const File& file)
{
    timer->startTimer();

    for(const auto& word : file.getWords())
    {
        if(!std::binary_search(dictionaryWords.begin(), dictionaryWords.end(), word))
           incorrectWords++;
    }

    checkedWords += file.getWords().size();
    checkTime += timer->getPassedTime();
}

VectorChecker::VectorChecker()
{
    structureName = "std::vector";
}
