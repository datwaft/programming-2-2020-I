#pragma once
#include "Strategy.h"
class Suma: public Strategy {
public:
	Suma();
	virtual ~Suma();
	virtual int action(int, int) override;
};

