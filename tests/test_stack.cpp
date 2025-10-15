// Copyright 2025 Marina Usova
#include "stack.h"
#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"

TEST(TestStackLib, can_create_with_init_construtor) {
	ASSERT_NO_THROW(Stack<int> stack(10));
}

TEST(TestStackLib, CopyConstructor) {
	Stack<int> stack(5);
	stack.push(1);
	stack.push(2);
	stack.push(7);

	Stack<int> stack2(stack);

	EXPECT_EQ(stack2.size(), 3);
	EXPECT_EQ(stack2.top(), 7);

}

TEST(TestStackLib, AssignmentOperator) {
	Stack<int> stack(6);
	stack.push(5);
	stack.push(6);

	Stack<int> stack2(9);
	stack2 = stack;

	EXPECT_EQ(stack2.top(), 6);
	EXPECT_EQ(stack2.size(), 2);
}

TEST(TestStackLib, pop) {
	Stack<int> stack(5);
	stack.push(42);
	stack.push(0);
	stack.push(99);
	stack.pop();

	EXPECT_EQ(stack.size(), 2);
	EXPECT_EQ(stack.top(), 0);


}

TEST(TestStackLib, IsEmpty) {
	Stack<int> stack(5);
	EXPECT_TRUE(stack.is_empty());

	Stack<int> stack2(6);
	stack2.push(99);
	EXPECT_FALSE(stack2.is_empty());

	Stack<int> stack3(10);
	stack3 = stack2;
	stack3.pop();
	EXPECT_TRUE(stack3.is_empty());
	EXPECT_THROW(stack3.pop(), std::logic_error);
}

TEST(TestStackLib, IsFull) {
	Stack<int> stack(3);
	EXPECT_FALSE(stack.is_full());

	Stack<int> stack2(2);
	stack2.push(9);
	stack2.push(3);
	EXPECT_TRUE(stack2.is_full());

}

TEST(TestStackLib, Clear) {
	Stack<int> stack(5);
	stack.push(1);
	stack.push(11);
	stack.push(111);
	stack.clear();

	EXPECT_TRUE(stack.is_empty());
	EXPECT_EQ(stack.size(), 0);
	EXPECT_THROW(stack.top(), std::logic_error);
}