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
		auto it = v.begin();
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
								  tuple <long long int,
								  vector<string>> &t) {
		stringstream s(l);
		string tmp;
		s >> tmp;
		get<0>(t) = stoi(tmp);
		// p.first = stoi(tmp);
		// p.second.resize(5, "");
		get<1>(t).resize(5,"");
		int i = 0;
		while(s >> tmp) {
			// p.second[i] = tmp;
			get<1>(t)[i] = tmp;
			i++;
		}
	}

    tuple<double,double> parse_line(tuple<double,double> &t, string l) {
		vector<string> values;
		values = split(l, values);
		if(values.size() >= 2) {
			/* Formal description : there is an edge like this : p.first -> p.second */
			get<0>(t) = stod(values[0]);
			get<1>(t) = stod(values[1]);
		}
		return t;
	}


	/** [get_nodes] extract the number of nodes located at the top of the file 
		[filename] and return it. */
	long long int get_nodes(const string filename) {
		ifstream file(filename);
		tuple<double,double> t(0., 0.);
		string line;
		if(!file.is_open()) {
			perror("Error open");
			exit(EXIT_FAILURE);
		}    
		getline(file,line);
		parse_line(t,line);
		file.close();
		return get<0>(t);
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
	void create_nodes_with_words(ListDictionary<string> &d, string fin) {
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
			words = d.randomize_vector();
			/* Adding these to the file */
			out << i << " " << vector_to_string(words) << endl;
		}
		out.close();
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
		vector<long long int> tmp;
		for(auto kv: m) {
			cout << "Words " << kv.first << " appears in nodes (s) : ";
			for(auto value : kv.second) {
				cout << value << " ";
			}      
		}
	}
}

