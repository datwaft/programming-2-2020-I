#include "Exception.h"

Exception::Exception() noexcept {
	this->msj = "";
}

Exception::Exception(const char* msj) noexcept {
	this->msj = msj;
}

Exception::Exception(const Exception& other) noexcept {
	this->msj = other.msj;
}

Exception::~Exception() {

}

Exception& Exception::operator=(const Exception& other) noexcept {
	this->msj = other.msj;
	return *this;
}

const char* Exception::message() const noexcept {
	return this->msj;
}
