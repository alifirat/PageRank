#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "WordsDictionary.h"
#include <string>
#include <vector>

class Dictionary : WordsDictionary {
 public:
  Dictionary();
  virtual ~Dictionary();
  void dictionary_from_file(std::string) override;
  void print_dictionary() override;
  void random_words_list(std::vector<std::string> &) override;
  int size() override;
  
 private:
  std::string dic[1000];
};

#endif 
