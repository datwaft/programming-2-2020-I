#pragma once
#include <string>
class Color {
public:
	virtual ~Color() = default;
	virtual std::string colorize(std::string) = 0;
};

