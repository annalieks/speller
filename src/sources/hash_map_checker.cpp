#include "hash_map_checker.h"

// adds words into unordered set
void hashMapChecker::addWords(const File& file)
{
    for(const auto& word : file.getWords())
        dictionaryWords.insert(word);
}

// checks words from file
void hashMapChecker::checkWords(const File& file)
{
    for(const auto& word : file.getWords())
    {
        if(dictionaryWords.find(word) == dictionaryWords.end())
            incorrectWords++;
    }
}

hashMapChecker::hashMapChecker()
{
    structureName = "Hash Map";
}