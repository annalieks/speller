#include "../includes/FileProcessor.h"
#include <iostream>
#include <regex>

// opens file
void FileProcessor::openFile(const std::string& filePath)
{
    file.open(filePath);
    if(!file)
    {
        std::cerr << "FileProcessor: Unable to open file ";
        exit(1);
    }
}

// closes file
void FileProcessor::closeFile()
{
    file.close();
}

// pushes words transformed into lower case
// and processed by regular expression into vector of words
void FileProcessor::processFiles()
{
    std::string word;
    std::regex target("([a-z]*|[a-z][a-z']*[a-z])");
    std::regex removed("[^a-z' ]*");
    std::smatch match;

    for (const auto& filePath : filePaths)
    {
        std::vector<std::string> fileWords;
        openFile(filePath);

        while(file >> word)
        {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            word = std::regex_replace(word,removed, "");
            std::regex_search(word, match, target);
            word = match.str(0);

            if (!word.empty())
                fileWords.push_back(word);
        }

        words.push_back(fileWords);
        closeFile();
    }
}

// processes all information for specified data structure
void FileProcessor::processDataStructure(const std::string& name, std::unique_ptr<Checker>& pObj)
{
    std::cout << "\n" << name << ": ";

    pObj->add(words[0]);

    for(int i = 1; i < words.size(); i++)
        pObj->check(words[i], "../incorrect/" + name + "/" + std::to_string(i) + ".txt");

    pObj->printCheckInfo();
}
