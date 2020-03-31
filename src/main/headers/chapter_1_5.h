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
    int wrap(int x, int low, int high);
    float wrap(float x, float low, float high);

    void useEarlyReturn();
    bool isDead();

    int bonus(int time, int hp);
    int bonus1st(int time, int hp);

private:
    int health = 0;
    int lifeTime = 0;
};

}