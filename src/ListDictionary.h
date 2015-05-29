#ifndef ListDictionary_H
#define ListDictionary_H

#include "Dictionary.h"
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <fstream>


template <class T>
class ListDictionary : public Dictionary<T> {
  
public:
  ListDictionary() {}
  virtual ~ListDictionary() {}
  void add_entry(T x) {
    _dictionary.push_back(x);
  }
  void dictionary_from_file(const std::string filename) {
      std::ifstream file(filename);
      std::string line;
      if(!file.is_open()) {
	perror("Error open ");
	return;
      }
      while(getline(file,line)) {
	_dictionary.push_back(line);
      }
      file.close();      
  }
  std::vector<T> randomize_vector(unsigned int limit = 5) {
    std::vector<T> res;
    T random_elt;
    if(limit > 0) {
      srand(time(0));
      for(unsigned int i = 0; i < limit; i++) {
	random_elt = _dictionary[rand() % this->size()];
	res.push_back(random_elt);
      }
    }
    return res;
  }

  void print_dictionary() {
    for(auto word : _dictionary) {
      std::cout << "Word -> " << word << std::endl;
    }
  }

  int size() {
    return _dictionary.size();
  }
    
 private:
  std::vector<T> _dictionary;

};

#endif	/* ListDictionary_H */
