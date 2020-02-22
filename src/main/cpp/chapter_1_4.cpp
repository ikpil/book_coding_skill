#include "chapter_1_4.h"
#include <iostream>
#include <cassert>

#include "state.h"

namespace coding_skill 
{
Chapter1_4::~Chapter1_4()
{

}

void Chapter1_4::learn()
{
    std::cout << "Chapter 1.4 learn" << std::endl;

    useAssert();
}

void Chapter1_4::useAssert()
{
    static const char* name[] = {
        "Sun", "Mon", "Tue",  "Wed", "Thu", "Fri", "Sat"
    };
    int week = 1;

    // 나쁜 예,
    std::string abc = name[week];

    // 좋은 예, 범위 초과시 어설트
    //week = 7; // test code
    assert(0 <= week && week <= 6);
    std::string bcd  = name[week];

    // 좋은 예, 처리할 수 없는 상태가 왔을 때, 어설트
    State state = WALK;
    //State state = DAMAGE; // test code
    switch (state)
    {
        case WAIT: break;
        case WALK: break;
        case JUMP: break;
        default: assert(!"inaccurate state"); // 요령 앞에 ! 가 붙는다
    }

    // 주의 : 릴리즈 모드에서 fp 가 초기화 되지 않음, 왜냐하면 릴리즈에선 assert 가 제외 되기 때문
    FILE* fp;
    //assert((fp = fopen("coding_skill.exe", "r")) != NULL && "fopen error");
}
}