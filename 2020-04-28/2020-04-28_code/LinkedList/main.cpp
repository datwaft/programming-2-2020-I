#include "linkedlist.h"
#include <iostream>
#include <string>
#include <sstream>

int main() {
	LinkedList* list = new LinkedList();
	std::cin >> *list;
	std::cout << *list;
	delete list;
}

std::ostream& operator << (std::ostream& out, LinkedList& list) {
	Iterator i(&list);
	while (!i.hasFinished()) {
		out << i.getCurrent() << std::endl;
		i.goNext();
	}
	return out;
}

std::istream& operator >> (std::istream& in, LinkedList& list) {
	std::string s;
	std::getline(in, s, '\n');
	std::stringstream stream(s);
	std::string aux;
	while (std::getline(stream, aux, ' ')) {
		list.push(std::stoi(aux));
	}
	return in;
}