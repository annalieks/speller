#include "hash_map_checker.h"

// adds words into unordered set
void hashMapChecker::add(const File& file)
{
    timer->startTimer();

    for(const auto& word : file.getWords())
        dictionaryWords.insert(word);

    addTime += timer->getPassedTime();
}

// checks words from file
void hashMapChecker::check(const File& file)
{
    timer->startTimer();

    for(const auto& word : file.getWords())
    {
        if(dictionaryWords.find(word) == dictionaryWords.end())
            incorrectWords++;
    }

    checkedWords += file.getWords().size();
    checkTime += timer->getPassedTime();
}

hashMapChecker::hashMapChecker()
{
    structureName = "Hash Map";
}