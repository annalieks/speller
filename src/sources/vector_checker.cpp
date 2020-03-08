#include "vector_checker.h"
#include <algorithm>

// adds words into vector
void vector_checker::addWords(const File& file)
{
     dictionaryWords = file.getWords();
}

// checks words from file
void vector_checker::checkWords(const File& file)
{
    //Binary Search
    for(const auto& word : file.getWords())
    {
        if(!std::binary_search(dictionaryWords.begin(), dictionaryWords.end(), word))
           incorrectWords++;
    }
}

vector_checker::vector_checker()
{
    structureName = "std::vector";
}
