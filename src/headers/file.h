#ifndef SPELLER_FILE_H
#define SPELLER_FILE_H

#include <fstream>
#include <string>
#include <vector>

class File {
 private:
  std::ifstream file;
  std::string fileName;
  std::vector<std::string> words;
  void process();

 public:
  explicit File(const std::string& filePath);
  ~File();
  std::vector<std::string> getWords() const;
  std::string getFileName() const;
};

#endif  // SPELLER_FILE_H
