#include <iostream>
#include "chapter_1_3.h"

namespace coding_skill 
{
Chapter1_3::~Chapter1_3()
{

}

void Chapter1_3::learn()
{
    std::cout << "Chapter 1.3 learn" << std::endl;

    useDescriptionNameVariable();
    convertConditionalExpressionToFunction();
}

// 설명 전용 함수 사용
void Chapter1_3::useDescriptionNameVariable()
{
    // 나쁜 예
    if (speed >= 5.0f && !(y > 2.0f) && state != DAMAGE)
    {
        // 생략
    }

    // 좋은 예
    const bool isJump = y > 2.0f;
    const bool isDamage = state == DAMAGE;
    const bool isDash = (speed >= 10.0f) && !isJump && !isDamage;

    if (isDash)
    {
        // 생략
    }
}

// 조건식을 함수화 해서 사용해라
void Chapter1_3::convertConditionalExpressionToFunction()
{
    isJump();
    isDamage();
    isDash();
}

bool Chapter1_3::isJump()
{
    return y > 2.0f;
}

bool Chapter1_3::isDamage()
{
    return state == DAMAGE;
}

bool Chapter1_3::isDash()
{
    if (isJump()) return false;
    if (isDamage()) return false;
    if (speed < 10.0f) return false;

    return true;
}

}