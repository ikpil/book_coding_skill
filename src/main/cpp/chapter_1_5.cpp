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

    // 최소/최대
    useMinMax();

    // 랩 어라운드
    useWrapAround();

    // 조기 리턴
    useEarlyReturn();
    
    // if ~ else 단순화
    bonus(10, 20);
    bonus1st(10, 20);

    // 중복 조건 제거
    duplicationConditionRemovalWorst();
    duplicationConditionRemovalBest();

    // 중복된 복합 조건 제거
    duplicatedComplexConditionRemovalWorst();
    duplicatedComplexConditionRemovalBest();
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

    // 좋은 예
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

void Chapter1_5::useEarlyReturn()
{
    // 조기 리턴 사용 예, 함수 일일이 만들기 귀찮아서 do ~ while 을 이용함

    // 나쁜 예,
    do {
        if (health > 0) {
            if (lifeTime > 0) {
                // 로직 처리 ...
            }
        }

    } while (false);

    // 좋은 예
    do {
        if (health <= 0)
            break;

        if (lifeTime <= 0)
            break;
        
        // 로직 처리 ...

    } while (false);

    // 더 좋은 예
    do {
        if (isDead())
            break;

        // 로직 처리 ...
    } while (false);
}

bool Chapter1_5::isDead()
{
    if (health <= 0)
        return true;

    if (lifeTime <= 0)
        return true;

    return false;
}

// 보너스 처리에 대한 안 좋은 예
int Chapter1_5::bonus(int time, int hp)
{
    // if ~ else 중첩이 많아짐에 따라 보기가 어려운 코드라고 할 수 있다.
    int result = 0;
    if (time <= 50)
    {
        if (hp >= 30)
        {
            result = 1000;
        }
        else
        {
            result = 500;
        }
    }
    else if (time <= 100)
    {
        result = 200;
    }

    return result;
}


// 보너스 처리에 대한 좋은 예
int Chapter1_5::bonus1st(int time, int hp)
{
    // if ~ else 중첩을 없앰으로써 더 보기 좋은 코드가 되었다고 평가 된다.
    if (time > 100)
    {
        return 0;
    }

    if (time > 50)
    {
        return 200;
    }

    if (time < 30)
    {
        return 500;
    }

    return 1000;
}

// 중복 조건 제거, 안좋은 예
void Chapter1_5::duplicationConditionRemovalWorst()
{
    if (state == State::STATE_FALL)
    {
        if (waitTimer > Constants::WAIT_TIME)
        {
            fall();
        }
    }
    if (state == State::STATE_MOVE)
    {
        if (waitTimer > Constants::WAIT_TIME)
        {
            move();
        }
    }
}

// 중복 조건 제거, 좋은 예
void Chapter1_5::duplicationConditionRemovalBest()
{
    // 조기 리턴으로 조건의 반대로 리턴 처리
    if (waitTimer <= Constants::WAIT_TIME)
    {
        return;
    }

    if (state == State::STATE_FALL)
    {
        fall();
    }

    if (state == State::STATE_MOVE)
    {
        move();
    }
}

// 중복된 복합 조건 제거, 안좋은 예
void Chapter1_5::duplicatedComplexConditionRemovalWorst()
{
    if (state == State::STATE_FALL && waitTimer > Constants::WAIT_TIME)
    {
        fall();
    }

    if (state == State::STATE_MOVE && waitTimer > Constants::WAIT_TIME)
    {
        move();
    }
 }

// 중복된 복합 조건 제거, 좋은 예
void Chapter1_5::duplicatedComplexConditionRemovalBest()
{
    if (waitTimer > Constants::WAIT_TIME)
    {
        if (state == State::STATE_FALL)
        {
            fall();
        }

        if (state == State::STATE_MOVE)
        {
            move();
        }
    }
}

void Chapter1_5::fall()
{

}

void Chapter1_5::move()
{

}

}