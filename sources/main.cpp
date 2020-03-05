#include <string>
#include "../includes/BinTreeChecker.h"
#include "../includes/FileProcessor.h"
#include "../includes/VectorChecker.h"
#include "../includes/HashMapChecker.h"
#include "../includes/HashTableChecker.h"
#include "../includes/Checker.h"

int main()
{
    std::vector<std::string> filePaths = {
            "../dictionary.txt",
            "../texts/alice.txt",
            "../texts/dracula.txt",
            "../texts/holmes.txt",
            "../texts/sherlock.txt",
            "../texts/tolstoy.txt"
    };

    FileProcessor files(filePaths);

    // open files and process all words from files
    files.processFiles();

    // create data structures
    std::unique_ptr<Checker> pBinaryTree (new BinTreeChecker());
    std::unique_ptr<Checker> pVector (new VectorChecker());
    std::unique_ptr<Checker> pHashMap (new HashMapChecker());
    std::unique_ptr<Checker> pHashTable (new HashTableChecker());

    // Binary Tree
    files.processDataStructure("BinTree", pBinaryTree);

    // Vector
    files.processDataStructure("Vector", pVector);

    // Unordered set (Hash Map)
    files.processDataStructure("HashMap", pHashMap);

    // Hash Table
    files.processDataStructure("HashTable", pHashTable);

    return 0;
}