#pragma once
#include "Component.h"

class Composite: public Component {
protected:
	Component** children;
	unsigned int n;
	unsigned int k;
public:
	Composite();
	virtual ~Composite();
	void add(Component*);
	void remove(unsigned int);
	Component* getChild(unsigned int);
	virtual double area() override;
	virtual double perimetro() override;
};

