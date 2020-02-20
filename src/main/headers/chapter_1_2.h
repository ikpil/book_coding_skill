#pragma once
#include "chapter.h"

namespace coding_skill
{

class Chapter1_2 : public Chapter
{
public:
    virtual ~Chapter1_2();
    virtual void learn();

    void naming();
    void shortIndexName();
    void namingMagicNumber();
};

}