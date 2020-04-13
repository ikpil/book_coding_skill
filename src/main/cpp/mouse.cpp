#include "mouse.h"

namespace coding_skill
{

const Position& Mouse::position()
{
    return position_;
}

bool Mouse::isLeftButtonPressed() const
{
    return true;
}

}
