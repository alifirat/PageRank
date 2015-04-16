#include <iostream>
#include <stdio.h>
#include "src/Cli.h"
#include "src/Utilities.h"
#include "src/Dictionary.h"

using namespace std;

ostream &operator<<(ostream &os, const Cli &p) {
    os << p.getCLI();
    return os;
}

int main(int argc, char **argv) {
  clock_t begin_time;
  Cli cli;
  Dictionary d;
  vector<string> v;
  vector<double> Z, result;
  string fin, user_input;
  double epsilon,zap;
  unsigned int max_value;
  map<string, vector<long long int>> m;
  if(argc <= 1 || argc >= 4) {
    cout << "Bad number arguments." << endl;
    cout << "Usage : ./search filename [N]" << endl;
    cout << "You can provide an argument N to set the "
	 << "number of results to print." << endl;
  } else {
    /* From a file with a graph description, we fill our array C, L and I */
    cli.to_cli(argv[1]);

    /* We choose a uniform vector before to launch the pageRankZAP */
    Z.resize((cli.sizeL()- 1), (1.0 / (cli.sizeL()-1)));

    /* Setting the epsilon and zap factor*/
    epsilon = 0.15;
    zap = 0.2;

    begin_time = clock();
    /* Lauching the pageRankZap algorithm */
    cout << "PageRankZAP algorithm is started." << endl;
    result = cli.pageRankZAP(Z,epsilon,zap);
    cout << "PageRankZAP algorithm is done. Time = "
	 << float (clock() - begin_time) / CLOCKS_PER_SEC << " s" << endl;

    /* Store in the memory the dictionary with 1000 words */
    cout << "The dictionary of words is creating : ";
    d.dictionary_from_file("metadata/dictionary.txt");
    cout << "Done" << endl;

    /* Creating the file with node number and five random words associated to 
       him. */
    cout << "Creating file with nodes and words : ";;
    utils::create_nodes_with_words(d,argv[1]);
    fin = argv[1];
    fin += "_with_words";
    cout << "Done" << endl;

    begin_time = clock();
    /* Creating a "database" which we can request */
    cout << "Building the words database : ";
    utils::build_words_database(result, fin, m);
    cout << "Done. Time = "
  	 << float (clock() - begin_time) / CLOCKS_PER_SEC << " s" << endl;

    /* Asked to the user to enter word*/
    cout << "Provide a word : ";
    cin >> user_input;

    /* Set the maximum of results to print. */
    if(argc == 2) max_value = 10;
    if(argc >= 3) max_value = strtol(argv[2],NULL,10);

    /* Print the result of the asked word. */
    utils::request_word(m, user_input, max_value);
  }
  return 0;
}
