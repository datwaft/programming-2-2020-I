#pragma once

#include "Strategy.h"

class Integer {
private:
	int a;
	int b;
public:
	Integer(int, int);
	virtual ~Integer();
	virtual int operation(Strategy*) const;
};

