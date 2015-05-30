#ifndef MarkovMatrix_H
#define MarkovMatrix_H

#include "AbstractMarkovMatrix.h"
#include <string>
#include <vector>

class MarkovMatrix : public AbstractMarkovMatrix {
 public:
  MarkovMatrix();
  virtual ~MarkovMatrix();
  std::vector<double>
  product_transpose_with_vector(std::vector<double> &) override;
  std::vector<double> product_with_vector(std::vector<double> &) override;  
  void fill_matrix(const std::string) override;
  int getRows() override; 
 private:
  std::vector<double> _C;
  std::vector<double> _L;
  std::vector<double> _I;

};

#endif
