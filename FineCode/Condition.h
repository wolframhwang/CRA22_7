#pragma once

#include "common.h"

class Condition {
public:
    virtual bool isEqual(const Employee &employee) const = 0;
};
