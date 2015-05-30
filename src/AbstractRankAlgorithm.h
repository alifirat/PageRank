#ifndef AbstractRankAlgorithm_H
#define AbstractRankAlgorithm_H

#include <vector>

class AbstractMarkovMatrix;

class AbstractRankAlgorithm {

 public:
  AbstractRankAlgorithm() {};
  virtual ~AbstractRankAlgorithm() {};
  virtual std::vector<double> pageRank(std::vector<double> &,
				       std::vector<double>,
				       double) = 0;
  virtual std::vector<double> pageRank(std::vector<double> &,
				       double,
				       double)= 0;
  

};

#endif	/* AbstractRankAlgorithm_H */
