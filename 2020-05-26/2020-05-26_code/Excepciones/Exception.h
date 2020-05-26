#pragma once

class Exception {
protected:
	const char* msj;
public:
	Exception() noexcept;
	Exception(const char*) noexcept;
	Exception(const Exception&) noexcept;
	virtual ~Exception();
	Exception& operator=(const Exception&) noexcept;
	virtual const char* message() const noexcept;
};
