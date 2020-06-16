#pragma once
#include "AbstractFactory.h"
#include "Circle.h"
#include "Rectangle.h"
class Factory5: public AbstractFactory {
public:
	Factory5();
	virtual ~Factory5();
	virtual Figure* createProduct1();
	virtual Figura* createProduct2();
};

