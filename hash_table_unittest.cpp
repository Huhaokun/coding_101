//
// Created by 胡昊坤 on 17/5/30.
//

#define CATCH_CONFIG_MAIN
#include "hash_table.h"
#include "catch.h"

TEST_CASE("string based hash table ", "[hash table]") {
    StringKeyHashTable<int> table(10);
    table.Put("abc", 1);

    int one;
    REQUIRE(table.Get("abc", one));
    REQUIRE(one == 1);
}