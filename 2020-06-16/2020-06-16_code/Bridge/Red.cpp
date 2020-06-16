#include "Red.h"

Red::Red() {
}

Red::~Red() {
}

std::string Red::colorize(std::string string) {
	return "\x1b[31m" + string + "\x1b[0m";
}
