#pragma once
#include "chapter.h"
#include "state.h"
#include "world.h"
#include "position.h"

namespace coding_skill
{

class Chapter1_3 : public Chapter
{
public:
    virtual ~Chapter1_3();
    virtual void learn();

    void useDescriptionNameVariable();
    void convertConditionalExpressionToFunction();
    bool isJump();
    bool isDamage();
    bool isDash();

    void convertConditionalExpressionToFunction2();
private:
    float speed = 0;
    float y = 0.0f;
    State state = WALK;

    World world;
    Position position;
    Position velocity;
    float deltaTime;

    void move(float deltaTime);
    float rightBorder();
    float leftBorder();

    bool isTurnLeft();
    void turnLeft();

    bool isTurnRight();
    void turnRight();
};

}