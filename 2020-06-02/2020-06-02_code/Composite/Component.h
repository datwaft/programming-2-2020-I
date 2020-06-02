#pragma once

class Component {
public:
	virtual ~Component() = default;
	virtual double area() = 0;
	virtual double perimetro() = 0;
};
