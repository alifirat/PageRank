#ifndef MarkovMatrix_H
#define MarkovMatrix_H

#include "AbstractMarkovMatrix.h"
#include <string>
#include <vector>

class MarkovMatrix : public AbstractMarkovMatrix {
 public:
  MarkovMatrix();
  virtual ~MarkovMatrix();
  int getRows() override;
  int getColumns() override;
  std::vector<double> product_transpose_with_vector(std::vector<double> &) override;
  void fill_matrix(const std::string) override;
    
 private:
  std::vector<double> C;
  std::vector<double> L;
  std::vector<double> I;

};

#endif
