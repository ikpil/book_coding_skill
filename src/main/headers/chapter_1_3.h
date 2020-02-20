#pragma once
#include "chapter.h"
#include "state.h"

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

private:
    float speed = 0;
    float y = 0.0f;
    State state = WALK;
};

}