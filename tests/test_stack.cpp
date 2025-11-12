// Copyright 2025 Marina Usova

#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"
#include "stack.h"

TEST(TestStackLib, can_create_with_init_construtor) {
	ASSERT_NO_THROW(Stack<int> stack(10));
}

TEST(TestStackLib, CanCreateWithDefaultConstructor) {
    ASSERT_NO_THROW(Stack<int> stack);
    Stack<int> stack;
    EXPECT_TRUE(stack.is_empty());
    EXPECT_EQ(stack.size(), 0);
}

TEST(TestStackLib, CopyConstructor) {
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    Stack<int> s2(s1);
    EXPECT_EQ(s2.size(), s1.size());
    EXPECT_EQ(s2.top(), s1.top());

   
    s1.pop();
    EXPECT_EQ(s2.top(), 3);
    EXPECT_EQ(s2.size(), 3);
}

TEST(TestStackLib, Push) {
    Stack<int> stack;
    stack.push(42);
    EXPECT_FALSE(stack.is_empty());
    EXPECT_EQ(stack.top(), 42);
    EXPECT_EQ(stack.size(), 1);

    stack.push(100);
    EXPECT_EQ(stack.top(), 100);
    EXPECT_EQ(stack.size(), 2);
}

TEST(TestStackLib, Pop) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(stack.top(), 3);
    stack.pop();
    EXPECT_EQ(stack.top(), 2);
    stack.pop();
    EXPECT_EQ(stack.top(), 1);
    stack.pop();
    EXPECT_TRUE(stack.is_empty());
    EXPECT_EQ(stack.size(), 0);

    EXPECT_THROW(stack.pop(), std::logic_error);
    EXPECT_THROW(stack.top(), std::logic_error);

}

TEST(TestLibStack, Clear) {
    Stack<int> stack;
    for (int i = 0; i < 5; ++i) {
        stack.push(i);
    }

    EXPECT_FALSE(stack.is_empty());
    stack.clear();
    EXPECT_TRUE(stack.is_empty());
    EXPECT_EQ(stack.size(), 0);

}

TEST(TestLibStack, AssignmentOperator) {
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);


    Stack<int> s2;
    s2 = s1;

    EXPECT_EQ(s2.size(), s1.size());
    EXPECT_EQ(s2.top(), s1.top());
}