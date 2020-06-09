#pragma once

#include <iostream>
#include <vector>

class Data {
protected:
	std::vector<int> numeros;
	//-------------------------
	Data();
	static Data* instance;
public:
	std::vector<int> getNumeros() const;
	// ------------------------
	virtual ~Data();
	static Data* getInstance();
};
