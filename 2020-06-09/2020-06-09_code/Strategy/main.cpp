#include <iostream>
#include "Strategy.h"
#include "Suma.h"
#include "Resta.h"
#include "Integer.h"


int main() {
	Strategy* s1 = new Suma();
	Strategy* s2 = new Resta();
	Integer* i = new Integer(9, 4);
	std::cout << i->operation(s1) << std::endl;
	std::cout << i->operation(s2) << std::endl;
}