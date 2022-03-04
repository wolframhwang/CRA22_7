#pragma once

#include "common.h"
#include <memory>

class Condition;
using ConditionPtr = shared_ptr<Condition>;

class Condition {
public:
    static ConditionPtr make(const string &type, const string &value);

    virtual bool isEqual(const Employee &employee) const = 0;
    virtual void set(Employee& employee) const = 0;
};
