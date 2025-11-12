#include "queue.h"
#include <gtest/gtest.h>

TEST(TestQueueLib, CopyConstructor) {
    Queue<int> queue(5);
    queue.push(1);
    queue.push(2);
    queue.push(7);

    Queue<int> queue2(queue);

    EXPECT_EQ(queue2.size(), 3);
    EXPECT_EQ(queue2.head(), 1);
}

TEST(TestQueueLib, DefaultConstructor) {
    ASSERT_NO_THROW(Queue<int> queue);
    Queue<int> queue;
    EXPECT_TRUE(queue.is_empty());
    EXPECT_EQ(queue.size(), 0);
}

TEST(TestQueueLib, ConstructorWithSize) {
    ASSERT_NO_THROW(Queue<int> queue(10));
    Queue<int> queue(15);
    EXPECT_TRUE(queue.is_empty());
    EXPECT_EQ(queue.size(), 0);
}

TEST(TestQueueLib, Push) {
    Queue<int> queue;
    queue.push(42);
    EXPECT_EQ(queue.head(), 42);
    EXPECT_EQ(queue.size(), 1);

    queue.push(100);
    EXPECT_EQ(queue.head(), 42);
    EXPECT_EQ(queue.size(), 2);

    Queue<int> queue2(2);
    queue2.push(1);
    queue2.push(2);
    EXPECT_THROW(queue2.push(3), std::logic_error);
}

TEST(TestQueueLib, Pop) {
    Queue<int> queue(3);
    queue.push(1);
    queue.push(2);
    queue.push(3);

    EXPECT_TRUE(queue.is_full());
    EXPECT_EQ(queue.head(), 1);
    queue.pop();
    EXPECT_EQ(queue.head(), 2);
    queue.pop();
    EXPECT_EQ(queue.head(), 3);
    queue.pop();
    EXPECT_TRUE(queue.is_empty());
    EXPECT_EQ(queue.size(), 0);

    EXPECT_THROW(queue.pop(), std::logic_error);
    EXPECT_THROW(queue.head(), std::logic_error);
}

TEST(TestQueueLib, Clear) {
    Queue<int> queue;
    for (int i = 0; i < 5; ++i) {
        queue.push(i);
    }

    EXPECT_FALSE(queue.is_empty());
    queue.clear();
    EXPECT_TRUE(queue.is_empty());
    EXPECT_EQ(queue.size(), 0);
}

TEST(TestQueueLib, AssignmentOperator) {
    Queue<int> queue1;
    queue1.push(10);
    queue1.push(20);
    queue1.push(30);

    Queue<int> queue2;
    queue2 = queue1;

    EXPECT_EQ(queue2.size(), queue1.size());
    EXPECT_EQ(queue2.head(), queue1.head());
}

TEST(TestQueueLib, MoveHead) {
    Queue<int> queue(3);
    queue.push(1);
    queue.push(2);
    queue.push(3);

    EXPECT_TRUE(queue.is_full());
    EXPECT_EQ(queue.head(), 1);
    queue.pop();
    queue.push(4);

    EXPECT_EQ(queue.head(), 2);
    EXPECT_EQ(queue.size(), 3);


}