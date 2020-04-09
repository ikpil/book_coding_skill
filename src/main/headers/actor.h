#pragma once
#include "position.h"

namespace coding_skill
{

class Actor
{
public:
    virtual void move() = 0;
    virtual void draw() = 0;
    virtual float distance(Position position) = 0;
};

}