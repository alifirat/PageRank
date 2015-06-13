#ifndef SearchEngine_H
#define SearchEngine_H

#include "AbstractSearchEngine.h"
#include <vector>

class SearchEngine : public AbstractSearchEngine {

public:
	SearchEngine();
	virtual ~SearchEngine();
	std::vector<long long int> request_word(AbstractWordsDatabase *,
											const std::string) override;
	
	
};

#endif	/* SearchEngine_H */
