#pragma once
#include "Color.h"
class Blue: public Color {
public:
	Blue();
	virtual ~Blue();
	virtual std::string colorize(std::string) override;
};

