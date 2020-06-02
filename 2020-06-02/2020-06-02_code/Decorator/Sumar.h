#pragma once
#include "Component.h"
class Sumar: public Component {
public:
	virtual ~Sumar() = default;
	virtual int operation(int, int) override;
};

