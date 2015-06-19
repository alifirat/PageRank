#ifndef UTILITIES_H
#define UTILITIES_H

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "ListDictionary.h"
#include <cmath>
#include <algorithm>  
#include <tuple>

/** 
    This module contains some utilities functions, which are used to parse or 
    to debug. It's also contains some functions without relation of our objets.
**/

namespace utils {

  std::tuple<double,double> parse_line(std::tuple<double,double> &,
				       std::string);
  std::vector<double> product_with_scalar(std::vector <double>,double);
  std::vector<double> sum_with_scalar(std::vector <double>, double);
  double vector_difference (std::vector <double>&,  std::vector <double> &);
  void create_nodes_with_words(ListDictionary<std::string> &, std::string);
  long long int get_nodes(const std::string);
  void extract_nodes_with_words(std::string,
								std::tuple<long long int,
								std::vector<std::string>> &);
}

#endif
