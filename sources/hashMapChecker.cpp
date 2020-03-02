#include "../includes/HashMapChecker.h"

// adds words into unordered set
void HashMapChecker::addWords(const std::vector<std::string> &values)
{
    for(const auto& word : values)
        dictionaryWords.insert(word);
}

// checks words from file
void HashMapChecker::checkWords(std::vector<std::string>& values)
{
    for(const auto& word : values)
    {
        if(dictionaryWords.find(word) == dictionaryWords.end())
        {
            incorrectWords++;
            writeIncorrectWord(word, outFile);
        }
    }
}