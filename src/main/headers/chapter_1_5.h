#pragma once
#include "chapter.h"
#include "state.h"
#include "constants.h"
#include "hand.h"
#include "rps_result.h"
#include "actor.h"
#include "button.h"
#include "mouse.h"
#include <cassert>
#include <memory>

namespace coding_skill
{

class Chapter1_5 : public Chapter
{
public:
    virtual ~Chapter1_5();
    Chapter1_5();

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

    void duplicationConditionRemovalWorst();
    void duplicationConditionRemovalBest();
    void fall();
    void move();

    void duplicatedComplexConditionRemovalWorst();
    void duplicatedComplexConditionRemovalBest();

    void conditionLocalizationWorst();
    void conditionLocalizationBest();
    bool isDash();
    float speed();

    int mappingTableWorst(int id);
    int mappingTableBest(int id);
    int mappingTableBest2(int id);

    bool mappingConditionWorst(int itemId);
    bool mappingConditionBest(int itemId);
    bool mappingConditionBest2(int itemId);

    RPSResult judgementWorst(Hand my, Hand target);
    RPSResult judgementBest(Hand my, Hand target);

    void nullObjectWorst();
    void nullObjectBest();

    void enchancedForLoop();
    void detectLoopWorst();
    void detectLoopBest();

    void separationOfUnnecessaryConditionsInsideLoopWorst();
    void separationOfUnnecessaryConditionsInsideLoopBest();
    std::shared_ptr<Button> findOverlapsButtons(const Position& position) const;

    void splitLoopWorst();
    void splitLoopBest();

private:
    int health = 0;
    int lifeTime = 0;

    State state = State::ATTACK;
    int waitTimer = 30;

    float position = 0.0f;
    int direction = 1;

    std::vector<std::shared_ptr<Actor>> actors;
    std::shared_ptr<Actor> player;

    Mouse mouse;
    std::vector<std::shared_ptr<Button>> buttons;
};

}