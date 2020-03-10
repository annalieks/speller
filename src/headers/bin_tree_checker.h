#ifndef SPELLER_BIN_TREE_CHECKER_H
#define SPELLER_BIN_TREE_CHECKER_H

#include "checker.h"

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
    ~BinTreeChecker() final = default;

    void add(const File& file) final;
    void check(const File& file) final;
};

#endif //SPELLER_BIN_TREE_CHECKER_H
