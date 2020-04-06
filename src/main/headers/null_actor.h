#pragma once

#include "actor.h"

namespace coding_skill
{

class NullActor : public Actor
{
public:
    virtual void move() override; 
    virtual void draw() override; 
};

}