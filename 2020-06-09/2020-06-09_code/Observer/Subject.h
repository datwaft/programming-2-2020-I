#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "Observer.h"

class Observer;

class Subject {
private:
	std::string nombre;
	// -------------------------
	std::vector<Observer*> observers;
public:
	std::string getNombre() const;
	void setNombre(std::string);
	// -------------------------
	Subject(std::string);
	virtual ~Subject();
	void addObserver(Observer*);
	void removeObserver(Observer*);
	void notify();
};

