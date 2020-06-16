#pragma once
#include "Figure.h"
#include <sstream>
class Circle: public Figure {
private:
	int radius;
	std::string getLine(int h);
public:
	Circle(int);
	virtual ~Circle();
	virtual std::string toString() override;
};

