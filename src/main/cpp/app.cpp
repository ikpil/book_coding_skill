/*
 * This C++ source file was generated by the Gradle 'init' task.
 */

#include <iostream>
#include <stdlib.h>
#include "app.h"

std::string coding_skill::Greeter::greeting() {
    return std::string("Hello, World!");
}

int main () {
    coding_skill::Greeter greeter;
    std::cout << greeter.greeting() << std::endl;
    return 0;
}