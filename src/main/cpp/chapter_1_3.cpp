#include <iostream>
#include "chapter_1_3.h"
#include "constrants.h"

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
    convertConditionalExpressionToFunction2();
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

void Chapter1_3::convertConditionalExpressionToFunction2()
{
    // 나쁜 예, 이유 계산식이 로직과 붙어 있어 의미 파악하기 힘듬
    position.x += velocity.x * deltaTime;
    if (position.x > world.getWidth() - Constrants::ACTOR_WIDTH / 2.0f)
    {
        position.x = world.getWidth() - Constrants::ACTOR_WIDTH / 2.0f;
        velocity.x = -Constrants::ACTOR_SPEED;
    }

    if (position.x < Constrants::ACTOR_WIDTH / 2.0f)
    {
        position.x = Constrants::ACTOR_WIDTH / 2.0f;
        velocity.x = Constrants::ACTOR_SPEED;
    }


    // 좋은 예, 함수 이름으로 코드 설명이 되기 때문에
    move(deltaTime);
    if (isTurnLeft())
    {
        turnLeft();
    }

    if (isTurnRight()) 
    {
        turnRight();
    }
}

void Chapter1_3::move(float deltaTime)
{
    position.x += velocity.x * deltaTime;
}

float Chapter1_3::rightBorder()
{
    return world.getWidth() - Constrants::ACTOR_WIDTH / 2.0f;
}

float Chapter1_3::leftBorder()
{
    return Constrants::ACTOR_WIDTH / 2.0f;
}

bool Chapter1_3::isTurnLeft()
{
    return position.x > rightBorder();
}

void Chapter1_3::turnLeft()
{
    position.x = leftBorder();
    velocity.x = Constrants::ACTOR_SPEED;
}

bool Chapter1_3::isTurnRight()
{
    return position.x < leftBorder();
}

void Chapter1_3::turnRight()
{
    position.x = rightBorder();
    velocity.x = Constrants::ACTOR_SPEED;
}

}