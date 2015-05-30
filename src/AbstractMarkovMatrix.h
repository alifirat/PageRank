#ifndef AbstracMarkovMatrix_H
#define AbstracMarkovMatrix_H

#include <vector>
#include <string>

class AbstractMarkovMatrix {

 public:
  AbstractMarkovMatrix() {};
  virtual ~AbstractMarkovMatrix() {};
  virtual void fill_matrix(const std::string) = 0;
  virtual std::vector<double>  
  product_transpose_with_vector(std::vector<double> &) = 0;
  virtual std::vector<double>
  product_with_vector(std::vector<double> &) = 0;  
  virtual int getRows() = 0;
};

#endif	/* AbstracMarkovMatrix_H */
