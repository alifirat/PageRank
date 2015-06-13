#include <iostream>
#include <stdio.h>
#include "Utilities.h"
#include "ListDictionary.h"
#include "MarkovMatrix.h"
#include "RankAlgorithm.h"
#include "WordsDatabase.h"
#include "SearchEngine.h"

using namespace std;

int main(int argc, char **argv) {
  const string dictionary_path = "./dic/dictionary.txt";
  string fin, user_input;
  MarkovMatrix m;
  RankAlgorithm rm;
  vector<double> Z, result;
  double epsilon,zap;
  ListDictionary<string> dic;
  WordsDatabase db;
  vector<long long int> nodes_from_se;
  SearchEngine se;
  unsigned int max_value;
  if(argc <= 1 || argc >= 4) {
    cout << "Bad number arguments." << endl;
    cout << "Usage : ./search filename [N]" << endl;
    cout << "You can provide an argument N to set the "
  	 << "number of results to print." << endl;
  } else {
    /* From a file with a graph description, we fill our array C, L and I */
    m.fill_matrix(argv[1]);

    
    rm.setMatrix(m);
    
    /* We choose a uniform vector before to launch the pageRankZAP */
    Z.resize((m.getRows()), (1.0 / (m.getRows())));

    /* Setting the epsilon and zap factor*/
    epsilon = 0.15;
    zap = 0.2;

    /* Lauching the pageRankZap algorithm */
    cout << "PageRankZAP algorithm is started." << endl;
    result = rm.pageRank(Z,epsilon,zap);

    // /* Store in the memory the dictionary with 1000 words */
    cout << "The dictionary of words is creating : ";
    cout.flush();
    dic.dictionary_from_file(dictionary_path);
    cout << "Done " << endl;
	/* Creating the file with node number and five random words associated to 
	   him. */
    cout << "Creating file with nodes and words : ";
    cout.flush();
    utils::create_nodes_with_words(dic,argv[1]);
    fin = argv[1];
    fin += "_with_words";
    cout << "Done " << endl;

	/* Creating a "database" which we can request */
     cout << "Building the words database : ";
    cout.flush();
  	db.fill_database(result, fin);
	// db.printDB();
	
    cout << "Done " << endl;
    /* Asked to the user to enter word*/
    cout << "Provide a word : ";
    cin >> user_input;

	/* Set the maximum of results to print. */
    if(argc == 2) max_value = 10;
    if(argc >= 3) max_value = strtol(argv[2],NULL,10);

	/* Found the nodes where the user word appears */
	nodes_from_se = se.request_word(&db, user_input);

	/* Print the result of the asked word. */
	if(nodes_from_se.size() > 0) {
		cout << "The word \'" << user_input << "\' appears in node : " << endl;
		for(unsigned int i = 0; i < max_value; i++) {
			cout << nodes_from_se[i] << " - ";
			cout.flush();
		}
		cout << endl;
	} else {
		cout << "The word \'" << user_input << "\' appears in any nodes ... "
			 << endl;
	}
  }
  return 0;
}
