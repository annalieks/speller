#include <iostream>
#include "../includes/BinTreeChecker.h"

// destructor
BinTreeChecker::~BinTreeChecker()
{
    deleteTree(root);
}

// virtual function that adds element to the tree
void BinTreeChecker::addWords(const std::vector<std::string>& values)
{
    addValueByIndex(0, long(values.size())-1, values);
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
void BinTreeChecker::addValueToTree(const std::string& val, Node*& head)
{
    if (head == nullptr)
    {
        head = new Node();
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
void BinTreeChecker::checkWords(std::vector<std::string>& values)
{
    for (const auto& val : values)
        checkInTree(val, root);
}

// checks if element is in the tree (private function)
void BinTreeChecker::checkInTree(const std::string& val, Node* head)
{
    if(head == nullptr)
    {
        incorrectWords++;
        writeIncorrectWord(val, outFile);
        return;
    }
    if (head->data > val)
        checkInTree(val, head->left);
    if (head->data < val)
        checkInTree(val, head->right);
}

// deletes tree
void BinTreeChecker::deleteTree(Node* leaf)
{
    if(leaf != nullptr){
        deleteTree(leaf->left);
        deleteTree(leaf->right);
        delete leaf;
    }
}
