#pragma once
#include "position.h"

namespace coding_skill
{

class Mouse
{
public:
    const Position& position();

private:
    Position position_;
};

}