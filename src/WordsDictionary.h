#ifndef WORDSDICTIONARY_H
#define WORDSDICTIONARY_H

#include <string>
#include <vector>

class WordsDictionary {
 public:
  WordsDictionary() {}
  virtual ~WordsDictionary() {};
  virtual void dictionary_from_file(std::string) = 0;
  virtual void print_dictionary() = 0;
  virtual void random_words_list(std::vector<std::string> &) = 0;
  virtual int size() = 0;
};

#endif 
  
