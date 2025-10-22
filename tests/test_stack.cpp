// Copyright 2025 Marina Usova

#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"
#include "stack.h"

TEST(TestStackLib, can_create_with_init_construtor) {
	ASSERT_NO_THROW(Stack<int> stack(10));
}