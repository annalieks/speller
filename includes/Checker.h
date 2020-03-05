#ifndef SPELLER_CHECKER_H
#define SPELLER_CHECKER_H

// interface class
class Checker
{
public:
    virtual void add(const std::vector<std::string>& values) = 0;
    virtual void check(std::vector<std::string>& values, const std::string& filePath) = 0;
    virtual void printCheckInfo() = 0;
};

#endif //SPELLER_CHECKER_H
