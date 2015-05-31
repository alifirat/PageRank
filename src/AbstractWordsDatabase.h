#ifndef AbstractWordsDatabase_H
#define AbstractWordsDatabase_H

#include <string>
#include <vector>

class AbstractWordsDatabase {

public:
	AbstractWordsDatabase() {}
	virtual ~AbstractWordsDatabase() {};
	virtual void fill_database(std::vector<double> &, const std::string) = 0;

};

#endif	/* AbstractWordsDatabase_H */
