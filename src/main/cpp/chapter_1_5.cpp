#include "chapter_1_5.h"
#include <iostream>
#include <algorithm>
#include <cassert>

namespace coding_skill 
{
Chapter1_5::~Chapter1_5()
{

}

void Chapter1_5::learn()
{
    std::cout << "Chapter 1.5 learn " << std::endl;

    useMinMax();
    useWrapAround();
}

void Chapter1_5::useMinMax()
{
    // 나쁜 예. 상한값
    int x = 11;
    if (x > 10) {
        x = 10;
    }

    // 좋은 예
    x = std::min(x, 10);


    // 나쁜 예, 하한값
    if (x < 0) {
        x = 0;
    }

    // 좋은 예
    x = std::max(x - 1, 0);


    // 나쁜 예, 상/하한 값
    if (x > 10) {
        x = 10;
    } else if (x < 0) {
        x = 0;
    }

    // 좋은 예
    x = std::min(std::max(x, 0), 10);

    // 더 좋은 예
    x = clamp(x, 0, 10);
}

void Chapter1_5::useWrapAround()
{
    int x = 10;

    // 나쁜 예
    if (x >= 10) {
        x = 0;
    } else if (x < 0) {
        x = 9;
    }

    x = wrap(x, 0, 10);
}

int Chapter1_5::wrap(int x, int low, int high)
{
    assert(low < high);
    const int n = (x - low) % (high - low);
    return (n >= 0) ? (n + low) : (n + high);
}

float Chapter1_5::wrap(float x, float low, float high)
{
    assert(low < high);
    const float n = std::fmod(x - low, high - low);
    return (n >= 0) ? (n + low) : (n + high);
}

}