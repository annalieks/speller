#include <string>
#include "bin_tree_checker.h"
#include "vector_checker.h"
#include "hash_map_checker.h"
#include "hash_table_checker.h"
#include "Checker.h"

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
    std::unique_ptr<Checker> binaryTree (new BinTreeChecker());
    std::unique_ptr<Checker> vector (new VectorChecker());
    std::unique_ptr<Checker> hashMap (new hashMapChecker());
    std::unique_ptr<Checker> hashTable (new hashTableChecker());

    // process dictionary
    File dictionary(dictPath);

    //add dictionary
    binaryTree->add(dictionary);
    vector->add(dictionary);
    hashMap->add(dictionary);
    hashTable->add(dictionary);

    for(const auto& filePath : textsPaths)
    {
        File text(filePath);
        binaryTree->check(text);
        vector->check(text);
        hashMap->check(text);
        hashTable->check(text);
    }

    binaryTree->printCheckInfo();
    vector->printCheckInfo();
    hashMap->printCheckInfo();
    hashTable->printCheckInfo();

    return 0;
}