#pragma once

namespace coding_skill
{

class Chapter
{
public:
    virtual ~Chapter();
    Chapter();

    virtual void learn() = 0;
};

}