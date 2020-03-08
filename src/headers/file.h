#ifndef SPELLER_FILE_H
#define SPELLER_FILE_H

#include <vector>
#include <fstream>
#include <string>

class File
{
private:
    std::ifstream file;
    std::vector<std::string> words;
    void process();

public:
    explicit File(const std::string& filePath);
    ~File();
    std::vector<std::string> getWords() const;
};

#endif //SPELLER_FILE_H
