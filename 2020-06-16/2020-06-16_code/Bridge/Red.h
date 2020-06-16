#pragma once
#include "Color.h"
class Red: public Color {
public:
	Red();
	virtual ~Red();
	virtual std::string colorize(std::string) override;
};

