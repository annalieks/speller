#include "file.h"
#include <iostream>
#include <regex>

// constructor
File::File(const std::string& filePath) {
  file.open(filePath, std::ios::in);
  if (!file) {
    std::cerr << "Unable to open file ";
    exit(1);
  }
  process();

  std::regex target(R"([\w]+\.\w*)");
  std::smatch match;
  std::regex_search(filePath, match, target);
  fileName = match.str(0);
}

// destructor
File::~File() {
    file.close();
}

// pushes words transformed into lower case
// and processed by regular expression into vector of words
void File::process() {
  std::string word;
  std::regex target("([a-z]*|[a-z][a-z']*[a-z])");
  std::regex removedSymbols("[^a-z' ]*");
  std::smatch match;

  while (file >> word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    word = std::regex_replace(word, removedSymbols, "");
    std::regex_search(word, match, target);
    word = match.str(0);

    if (!word.empty()) {
      words.push_back(word);
    }
  }
}

std::vector<std::string> File::getWords() const {
    return words;
}

std::string File::getFileName() const {
    return fileName;
}
