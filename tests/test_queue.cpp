// Copyright 2025 Marina Usova
#include "queue.h"
#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"

TEST(TestQueueLib, CanCreateWithDefaultConstructor) {
	Queue<int> q;

	EXPECT_TRUE(q.is_empty());
	EXPECT_EQ(q.size(), 0);
}

TEST(TestQueueLib, CanCreateWithInitConstructor) {
	Queue<int> q(5);
	EXPECT_EQ(q.size(), 0);
	EXPECT_FALSE(q.is_full());
}

TEST(TestQueueLib, CopyConstructor) {
	Queue<int> q1(7);
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(5);
	EXPECT_EQ(q1.size(), 4);
	EXPECT_EQ(q1.head(), 1);
	Queue<int> q2(q1);
	EXPECT_EQ(q2.size(), 4);
	EXPECT_EQ(q2.head(), 1);
}

TEST(TestQueueLib, POP) {
	Queue<int> q1(7);
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(5);

	q1.pop();
	EXPECT_EQ(q1.size(), 3);
	EXPECT_EQ(q1.head(), 2);
}


TEST(TestQueueLib, Clear) {
	Queue<int> q1(7);
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(5);

	q1.clear();
	EXPECT_TRUE(q1.is_empty());
}


TEST(TestQueueLib, MoveHead) {
	Queue<int> q(3);

	q.push(1);
	q.push(2);
	q.push(3);

	EXPECT_EQ(q.head(), 1);
	q.pop();
	q.push(6);
	EXPECT_EQ(q.head(), 2);
	q.pop();
	q.pop();
	EXPECT_EQ(q.head(), 4);
}


TEST(TestQueueLib, PopEmptyQueue) {
	Queue<int> q(1);
	q.push(1);
	EXPECT_TRUE(q.is_full());
	q.pop();
	EXPECT_TRUE(q.is_empty());
	EXPECT_THROW(q.pop(), std::logic_error);

	EXPECT_THROW(q.head(), std::logic_error);
	
}

TEST(TestQueueLib, PushFullQueue) {
	Queue<int> q(2);
	q.push(1);
	q.push(2);

	EXPECT_TRUE(q.is_full());

	EXPECT_THROW(q.push(3), std::logic_error);
}

TEST(TestQueueLib, Operations) {
	Queue<int> q(4);
	q.push(1);
	q.push(2);
	q.pop();
	q.push(3);
	q.push(4);
	q.pop();
	q.push(5);
	q.push(6);
	
	EXPECT_EQ(q.size(), 4);
	EXPECT_EQ(q.head(), 3);
}