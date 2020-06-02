#pragma once
#include "Component.h"
class Square: public Component {
protected:
	unsigned int x;
	unsigned int y;
	double l;
public:
	Square(unsigned int, unsigned int, double);
	virtual ~Square() = default;
	virtual double area() override;
	virtual double perimetro() override;
};

