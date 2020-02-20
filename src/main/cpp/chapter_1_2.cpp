#include "chapter_1_2.h"
#include <iostream>


namespace coding_skill 
{
Chapter1_2::~Chapter1_2()
{

}

void Chapter1_2::learn()
{
    std::cout << "Chapter 1.2 learn" << std::endl;

    naming();
    shortIndexName();
    shortIndexName();


}

// 명확한 변수 이름 붙이기
void Chapter1_2::naming()
{
    // 나쁜예
    float t;

    // 좋은예
    float time;
    float limitTime;
}

// 순환 인덱스의 이름은 i, j, k 짧게 하기
void Chapter1_2::shortIndexName()
{
    // 좋은 예
    for (int i = 0; i < 4; ++i) 
    {
        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 4; ++k) 
            {

            }
        }
    }

    // 개인적으로 i, ii, iii 가 더 편하다
    for (int i = 0; i < 4; ++i) 
    {
        for (int ii = 0; ii < 4; ++ii)
        {
            for (int iii = 0; iii < 4; ++iii) 
            {

            }
        }
    }
}

// 상수에 이름 붙이기
void Chapter1_2::namingMagicNumber()
{
    // 나쁜 예
    int state = 3;
    if (state == 0)
    {

    }

    // 좋은 예
    enum State 
    {
        WALK,
        JUMP,
        ATTACK,
    };

    State state2 = WALK;
    if (state == JUMP)
    {

    }
}

}