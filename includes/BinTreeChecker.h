#ifndef SPELLER_BINTREECHECKER_H
#define SPELLER_BINTREECHECKER_H

#include "CheckWords.h"

struct Node
{
    Node* right;
    Node* left;
    std::string data;
};

class BinTreeChecker : public CheckWords
{
private:
    Node* root;
    static void addValueToTree(const std::string& val, Node*& head);
    static void deleteTree(Node* leaf);

    void checkInTree(const std::string& val, Node* head);
    void addValueByIndex(long left, long right, const std::vector<std::string>& values);

public:
    BinTreeChecker() : root(nullptr) {}
    ~BinTreeChecker();
    void addWords(const std::vector<std::string>& values) final;
    void checkWords(std::vector<std::string>& values) final;
};

#endif //SPELLER_BINTREECHECKER_H
