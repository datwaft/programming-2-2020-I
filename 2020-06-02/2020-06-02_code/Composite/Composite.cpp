#include "Composite.h"

Composite::Composite() {
	this->n = 30;
	this->k = 0;
	this->children = new Component*[this->n];
}

Composite::~Composite() {
	delete[] this->children;
}

void Composite::add(Component* o) {
	if (this->k < this->n)
		this->children[this->k++] = o;
}

void Composite::remove(unsigned int index) {
	if (index >= k)
		throw "nope";
	this->k--;
	for (unsigned int i = index; i < k; ++i) {
		this->children[i] = this->children[i + 1];
	}
	this->children[k] = nullptr;
}

Component* Composite::getChild(unsigned int index) {
	if (index >= k)
		throw "nope";
	return this->children[index];
}

double Composite::area() {
	double acc = 0;
	for (unsigned int i = 0; i < this->k; ++i) {
		acc += this->children[i]->area();
	}
	return acc;
}

double Composite::perimetro() {
	double acc = 0;
	for (unsigned int i = 0; i < this->k; ++i) {
		acc += this->children[i]->perimetro();
	}
	return acc;
}
