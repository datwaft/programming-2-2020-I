#pragma once

#include "Subject.h"

class Subject;

class Observer {
public:
	virtual ~Observer() = default;
	virtual void update(Subject*) = 0;
};

