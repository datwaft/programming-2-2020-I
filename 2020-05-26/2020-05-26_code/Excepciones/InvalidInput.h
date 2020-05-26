#pragma once
#include "Exception.h"

class InvalidInput : public Exception {
public:
	InvalidInput() noexcept;
	InvalidInput(const char*) noexcept;
	InvalidInput(const InvalidInput&) noexcept;
	virtual ~InvalidInput();
	InvalidInput& operator=(const InvalidInput&) noexcept;
};
