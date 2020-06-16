#pragma once
#include "Figure.h"
class AbstractFigureCreator {
public:
	virtual ~AbstractFigureCreator() = default;
	virtual Figure* factoryMethod() = 0;
};

