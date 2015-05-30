#ifndef UTILITIES_H
#define UTILITIES_H

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Dictionary.h"
#include <cmath>
#include <algorithm>  


/** 
    This module contains some utilities functions, which are used to parse or 
    to debug. It's also contains some functions without relation of our objets.
**/

namespace utils {

  // std::string string_of_double(const double);
  // std::string string_from_dvector(const std::vector<double>);
  // void print_vector(std::vector<double> &v);
  // std::vector <std::string> &split(const std::string &s,
  // 				  std::vector<std::string> &elems);
  /* std::pair <double,double> &parse_line(std::pair<double, double> &p, */
  /* 				     std::string line); */
  std::tuple<double,double> parse_line(std::tuple<double,double> &,
				       std::string);
  // std::vector<double> product_with_scalar(std::vector <double>,double);
  // std::vector<double> sum_with_scalar(std::vector <double>, double);
  // double vector_difference (std::vector <double>&,  std::vector <double> &);
  // void create_nodes_with_words(Dictionary &d, std::string);
  // void extract_nodes_with_words(std::string,
  // 				std::pair<
  // 				long long int,
  // 				std::vector<std::string>
  // 				>&);

  // void build_words_database(std::vector<double> &, std::string,
  // 			    std::map<std::string, std::vector<long long int>>&);

  // void print_map(std::map<std::string, std::vector<long long int>>&);

  // void request_word(std::map<std::string, std::vector<long long int>>&,
  // 		     std::string, unsigned int);
}

#endif
