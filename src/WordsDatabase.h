#ifndef WordsDatabase_H
#define WordsDatabase_H

#include "AbstractWordsDatabase.h"
#include <map>
#include <vector>
#include <string>

class WordsDatabase : public AbstractWordsDatabase {

public:
	WordsDatabase();
	virtual ~WordsDatabase();
	void fill_database(std::vector<double> &, const std::string) override;

private:
	std::map<std::string, std::vector<long long int>> _m;
	
};

#endif	/* WordsDatabase_H */
