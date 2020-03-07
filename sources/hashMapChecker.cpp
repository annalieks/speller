#include "../includes/HashMapChecker.h"

// adds words into unordered set
void HashMapChecker::addWords(const File& file)
{
    for(const auto& word : file.getWords())
        dictionaryWords.insert(word);
}

// checks words from file
void HashMapChecker::checkWords(const File& file)
{
    for(const auto& word : file.getWords())
    {
        if(dictionaryWords.find(word) == dictionaryWords.end())
            incorrectWords++;
    }
}

HashMapChecker::HashMapChecker()
{
    structureName = "Hash Map";
}