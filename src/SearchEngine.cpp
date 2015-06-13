#include "SearchEngine.h"

#include <iostream>

using namespace std;

SearchEngine::SearchEngine() {}

vector<long long int> SearchEngine::request_word(AbstractWordsDatabase *db,
												 const string word) {
	return db->getValues(word);
}
	

SearchEngine::~SearchEngine() {}
