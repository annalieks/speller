#include "../includes/File.h"
#include <iostream>
#include <regex>

// constructor
File::File(const std::string& filePath)
{
    file.open(filePath);
    if(!file)
    {
        std::cerr << "Unable to open file ";
        exit(1);
    }
    process();
}

// destructor
File::~File()
{
    file.close();
}

// pushes words transformed into lower case
// and processed by regular expression into vector of words
void File::process()
{
    std::string word;
    std::regex target("([a-z]*|[a-z][a-z']*[a-z])");
    std::regex removed("[^a-z' ]*");
    std::smatch match;

    while(file >> word)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word = std::regex_replace(word,removed, "");
        std::regex_search(word, match, target);
        word = match.str(0);

        if (!word.empty())
            words.push_back(word);
    }
}

std::vector<std::string> File::getWords() const
{
    return words;
}
