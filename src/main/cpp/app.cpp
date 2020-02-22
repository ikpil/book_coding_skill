/*
 * This C++ source file was generated by the Gradle 'init' task.
 */

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <memory>

#include "chapter.h"
#include "chapter_1_1.h"
#include "chapter_1_2.h"
#include "chapter_1_3.h"
#include "chapter_1_4.h"

using namespace coding_skill;

int main () {
    std::vector<std::shared_ptr<Chapter>> chapters;
    chapters.push_back(std::make_shared<Chapter1_1>());
    chapters.push_back(std::make_shared<Chapter1_2>());
    chapters.push_back(std::make_shared<Chapter1_3>());
    chapters.push_back(std::make_shared<Chapter1_4>());

    for (auto chapter : chapters)
    {
        chapter->learn();
    }
    return 0;
}
