#include "MarkovMatrix.h"
#include <tuple>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Utilities.h"

using namespace std;

MarkovMatrix::MarkovMatrix() {}

// TODO : rewrite this function 
int MarkovMatrix::getRows() {
  return _L.size()-1;
}

// TODO : rewrite this function 

void MarkovMatrix::fill_matrix(const string filename) {
  /* We put every line of the file in this variable */
  string line;
  ifstream myfile(filename);
  /* Temporary tuple-2 in which we put the description of the edge */
  // pair <double, double> p;
  tuple<double,double> t(0,0);
  long int edges;
  /* 
     i is the iterator index of the array L.
     distance corresponds to the distance between two nodes.
   */
  int i = 0, distance = 0;
  /* cnode corresponds to the current node in the file (the first must be 0).
     degre represents the numbers of edges leaving from a node 
     line_jump is the jump value between the lines of the matrix.
  */
  double cnode = 0, degre = 0.0, line_jump;
  if(!myfile.is_open()) {
    perror("Error open");
    return;
  }
  /* Getting the number of edges located at the top of the file. */
  getline(myfile, line);
  utils::parse_line(t,line);
  edges = get<1>(t);

  _L.push_back(0.0);
  while(getline(myfile,line)) {
    utils::parse_line(t,line);
    /* Filling the array I */
    _I.push_back(get<1>(t));
    /* We met the same node that the previous so we increment his degre*/
    if(cnode == get<0>(t)) {
      degre++;
    } else {
      /* Filling the array L */
      line_jump = degre + _L[i];
      _L.push_back(line_jump);

      /* Some files have jumps between nodes, we offer a way to deal with 
	 this case : we consider that for theses nodes, there is only 0 on the
	 line of the matrix. */
      distance = get<0>(t) - cnode;
      if(distance > 1) {
	for(int k = 0; k < (distance-1); k++) {
	  _L.push_back(line_jump);
	}
	i += (distance-1);
      } 
      for(int k = 0; k < degre; k++) {
	_C.push_back(1.0 / degre);
      }
      i++;      
      cnode = get<0>(t);
      degre = 1;    
    }
  }
  /* This is a last loop for the last node of the graph. */
  for(int k = 0; k < degre; k++) {
    _C.push_back(1.0 / degre);	
  }  
  _L.push_back(edges);
  myfile.close();
}

vector<double> MarkovMatrix::product_transpose_with_vector(vector<double> &v) {
  vector<double> result (v.size (), 0.0);
  for (unsigned int i (0); i < (v.size ()); i++){
    for (unsigned int j (_L[i]); j < _L[i + 1]; j++){
      result[_I[j]] += _C[j] * v[i];
    }
  }
  return result;
}

vector<double> MarkovMatrix::product_with_vector(vector<double> &v) {
  vector<double> res(v.size(),0);
  for(int i = 0; i < (_L[_L.size () - 1]); i++) {
    res[i] = 0;
    for(int j = _L[i]; j < (_L[i+1]); j++) {
      res[i] += _C[j] * v.at(_I[j]);
    }
  }
  return res; 
}



MarkovMatrix::~MarkovMatrix() {}
