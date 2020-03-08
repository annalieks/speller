#include "hash_table_checker.h"

// hash function, returnes hash of the given string
unsigned long hashTableChecker::hash(const std::string& word)
{
    unsigned long hash = 0;
    int seed = 1;

    for (auto ch : word)
    {
        seed *= kHashSeed;
        hash += long(ch-'a')*seed;
    }

    return (hash % kArraySize);
}

// adds words into hash table
void hashTableChecker::addWords(const File& file)
{
    for(const auto& word : file.getWords())
    {
        unsigned long index = hash(word);

        if (dictionaryWords[index].empty())
        {
            dictionaryWords[index].insert(dictionaryWords[index].begin(), word);
        }
        else {
            auto p = dictionaryWords[index].begin();

            while (p != dictionaryWords[index].end() && word > *p)
                ++p;

            dictionaryWords[index].insert(p, word);
        }
    }
}

// checks words from file
void hashTableChecker::checkWords(const File& file)
{
    for(const auto& word : file.getWords())
    {
        unsigned long index = hash(word);

        if(dictionaryWords[index].empty())
        {
            incorrectWords++;
        }
        else {
            auto p = dictionaryWords[index].begin();

            while (p != dictionaryWords[index].end() && *p != word)
                p++;

            if (p == dictionaryWords[index].end())
                incorrectWords++;
        }
    }
}

hashTableChecker::hashTableChecker()
{
    structureName = "Hash table";
}