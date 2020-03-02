#include "../includes/VectorChecker.h"

// adds words into vector
void VectorChecker::addWords(const std::vector<std::string>& values)
{
     dictionaryWords = values;
}

// checks words from file
void VectorChecker::checkWords(std::vector<std::string>& values)
{
    //Binary Search
    for(const auto& word : values)
    {
        if(binarySearch(word, dictionaryWords) < 0) {
           incorrectWords++;
           writeIncorrectWord(word, outFile);
        }
    }
}

// binary search function (works faster that std::binary_search)
long VectorChecker::binarySearch(const std::string& word, const std::vector<std::string>& dictWords)
{
    long lower = 0;
    long upper = long(dictWords.size()) - 1;
    while (lower <= upper) {
        long mid = lower + (upper - lower) / 2;
        if (word == (dictWords[mid]))
            return mid;
        if (word > (dictWords[mid]))
            lower = mid + 1;
        else
            upper = mid - 1;
    }
    return -1;
}
