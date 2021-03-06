#ifndef Dictionary_H
#define Dictionary_H

#include <string>
#include <vector>

template <class T>
class Dictionary {
public:
  Dictionary() {};
  virtual ~Dictionary() {};
  virtual void add_entry(T) = 0;
  virtual void dictionary_from_file(const std::string) = 0;
  virtual std::vector<T> randomize_vector(unsigned int limit = 5) = 0;
  virtual void print_dictionary() = 0;
  virtual int size() = 0;
 
};

#endif	/* Dictionary_H */
  
