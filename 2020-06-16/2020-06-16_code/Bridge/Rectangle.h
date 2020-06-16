#pragma once
#include "Figura.h"
#include "Color.h"
#include <sstream>
class Rectangle: public Figura {
private:
	int height;
	int width;
	Color* color;
	std::string getLine(bool = true);
public:
	Rectangle(int, int, Color* = nullptr);
	virtual ~Rectangle();
	virtual std::string toString() override;
};

