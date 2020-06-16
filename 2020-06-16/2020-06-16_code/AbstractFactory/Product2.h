#pragma once
#include <string>
class Figura {
public:
	virtual ~Figura() = default;
	virtual std::string toString() = 0;
};
