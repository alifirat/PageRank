#ifndef AbstractSearchEngine_H
#define AbstractSearchEngine_H

#include <vector>
#include <string>
#include "AbstractWordsDatabase.h"

class AbstractSearchEngine {

public:
	AbstractSearchEngine() {};
	virtual ~AbstractSearchEngine() {};
	virtual std::vector<long long int> request_word(AbstractWordsDatabase *,
											const std::string) = 0;

};

#endif	/* AbstractSearchEngine_H */
