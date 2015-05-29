#include "ListDictionary.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

template <class T>
ListDictionary<T>::ListDictionary(void) {}

template <class T>
void ListDictionary<T>::add_entry(T x) {
  _dictionary.push_back(x);
}

template <class T>
ListDictionary<T>::~ListDictionary(void) {}

template <class T>
void ListDictionary<T>::dictionary_from_file(string filename) {
  ifstream file(filename);
  string line;
  if(!file.is_open()) {
    perror("Error open ");
    return;
  }
  while(getline(file,line)) {
    _dictionary.push_back(line);
  }
  file.close();
}

// /* [random_words_list v] fill the vector [v] with 5 random words from the 
//    dictionary. */
// void Dictionary::random_words_list(vector<string> &v) {
//   v.resize(5,"");
//   for(int i = 0; i < 5; i++) {
//     v[i] = dic[rand() % 999];
//   }
// }

// /* [print_dictionary] print the dictionary on STDIN. */
// void Dictionary::print_dictionary() {
//   for(int i = 0; i < 1000; i++) {
//     cout << dic[i] << endl;
//   }
// }

// int Dictionary::size() {
//   return 1000;
// }


