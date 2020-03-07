#include "../includes/VectorChecker.h"
#include <algorithm>

// adds words into vector
void VectorChecker::addWords(const File& file)
{
     dictionaryWords = file.getWords();
}

// checks words from file
void VectorChecker::checkWords(const File& file)
{
    //Binary Search
    for(const auto& word : file.getWords())
    {
        if(!std::binary_search(dictionaryWords.begin(), dictionaryWords.end(), word))
           incorrectWords++;
    }
}

VectorChecker::VectorChecker()
{
    structureName = "std::vector";
}
