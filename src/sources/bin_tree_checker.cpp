#include <iostream>
#include "bin_tree_checker.h"

// virtual function that adds element to the tree
void BinTreeChecker::add(const File& file)
{
    timer->startTimer();

    addValueByIndex(0, long(file.getWords().size())-1, file.getWords());

    addTime += timer->getPassedTime();
}

//recursive function for calculating element index and adding element to the tree
void BinTreeChecker::addValueByIndex (long left, long right, const std::vector<std::string>& values )
{
    long mid = (right+left)/2;
    addValueToTree(values[mid], root);
    if(right == left)
        return;
    addValueByIndex(left, mid, values);
    addValueByIndex(mid+1, right, values);
}

// recursive function for adding elements into tree (using node root)
void BinTreeChecker::addValueToTree(const std::string& val, std::shared_ptr<Node>& head)
{
    if (head == nullptr)
    {
        head = std::make_shared<Node>(Node());
        head->data = val;
        return;
    }
    else if (head->data > val)
    {
        addValueToTree(val, head->left);
    }
    else if (head->data < val)
    {
        addValueToTree(val, head->right);
    }
}

// virtual function for checking every word from vector of words
void BinTreeChecker::check(const File& file)
{
    timer->startTimer();

    for (const auto& val : file.getWords())
        checkInTree(val, root);

    checkedWords += file.getWords().size();
    checkTime += timer->getPassedTime();
}

// checks if element is in the tree (private function)
void BinTreeChecker::checkInTree(const std::string& val, std::shared_ptr<Node>& head)
{
    if(head == nullptr)
    {
        incorrectWords++;
        return;
    }
    if (head->data > val)
        checkInTree(val, head->left);
    if (head->data < val)
        checkInTree(val, head->right);
}

BinTreeChecker::BinTreeChecker() : root(nullptr)
{
    structureName = "Binary Tree";
}