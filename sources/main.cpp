#include <string>
#include "../includes/BinTreeChecker.h"
#include "../includes/VectorChecker.h"
#include "../includes/HashMapChecker.h"
#include "../includes/HashTableChecker.h"
#include "../includes/Checker.h"

int main()
{
    std::string dictPath = "../dictionary.txt";
    std::vector<std::string> textsPaths = {
            "../texts/alice.txt",
            "../texts/dracula.txt",
            "../texts/holmes.txt",
            "../texts/sherlock.txt",
            "../texts/tolstoy.txt"
    };

    // create data structures
    std::unique_ptr<Checker> pBinaryTree (new BinTreeChecker());
    std::unique_ptr<Checker> pVector (new VectorChecker());
    std::unique_ptr<Checker> pHashMap (new HashMapChecker());
    std::unique_ptr<Checker> pHashTable (new HashTableChecker());

    // process dictionary
    File dictionary(dictPath);

    //add dictionary
    pBinaryTree->add(dictionary);
    pVector->add(dictionary);
    pHashMap->add(dictionary);
    pHashTable->add(dictionary);

    for(const auto& filePath : textsPaths)
    {
        File text(filePath);
        pBinaryTree->check(text);
        pVector->check(text);
        pHashMap->check(text);
        pHashTable->check(text);
    }

    pBinaryTree->printCheckInfo();
    pVector->printCheckInfo();
    pHashMap->printCheckInfo();
    pHashTable->printCheckInfo();

    return 0;
}