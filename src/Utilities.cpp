#include "Utilities.h"

using namespace std;

namespace utils {

  /* [string_of_double f] converts the double [f] to a string. */
  string string_of_double(const double f) {
    ostringstream converter;
    converter << f;
    return converter.str();
  }

  /* [string_from_dvector v] returns a human-readable description of the vector
     [v].
   */
  string string_from_dvector(const vector<double> v) {
    string s;
    for(unsigned int i = 0; i < v.size (); i++) {
      s += string_of_double(v[i]) + " ";
    }
    return s;
  }

  /* [print_vector v] print the vector [v] on STDIN. */
  void print_vector(vector<double> &v) {
    vector<double>::iterator it = v.begin();
    cout << "[ ";
    while(it != v.end()) {
      cout << *it << " ";
      it++;
    }
    cout << "]" << endl;
  }

  /* [split l elems] split the line [l] and store every elements of [l] into
     the vector [elems]. */
  vector<std::string> &split(const string &l,vector<std::string> &elems) {
    stringstream s(l);
    while(!s.eof()) {
      string tmp;
      s >> tmp;
      elems.push_back(tmp);
    }
    return elems;
  }

  /* [extract_nodes_with_word l p] extract informations from a line [l] 
     having this format : N words1 words2 words3 words4 words5.
     N is the node number and words{1...5} is the associated word to this node.
  */
  void extract_nodes_with_words(string l,
				pair<long long int, vector<string>>& p) {
    
    stringstream s(l);
    string tmp;
    s >> tmp;
    p.first = stoi(tmp);
    p.second.resize(5, "");
    int i = 0;
    while(s >> tmp) {
      p.second[i] = tmp;
      i++;
    }
  }

  /* [parse_line p l] parse the line [l] and store the first two elements 
   into the tuple [p]. */
  pair<double,double> &parse_line(pair<double,double> &p, string l) {
    vector<string> values;
    values = split(l, values);
    if(values.size() >= 2) {
      /* Formal description : there is an edge like this : p.first -> p.second */
      p.first = stod(values[0]);
      p.second = stod(values[1]);
    }
    return p;
  }

  /* [get_nodes] extract the number of nodes located at the top of the file 
   [filename] and return it. */
  long long int get_nodes(string filename) {
    ifstream file(filename);
    pair<double,double> p;
    string line;
    if(!file.is_open()) {
      perror("Error open");
      exit(EXIT_FAILURE);
    }    
    getline(file,line);
    parse_line(p,line);
    file.close();
    return p.first;
  }

  /* [vector_to_string v] returns an human-readable description of the vector 
   [v]. */
  string vector_to_string(vector<string> &v) {
    string s;
    for(unsigned int i = 0; i < v.size(); i++) {
      s += v[i] + " ";
    }
    return s;
  }

  /* [product_with_scalar] return a new vector resulting of the product between 
     the vector [v] and the scalar [s]. */
  vector<double> product_with_scalar(vector<double> v, double s)  {
    vector<double> r (v);
    for (unsigned int i (0); i < r.size (); i++) {
      r[i] *= s;
    }
    return (r);
  }

  /* [sum_with_scalar] return a new vector resulting of the sum between 
     the vector [v] and the scalar [s]. */
  vector<double> sum_with_scalar(vector<double> v, double s)  {
    vector<double> r (v);
    for (unsigned int i (0); i < r.size (); i++) {
      r[i] += s;
    }
    return (r);
  }

  /* [vector_difference] compute the distance between the vector [v1] and [v2].
   */
  double vector_difference (vector<double> &v1,  vector<double> &v2) {
    double result (0);
    for (unsigned int i (0); i < v1.size (); i++) {
      result += fabs (v1[i] - v2[i]);
    }
    return result;
  }  

  /* [create_nodes_with_words d fin] creates a file, called [[fin]_with_words],
     in which every line contains a node number and a word list. */
  void create_nodes_with_words(Dictionary &d, string fin) {
    string fout;
    long long int nodes;    
    fout = fin + "_with_words";
    ofstream out(fout);
    /* Getting the number of nodes located at the top of the file [fin]. */
    nodes = get_nodes(fin);
    vector<string> words;
    /* This help us to do not have the same number returning by random. */
    srand (time(NULL));  
    for(unsigned int i = 0; i < nodes; i++) {
      /* Getting a random list of words */
      d.random_words_list(words);
      /* Adding these to the file */
      out << i << " " << vector_to_string(words) << endl;
    }
    out.close();
  }

  /* [build_words_database Z fnodes_words m] store every words contains in the 
     file [fnodes_words] into the map [m] in the lexicographic way. For every
     words in the map, there is a nodes list sorted by the pageRank range. The
     vector [Z] contains the pageRank of every nodes.
   */
  void build_words_database(vector<double> &Z, string fnodes_words,
			    map<string, vector<long long int>> &m) {
    /* This represents every line from the file fnodes_words */
    string line;
    /* The tuple-2 with the node and his associated word list */
    pair<long long int, vector<string>> p;
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
      extract_nodes_with_words(line,p);
      node = p.first;
      words = p.second;
      /* For every words, add into his nodes list the node that we just met.*/
      for(unsigned int i = 0; i < words.size(); i++) {
	m[words[i]].push_back(node);
      }
    }    
    map<string, vector<long long int>>::iterator it = m.begin();
    /* Sorting every node list by pageRank range. */
    while(it != m.end()) {
      sort(m[it->first].begin(), m[it->first].end(),
	   [&Z](int x, int y) -> bool { return Z[x] > Z[y]; });
      it++;
    }
    file.close();
  }

  /* [request_word m word n] return the node list associated to the word [w] in 
   the map [m]. If there is a result, we print the [n] first nodes. */
  void request_word(map <string, vector<long long int>>& m, string w,
		     unsigned int n) {
    vector<long long int> v;
    v = m[w];
    /* The node doesn't appears in the map*/
    if(v.size() <= 0) {
      cout << "The word " << w << " appears in any node" << endl;
    } else {
      /* We check if the size of the resulting vector is equal to [n]. */
      if(v.size() < n) n = v.size();
      cout << "The word \'" << w << "\' appears in node(s) :  ";
      for(unsigned int i = 0; i < n; i++) {
	cout << v[i] << " - ";
      }
      cout << endl;
    }
  }

  /* [print_map m] print [m] in STDIN.*/
  void print_map(map<string,vector<long long int>> &m) {
    map<string, vector<long long int>>::iterator it = m.begin();
    vector<long long int> tmp;
    while(it != m.end()) {
      cout << "Words " << it-> first << " appears in node(s) : ";
      tmp = it -> second;
      for(unsigned int i = 0; i < tmp.size(); i++) {
	cout << tmp[i] << " ";
      }
      cout << endl;
      it++;
    }
  }
}

