#pragma once

#include <string>
#include <iostream>
#include "Observer.h"

class ConcreteObserver: public Observer {
private:
	std::string nombre;
public:
	ConcreteObserver(std::string nombre);
	virtual ~ConcreteObserver();
	virtual void update(Subject*) override;
};

