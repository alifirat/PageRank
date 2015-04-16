#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>

/* This class corresponds to a simple dictionary of string. */

class Dictionary {
 public:
  Dictionary();
  void dictionary_from_file(std::string);
  void print_dictionary();
  void random_words_list(std::vector<std::string> &);
  int size();
 private:
  std::string dic[1000];
};

#endif 
