#pragma once
#include "Decorator.h"

class Double: public Decorator {
public:
	Double(Component*);
	~Double() = default;
	virtual int operation(int, int) override;
};
