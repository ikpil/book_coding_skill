#include "null_actor.h"

namespace coding_skill
{

void NullActor::move()
{

}

void NullActor::draw()
{

}

float NullActor::distance(Position position)
{
    float x = this->position.x - position.x;
    float y = this->position.y - position.y;

    return x + y;
}

} 
