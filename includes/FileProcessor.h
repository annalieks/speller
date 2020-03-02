#ifndef SPELLER_FILEPROCESSOR_H
#define SPELLER_FILEPROCESSOR_H

#include <vector>
#include <fstream>
#include <string>
#include "Checker.h"

class FileProcessor
{
private:
    std::vector<std::string> filePaths;
    std::ifstream file;
    std::vector<std::vector<std::string>> words;

public:
    FileProcessor(std::vector<std::string> filePaths) : filePaths(filePaths) {}

    void processDataStructure(const std::string& name, Checker* pObj);
    void openFile(const std::string& fileName);
    void closeFile();
    void processFiles();
};

#endif //SPELLER_FILEPROCESSOR_H
