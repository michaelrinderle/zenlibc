#pragma once
#include "gtest/gtest.h"

extern "C" {
#include "../../src/zl_type_hash.c"
}

TEST(zl_types_tests, zl_hash_init) {
	zl_hash* dns = zl_hash_init();

	EXPECT_NE(dns, nullptr);
}

TEST(zl_types_tests, zl_hash_append) {
	zl_hash* dns = zl_hash_init();
	zl_hash_append(dns, "test", "19.212.12.34");
	zl_hashkv* kv = zl_hash_search_key(dns, "test");

	EXPECT_EQ(0, strcmp("test", kv->key));
}

TEST(zl_types_tests, zl_hash_remove) {
	zl_hash* dns = zl_hash_init();
	zl_hash_append(dns, "test", "19.212.12.34");

	ASSERT_TRUE(zl_hash_remove(dns, "test"));
}

TEST(zl_types_tests, zl_hash_free) {
	zl_hash* dns = zl_hash_init();

	ASSERT_TRUE(zl_hash_free(dns));
}

TEST(zl_types_tests, zl_hash_key) {
	zl_hash* dns = zl_hash_init();
	zl_hash_append(dns, "test", "19.212.12.34");
	uint key = zl_hash_key("test");

	ASSERT_TRUE(key, 1);
}

TEST(zl_types_tests, zl_hash_search_key) {
	zl_hash* dns = zl_hash_init();
	zl_hash_append(dns, "test", "19.212.12.34");
	zl_hashkv* kv = zl_hash_search_key(dns, "test");

	EXPECT_EQ(0, strcmp("test", kv->key));
}