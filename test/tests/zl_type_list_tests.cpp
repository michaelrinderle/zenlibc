#pragma once
#include "gtest/gtest.h"
#include "../../src/zl_type_list.c"

TEST(zl_type_list_tests, zl_list_init)
{
	zl_list* procs = zl_list_init(VOID_LIST_TYPE);
	EXPECT_NE(procs, nullptr);
}

TEST(zl_type_list_tests, zl_list_init_node) {

	zl_node* node = zl_list_init_node("process");
	EXPECT_NE(node, nullptr);
}

TEST(zl_type_list_tests, zl_list_append) {
	zl_list* procs = zl_list_init(VOID_LIST_TYPE);
	zl_list_append(procs, "process");
	zl_node* first = zl_list_first(procs);
	EXPECT_NE(first, nullptr);
}

TEST(zl_type_list_tests, zl_list_free) {
	zl_list* procs = zl_list_init(VOID_LIST_TYPE);
	EXPECT_TRUE(zl_list_free(procs));
}

TEST(zl_type_list_tests, zl_list_first) {
	zl_list* procs = zl_list_init(VOID_LIST_TYPE);
	zl_list_append(procs, "process");
	EXPECT_NE(zl_list_first(procs), nullptr);
}

TEST(zl_type_list_tests, zl_list_last) {
	zl_list* procs = zl_list_init(VOID_LIST_TYPE);
	zl_list_append(procs, "process");
	zl_list_append(procs, "process1");
	EXPECT_NE(zl_list_last(procs), nullptr);
}

TEST(zl_type_list_tests, zl_list_get) {
	zl_list* procs = zl_list_init(VOID_LIST_TYPE);
	zl_list_append(procs, "process");
	zl_list_append(procs, "process1");
	zl_list_append(procs, "process2");
	EXPECT_NE(zl_list_get(procs, 1), nullptr);
}

TEST(zl_type_list_tests, zl_list_insert) {
	zl_list* procs = zl_list_init(VOID_LIST_TYPE);
	zl_list_append(procs, "process");
	EXPECT_NE(zl_list_insert(procs, "process0", 0), nullptr);
}

TEST(zl_type_list_tests, zl_list_remove) {
	zl_list* procs = zl_list_init(VOID_LIST_TYPE);
	zl_list_append(procs, "process");
	zl_list_append(procs, "process1");
	zl_list_append(procs, "process2");
	EXPECT_TRUE(zl_list_remove(procs, 1));
}

TEST(zl_type_list_tests, zl_list_length) {
	zl_list* procs = zl_list_init(VOID_LIST_TYPE);
	zl_list_append(procs, "process");
	EXPECT_EQ(zl_list_length(procs), 1);
}

TEST(zl_type_list_tests, zl_list_size) {
	zl_list* procs = zl_list_init(VOID_LIST_TYPE);
	zl_list_append(procs, "process");
	uint size = zl_list_size(procs);
	EXPECT_EQ(size, 8);
}