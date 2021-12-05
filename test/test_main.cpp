#pragma once
#include "gtest/gtest.h"
#include "tests/zl_type_hash_tests.cpp"
#include "tests/zl_type_list_tests.cpp"

int
main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}