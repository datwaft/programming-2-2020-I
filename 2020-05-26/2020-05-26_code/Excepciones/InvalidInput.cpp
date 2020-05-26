#include "InvalidInput.h"

InvalidInput::InvalidInput() noexcept {
	this->msj = "";
}

InvalidInput::InvalidInput(const char* msj) noexcept {
	this->msj = msj;
}

InvalidInput::InvalidInput(const InvalidInput& other) noexcept {
	this->msj = other.msj;
}

InvalidInput::~InvalidInput() {
}

InvalidInput& InvalidInput::operator=(const InvalidInput& other) noexcept {
	this->msj = other.msj;
	return *this;
}
