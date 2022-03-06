#pragma once

#include "Employee.h"

class Condition {
public:
    virtual bool isEqual(const Employee &employee) const = 0;
    virtual void set(Employee& employee) const = 0;
};