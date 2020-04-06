#include <iostream>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

#include "chapter_1_5.h"
#include "null_actor.h"


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

    // 조건식 국소화
    conditionLocalizationWorst();
    conditionLocalizationBest();

    // 매핑 테이블 기법
    mappingTableWorst(1);
    mappingTableBest(2);
    mappingTableBest2(3);

    // 매핑 조건
    mappingConditionWorst(2);
    mappingConditionBest(3);
    mappingConditionBest2(1);

    judgementWorst(Hand::Paper, Hand::Paper);
    judgementBest(Hand::Rock, Hand::Paper);

    nullObjectWorst();
    nullObjectBest();
}

void Chapter1_5::useMinMax()
{
    // 나쁜 예. 상한값
    int x = 11;
    if (x > 10)
    {
        x = 10;
    }

    // 좋은 예
    x = std::min(x, 10);

    // 나쁜 예, 하한값
    if (x < 0)
    {
        x = 0;
    }

    // 좋은 예
    x = std::max(x - 1, 0);

    // 나쁜 예, 상/하한 값
    if (x > 10)
    {
        x = 10;
    }
    else if (x < 0)
    {
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
    if (x >= 10)
    {
        x = 0;
    }
    else if (x < 0)
    {
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
    do
    {
        if (health > 0)
        {
            if (lifeTime > 0)
            {
                // 로직 처리 ...
            }
        }

    } while (false);

    // 좋은 예
    do
    {
        if (health <= 0)
            break;

        if (lifeTime <= 0)
            break;

        // 로직 처리 ...

    } while (false);

    // 더 좋은 예
    do
    {
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

// 조건식 국소화, 안좋은 예
void Chapter1_5::conditionLocalizationWorst()
{
    if (isDash())
    {
        position += direction * 10.0f;
    }
    else
    {
        position += direction * 5.0f;
    }
}

// 조건식 국소화, 좋은 예
void Chapter1_5::conditionLocalizationBest()
{
    // 1차, 안 좋은 예에서 계산식이 두개로 되어 있기 때문에, 한개로 변경한 상태
    {
        float speed = 5.0f;
        if (isDash())
        {
            speed = 10.0f;
        }
        position += direction * speed;
    }

    // 2차, 좋은예, 스피드 계산이 조건식이므로, 스피드 조건식을 국소화해서, 계산식을 만든다
    position += direction * speed();
}

float Chapter1_5::speed()
{
    return isDash() ? Constants::SPEED_DASH : Constants::SPEED_NORMAL;
}

bool Chapter1_5::isDash()
{
    return true;
}

// 매핑 테이블 기법, 안좋은 예
int Chapter1_5::mappingTableWorst(int id)
{
    if (id == 0)
        return 10;
    if (id == 1)
        return 15;
    if (id == 2)
        return 30;
    if (id == 3)
        return 50;

    return 0;
}

// 매핑 테이블 기법, 좋은 예
int Chapter1_5::mappingTableBest(int id)
{
    static const int table[] = {10, 15, 30, 50};
    return table[id];
}

// 매핑 테이블 기법, 배열이 아닌 자료구조로 사용한 예
int Chapter1_5::mappingTableBest2(int id)
{
    static const std::unordered_map<int, int> table = {
        {0, 10}, {1, 15}, {2, 30}, {3, 50}};
    return table.at(id);
}


// 매핑 조건 기법, 나쁜 예
bool Chapter1_5::mappingConditionWorst(int itemId)
{
    return (itemId == Constants::SWORD) || (itemId == Constants::SPEAR) || (itemId == Constants::KNIFE);
}

// 매핑 조건 기법, 좋은 예, 조건 대상을 배열화
bool Chapter1_5::mappingConditionBest(int itemId)
{
    static const int weapons[] = { 
        Constants::SWORD, 
        Constants::SPEAR, 
        Constants::KNIFE 
    };

    return std::find(&weapons[0], &weapons[3], itemId) != &weapons[3];
}

// 매핑 조건 기법, 좋은 예, 조건 대상을 자료구조화
bool Chapter1_5::mappingConditionBest2(int itemId)
{
    static const std::unordered_set<int> weapons = { 
        Constants::SWORD, 
        Constants::SPEAR, 
        Constants::KNIFE 
    };

    return weapons.find(itemId) != weapons.end();
}

// 결정표 기법, Decision table, 나쁜 예, 모두 if 로 조건 체크 해야 해서 복잡해 진다.
RPSResult Chapter1_5::judgementWorst(Hand my, Hand target)
{
    if (my == target) return RPSResult::Draw;
    if (my == Hand::Rock && target == Hand::Scissors) return RPSResult::Win;
    if (my == Hand::Scissors&& target == Hand::Paper) return RPSResult::Win;
    if (my == Hand::Paper&& target == Hand::Rock) return RPSResult::Win;

    return RPSResult::Lose;
}

// 결정표 기법, Decision table, 좋은 예, 태이블만 보면 된다, 단점으로는 결정표가 크면 클 수록 이것도 복잡해 진다.
RPSResult Chapter1_5::judgementBest(Hand my, Hand target)
{
    static const RPSResult results[3][3] = {
        { RPSResult::Draw, RPSResult::Win, RPSResult::Lose, },
        { RPSResult::Lose, RPSResult::Draw, RPSResult::Win, },
        { RPSResult::Draw, RPSResult::Lose, RPSResult::Win, },
    };

    return results[my][target];
}

// 널 오브젝트 패턴, 나쁜 예, 널인지를 항상 체크해야 한다
void Chapter1_5::nullObjectWorst()
{
    if (nullptr != player)
    {
        // 플레이어에 관한 이동 체크 하고
        // ...
        player->move();
    }

    if (nullptr != player)
    {
        // 플레이어에 대한 그리기 체크 하고
        // ...
        player->draw();
    }
}

// 널 오브젝트 패턴, 좋은 예, 객체가 널일 수 없기 때문에, 체크하지 않아도 된다
void Chapter1_5::nullObjectBest()
{
    player = std::make_shared<NullActor>();

    // 플레이어에 관한 이동 체크 하고
    // 플레이어에 대한 그리기 체크 하고
    player->move();
    player->draw();
}

} // namespace coding_skill