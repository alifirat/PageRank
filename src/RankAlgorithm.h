#ifndef RankAlgorithm_H
#define RankAlgorithm_H

#include "AbstractRankAlgorithm.h"
#include "MarkovMatrix.h"
#include <vector>

class RankAlgorithm : public AbstractRankAlgorithm {
 public:
  RankAlgorithm();
  RankAlgorithm(MarkovMatrix m);
  std::vector<double> pageRank(std::vector<double> &,
			       std::vector<double>,
			       double) override;
  std::vector<double> pageRank(std::vector<double> &,
			       double,
			       double);
  void setMatrix(MarkovMatrix m);
  virtual ~RankAlgorithm();

private:
  MarkovMatrix _m;
  
};

#endif	/* RankAlgorithm_H */
