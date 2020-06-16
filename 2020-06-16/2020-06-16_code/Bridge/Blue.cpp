#include "Blue.h"

Blue::Blue() {
}

Blue::~Blue() {
}

std::string Blue::colorize(std::string string) {
	return "\x1b[34m" + string + "\x1b[0m";
}
