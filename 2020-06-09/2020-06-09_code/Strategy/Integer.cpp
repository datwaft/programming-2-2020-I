#include "Integer.h"

Integer::Integer(int a, int b) {
	this->a = a;
	this->b = b;
}

Integer::~Integer() {
}

int Integer::operation(Strategy* o) const {
	return o->action(a, b);
}
