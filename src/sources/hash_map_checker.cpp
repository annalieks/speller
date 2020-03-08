#include "hash_map_checker.h"

// adds words into unordered set
void hash_map_checker::addWords(const File& file)
{
    for(const auto& word : file.getWords())
        dictionaryWords.insert(word);
}

// checks words from file
void hash_map_checker::checkWords(const File& file)
{
    for(const auto& word : file.getWords())
    {
        if(dictionaryWords.find(word) == dictionaryWords.end())
            incorrectWords++;
    }
}

hash_map_checker::hash_map_checker()
{
    structureName = "Hash Map";
}