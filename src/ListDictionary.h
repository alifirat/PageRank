#ifndef ListDictionary_H
#define ListDictionary_H

#include "Dictionary.h"
#include <string>
#include <vector>

template <class T>
class ListDictionary : public Dictionary<T> {

public:
  ListDictionary(void);
  ~ListDictionary(void);
  void add_entry(T x) override;

 private:
  std::vector<T> _dictionary;

};


#endif	/* ListDictionary_H */
