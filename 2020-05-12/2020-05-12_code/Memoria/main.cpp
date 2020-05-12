#include <iostream>
#include <string>

enum MyEnum
{
	MAYUS = (1 << 0),
	FG = (1 << 1)
};

const int MAYUS = (1 << 0);
const int FG = (1 << 1);
const int BG = (1 << 2);

void print(int x) {
	std::string s = "hola mundo";
	if (x & MAYUS)
		return;
	if (x & MAYUS && x & FG)
		return;
}

print(MAYUS | FG);

int main() {
	std::string* s1 = new std::string;
	std::string** ss1 = &s1;
	std::string*** sss1 = &ss1;
	std::string* s2 = nullptr;
	int* i1 = new int;
	int* i2 = NULL;
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "&s1: " << &s1 << std::endl;
	std::cout << "ss1: " << ss1 << std::endl;
	std::cout << "&ss1: " << &ss1 << std::endl;
	std::cout << "sss1: " << sss1 << std::endl;
	std::cout << "s2: " << s2 << std::endl;
	std::cout << "i1: " << i1 << std::endl;
	std::cout << "i2: " << i2 << std::endl;
}