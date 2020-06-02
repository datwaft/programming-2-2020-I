#include "Double.h"

Double::Double(Component* o): Decorator(o) { }

int Double::operation(int a, int b) {
	return this->component->operation(a, b) * 2;
}
