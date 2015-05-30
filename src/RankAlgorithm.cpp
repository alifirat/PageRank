#include "RankAlgorithm.h"
#include "Utilities.h"

using namespace std;

RankAlgorithm::RankAlgorithm() {}

RankAlgorithm::RankAlgorithm(MarkovMatrix m) {
  _m = m;
}

vector<double> RankAlgorithm::pageRank(vector<double> &Z,
			    vector<double> result,
			    double epsilon) {
  result.resize(Z.size(), 0.0);
  vector<double> p(Z);
  int converge = 0;
  double delta = epsilon + 2;
  while(epsilon <= delta) {
    /* Make the product between the transpose of our CLi matrix and p*/
    result = _m.product_transpose_with_vector (p);
    /* Compute the distance between the two vector result and p. */
    delta = utils::vector_difference (result, p);
    p = result;
    converge++;
  }
  cout << "Converge in " << converge << " step." << endl;
  return result;
}

vector<double> RankAlgorithm::pageRank (vector<double> &Z,
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
    prod1 = utils::product_with_scalar (_m.product_transpose_with_vector(r),
					(1 - zap));
    /* Making the sum operation between the resulting vector a scalar.*/
    result = utils::sum_with_scalar (prod1, (zap / size));
    /* Computing the distance between the vector result and r.*/
    delta = utils::vector_difference (result, r);
    r = result;
    converge++;
  }
  cout << "Converge in " << converge << " step." << endl;  
  return (result);
}

void RankAlgorithm::setMatrix(MarkovMatrix m) {
  _m = m;
}


RankAlgorithm::~RankAlgorithm() {}
