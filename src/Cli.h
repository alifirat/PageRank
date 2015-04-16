#ifndef CLI_H
#define CLI_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <assert.h>
#include <stdlib.h>
#include "Utilities.h"


/* You can find all excepted codes about the PageRank in the source file 
 corresponding to this interface. */

class Cli {
 public:
  Cli();
  virtual ~Cli();
  std::vector <double> pageRank(std::vector<double> &, std::vector<double>,
				double) ;
  std::vector <double> pageRankZAP (std::vector<double>&, double, double) ;
  std::vector<double> product_with_vector(std::vector<double>&);
  std::vector <double> transpose_with_vector (std::vector<double> &) ;  
  int sizeL();  
  void to_cli(std::string);
  std::string getCLI() const;
  
 private:
        std::vector <double> C;
        std::vector <double> L;
        std::vector <double> I;
};

#endif // CLI_H
