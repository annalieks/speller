#ifndef SPELLER_BINTREECHECKER_H
#define SPELLER_BINTREECHECKER_H

#include "Checker.h"
#include <memory>

struct Node
{
    std::shared_ptr<Node> right;
    std::shared_ptr<Node> left;
    std::string data;
};

class BinTreeChecker : public Checker
{
private:
    std::shared_ptr<Node> root;
    static void addValueToTree(const std::string& val, std::shared_ptr<Node>& head);

    void checkInTree(const std::string& val, std::shared_ptr<Node>& head);
    void addValueByIndex(long left, long right, const std::vector<std::string>& values);

public:
    BinTreeChecker();
    ~BinTreeChecker() = default;

    void addWords(const File& file) final;
    void checkWords(const File& file) final;
};

#endif //SPELLER_BINTREECHECKER_H
