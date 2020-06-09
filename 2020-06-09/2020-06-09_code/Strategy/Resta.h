#pragma once

#include "Strategy.h"

class Resta: public Strategy {
public:
	Resta();
	virtual ~Resta();
	virtual int action(int, int) override;
};

