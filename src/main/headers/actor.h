#pragma once

namespace coding_skill
{

class Actor
{
public:
    virtual void move() = 0;
    virtual void draw() = 0;
};

}