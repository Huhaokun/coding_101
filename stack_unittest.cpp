//
// Created by 胡昊坤 on 17/5/28.
//

#define CATCH_CONFIG_MAIN
#include "Stack.h"
#include "catch.h"

TEST_CASE("type int stack ", "[stack]") {
    Stack<int> intStack;

    for (int i = 0; i < 10; i++) {
        intStack.Push(i);
    }

    for (int i = 9; i < 0; i++) {
        int tmp;
        intStack.Pop(tmp);
        REQUIRE(tmp == i);
    }
}