#pragma once
#include "Product1.h"
#include "Product2.h"
class AbstractFactory {
public:
	virtual Figure* createProduct1() = 0;
	virtual Figura* createProduct2() = 0;
};

