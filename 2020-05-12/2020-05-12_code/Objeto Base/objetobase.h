#pragma once
#include <string>

class ObjetoBase {
public:
	virtual std::string getIdentifier() = 0;
	virtual std::string toString() = 0;
	virtual std::string serialize() = 0;
};
