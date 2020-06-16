#pragma once
#include "AbstractFigureCreator.h"
#include "Circle.h"
class CircleCreator: public AbstractFigureCreator {
private:
	int radius;
public:
	CircleCreator(int);
	virtual ~CircleCreator();
	virtual Circle* factoryMethod() override;
};

