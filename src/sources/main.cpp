#include "bin_tree_checker.h"
#include "checker.h"
#include "hash_map_checker.h"
#include "hash_table_checker.h"
#include "vector_checker.h"
#include <string>

int main() {
  std::string dictPath = "../dictionary.txt";
  std::vector<std::string> textsPaths = {
      "../texts/alice.txt", "../texts/dracula.txt", "../texts/holmes.txt",
      "../texts/sherlock.txt", "../texts/tolstoy.txt"};

  std::vector<std::unique_ptr<Checker>> structVector;
  structVector.emplace_back(std::unique_ptr<Checker>(new BinTreeChecker()));
  structVector.emplace_back(std::unique_ptr<Checker>(new VectorChecker()));
  structVector.emplace_back(std::unique_ptr<Checker>(new hashMapChecker()));
  structVector.emplace_back(std::unique_ptr<Checker>(new hashTableChecker()));

  // process dictionary
  File dictionary(dictPath);

  // add dictionary
  for (const auto& dataStruct : structVector) {
    dataStruct->add(dictionary);
  }

  // check words
  for (const auto& filePath : textsPaths) {
    File text(filePath);
    for (const auto& dataStruct : structVector) {
      dataStruct->check(text);
    }
  }

  // print information about checks
  for (const auto& dataStruct : structVector) {
    dataStruct->printCheckInfo();
  }

  return 0;
}