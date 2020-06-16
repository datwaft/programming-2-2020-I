#pragma once
#include <string>
class Figure {
public:
	virtual ~Figure() = default;
	virtual std::string toString() = 0;
};

