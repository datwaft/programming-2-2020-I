#pragma once

class Component {
public:
	virtual ~Component() = default;
	virtual int operation(int, int) = 0;
};
