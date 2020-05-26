#include <string>
#include <iostream>

class Matrix {
public:
	int height;
	int width;
	std::string** data;
public:
	Matrix(int h, int w) {
		this->height = h;
		this->width = w;
		this->data = new std::string*[this->height];
		for (int i = 0; i < this->height; ++i) {
			this->data[i] = new std::string[this->width];
		}
	}
	~Matrix() {
		for (int i = 0; i < this->height; ++i) {
			delete this->data[i];
		}
		delete[] this->data;
	}
	std::string& get(int r, int c) {
		return this->data[r][c];
	}
};

class Iterator {
private:
	int r;
	int c;
	Matrix* data;
public:
	Iterator(Matrix* data) {
		this->r = 0;
		this->c = 0;
		this->data = data;
	}
	bool hayMas() const {
		return r != this->data->height;
	}
	std::string& actual() {
		return this->data->get(r, c);
	}
	void next() {
		if (++c == this->data->width) {
			c = 0;
			r += 1;
		}
	}
};

int main() {
	Matrix* data = new Matrix(5, 5);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			data->get(i, j) = "8";
		}
	}
	std::cout << data->height << std::endl;
	std::cout << data->width << std::endl;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			std::cout << data->get(i, j) << " ";
		}
		std::cout << std::endl;
	}
	Iterator i(data);
	for (; i.hayMas(); i.next()) {
		std::cout << i.actual();
	}
}