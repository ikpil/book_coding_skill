#pragma once

namespace coding_skill
{

class Position
{
public:
    Position()
    {
        this->x = 0.0f;
        this->y = 0.0f;
    }

    Position(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

public:
    float x;
    float y;
};

}