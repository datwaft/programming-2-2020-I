#pragma once
#include "Product2.h"
#include <sstream>
class Rectangle: public Figura {
private:
	int height;
	int width;
	std::string getLine(bool = true);
public:
	Rectangle(int, int);
	virtual ~Rectangle();
	virtual std::string toString() override;
};

