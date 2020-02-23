#pragma once
#include "chapter.h"
#include <cassert>

namespace coding_skill
{

class Chapter1_5 : public Chapter
{
public:
    virtual ~Chapter1_5();
    virtual void learn();

    void useMinMax();

    template <typename T>
    T clamp(T x, T low, T high)
    {
        assert(low <= high);
        return std::min(std::max(x, low), high);
    }

    void useWrapAround();
};

}