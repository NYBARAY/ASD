#include "stack_list.h"
#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"

TEST(TestStackListLib, can_create_with_init_construtor) {
    ASSERT_NO_THROW(StackList<int> stack);
}

TEST(TestStackListLib, CanCreateWithDefaultConstructor) {
    ASSERT_NO_THROW(StackList<int> stack);
    StackList<int> stack;
    EXPECT_TRUE(stack.is_empty());
    EXPECT_EQ(stack.size(), 0);
}

TEST(TestStackListLib, CopyConstructor) {
    StackList<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    StackList<int> s2(s1);
    EXPECT_EQ(s2.size(), s1.size());
    EXPECT_EQ(s2.top(), s1.top());


    s1.pop();
    EXPECT_EQ(s2.top(), 3);
    EXPECT_EQ(s2.size(), 3);
}

TEST(TestStackListLib, Push) {
    StackList<int> stack;
    stack.push(42);
    EXPECT_FALSE(stack.is_empty());
    EXPECT_EQ(stack.top(), 42);
    EXPECT_EQ(stack.size(), 1);

    stack.push(100);
    EXPECT_EQ(stack.top(), 100);
    EXPECT_EQ(stack.size(), 2);
}

TEST(TestStackListLib, Pop) {
    StackList<int> stack;
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

TEST(TestStackListLib, Clear) {
    StackList<int> stack;
    for (int i = 0; i < 5; ++i) {
        stack.push(i);
    }

    EXPECT_FALSE(stack.is_empty());
    stack.clear();
    EXPECT_TRUE(stack.is_empty());
    EXPECT_EQ(stack.size(), 0);

}

TEST(TestStackListLib, AssignmentOperator) {
    StackList<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);


    StackList<int> s2;
    s2 = s1;

    EXPECT_EQ(s2.size(), s1.size());
    EXPECT_EQ(s2.top(), s1.top());
}