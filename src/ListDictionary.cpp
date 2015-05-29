#include "Dictionary.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

Dictionary::Dictionary() {
  
}

Dictionary::~Dictionary() {
  
}

/* [dictionary_from_file f] fill the dictionary with the words in the file
   [f]. */
void Dictionary::dictionary_from_file(string f) {
  int i = 0;
  ifstream file(f);
  string line;
  if(!file.is_open()) {
    perror("Error open");
    return;
  }
  while(getline(file,line)) {
    dic[i++] = line;
  }
  file.close();
}

/* [random_words_list v] fill the vector [v] with 5 random words from the 
   dictionary. */
void Dictionary::random_words_list(vector<string> &v) {
  v.resize(5,"");
  for(int i = 0; i < 5; i++) {
    v[i] = dic[rand() % 999];
  }
}

/* [print_dictionary] print the dictionary on STDIN. */
void Dictionary::print_dictionary() {
  for(int i = 0; i < 1000; i++) {
    cout << dic[i] << endl;
  }
}

int Dictionary::size() {
  return 1000;
}


