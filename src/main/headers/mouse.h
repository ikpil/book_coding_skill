#pragma once
#include "position.h"

namespace coding_skill
{

class Mouse
{
public:
    const Position& position();
    bool isLeftButtonPressed() const;

private:
    Position position_;
};

}