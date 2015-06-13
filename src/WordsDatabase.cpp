#include "WordsDatabase.h"
#include "Utilities.h"
#include <fstream>
#include <tuple>

using namespace std;

WordsDatabase::WordsDatabase() {}

void WordsDatabase::fill_database(vector<double> &Z, const string fnodes_words)
{
  	string line;
    /* The tuple-2 with the node and his associated word list */
	// pair<long long int, vector<string>> p;
	tuple<long long int, vector<string>> t(0, {});
    /* Temporay variable for every node in the file fnodes_words */
    long long int node;
    /* The vector of words associated to a node*/
    vector<string> words;    
    ifstream file(fnodes_words);    
    if(!file.is_open()) {
		perror("Error open");
		exit(EXIT_FAILURE);
    }
    while(getline(file,line)){
		/* Extract the node and the words list from line. */
		utils::extract_nodes_with_words(line,t);
		node = get<0>(t);
		words = get<1>(t);
		/* For every words, add into his nodes list the node that we just met.*/
		for(unsigned int i = 0; i < words.size(); i++) {
			_m[words[i]].push_back(node);
		}
    }    
    auto it = _m.begin();
    /* Sorting every node list by pageRank range. */
    while(it != _m.end()) {
		sort(_m[it->first].begin(), _m[it->first].end(),
			 [&Z](int x, int y) -> bool { return Z[x] > Z[y]; });
		it++;
    }
    file.close();
}


vector<long long int> WordsDatabase::getValues(const string word) {
	return _m[word];
}

void WordsDatabase::printDB() {
	for(auto it :  _m) {
		cout << "Word" << it.first << endl;
		cout << "Node : ";
		cout.flush();
		for(auto node : it.second) {
			cout << node << " ";
		}
		cout.flush();
	}
}

WordsDatabase::~WordsDatabase() {}
