#include "Cli.h"

using namespace std;
using namespace utils;

Cli::Cli() {  

}

Cli::~Cli()
{
    //dtorb
}

/* [pageRank Z r epsilon] launch the pageRank algorithm with the initial vector
 [Z] and the factor [epsilon]. If the algorithm converge, the final vector will
 be in [result]. */
vector<double> Cli::pageRank (vector<double> &Z, vector<double> result,
		    double epsilon)  {  
  result.resize(Z.size(), 0.0);
  vector<double> p (Z);
  int converge = 0;
  double delta = epsilon + 2;
  while(epsilon <= delta) {
    /* Make the product between the transpose of our CLi matrix and p*/
    result = transpose_with_vector (p);
    /* Compute the distance between the two vector result and p. */
    delta = vector_difference (result, p);
    p = result;
    converge++;
  }
  cout << "Converge in " << converge << " step." << endl;
  return result;
}

/* [pageRankZAP] corresponds to our second pageRank algorithm with one more 
   factor. [Z] is the initial vector on which we launch the algoritm with the 
   factor [epsilon] and the factor [zap]. */
vector<double> Cli::pageRankZAP (vector<double> &Z,
				 double epsilon,
				 double zap)  {
  int converge = 0;
  vector<double> result (Z);
  vector<double> r (Z);
  double delta = epsilon + 2;
  double size = Z.size();
  vector<double> prod1;
  while (epsilon <= delta) {
    /* Compute the product between the vector, resulting by the tranpose 
       operation between our CLI matrix and the vector r, and a scalar. */
    prod1 = product_with_scalar (transpose_with_vector(r), (1 - zap));
    /* Making the sum operation between the resulting vector a scalar.*/
    result = sum_with_scalar (prod1, (zap / size));
    /* Computing the distance between the vector result and r.*/
    delta = vector_difference (result, r);
    r = result;
    converge++;
  }
  cout << "Converge in " << converge << " step." << endl;  
  return (result);
}

/* [transpose_with_vector v] compute the product operation between the 
   the tranpose of our CLI matrix and the vector [v]. */
vector<double> Cli::transpose_with_vector (vector<double> &v)  {
  vector<double> result (v.size (), 0.0);
  assert(v.size() == (L.size() - 1));
  for (unsigned int i (0); i < (v.size ()); i++){
    for (unsigned int j (L[i]); j < L[i + 1]; j++){
      result[I[j]] += C[j] * v[i];
    }
  }
  return (result);
}


/* [to_cli filename] converts the graph from his description in the file 
   [filename] to a matrix in the CLI format. */
void Cli::to_cli( string filename) {
  /* We put every line of the file in this variable */
  string line;
  ifstream myfile(filename);
  /* Temporary tuple-2 in which we put the description of the edge */
  pair <double, double> p;
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
  parse_line(p,line);
  edges = p.second;

  L.push_back(0.0);
  while(getline(myfile,line)) {
    parse_line(p,line);
    /* Filling the array I */
    I.push_back(p.second);
    /* We met the same node that the previous so we increment his degre*/
    if(cnode == p.first) {
      degre++;
    } else {
      /* Filling the array L */
      line_jump = degre + L[i];
      L.push_back(line_jump);

      /* Some files have jumps between nodes, we offer a way to deal with 
	 this case : we consider that for theses nodes, there is only 0 on the
	 line of the matrix. */
      distance = p.first - cnode;
      if(distance > 1) {
	for(int k = 0; k < (distance-1); k++) {
	  L.push_back(line_jump);
	}
	i += (distance-1);
      } 
      for(int k = 0; k < degre; k++) {
	C.push_back(1.0 / degre);
      }
      i++;      
      cnode = p.first;
      degre = 1;    
    }
  }
  /* This is a last loop for the last node of the graph. */
  for(int k = 0; k < degre; k++) {
    assert ((1.0 / degre) != 0);
    C.push_back(1.0 / degre);	
  }  
  L.push_back(edges);
  myfile.close();
}

/* [product_with_vector v] do the product between our matrix CLI and the vector
 [v].*/
vector<double> Cli::product_with_vector(vector<double> &v) {
  vector<double> res(v.size(),0);
  for(int i = 0; i < (L[L.size () - 1]); i++) {
    res[i] = 0;
    for(int j = L[i]; j < (L[i+1]); j++) {
      res[i] += C[j] * v.at(I[j]);
    }
  }
  return res;
}


/* [sizeL] return the size of L array of our matrix CLi. */
int Cli::sizeL() {
  return L.size();
}

/* [getCLI] returns a human-readable representation of our matrix CLI. */
string Cli::getCLI() const {
  string s;
  s += "C = [ ";
  s += string_from_dvector(C);
  s += "]\nL = [ ";
  s += string_from_dvector(L);
  s += "]\nI = [ ";
  s += string_from_dvector(I);
  s += "]\n";
  return s;
}




