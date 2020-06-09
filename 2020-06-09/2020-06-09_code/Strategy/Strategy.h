#pragma once
class Strategy {
public:
	virtual ~Strategy() = default;
	virtual int action(int, int) = 0;
};

