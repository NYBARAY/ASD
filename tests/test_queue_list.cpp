#include "queue_list.h"
#include <gtest/gtest.h>

TEST(TestQueueListLib, CopyConstructor) {
    QueueList<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(7);

    QueueList<int> queue2(queue);

    EXPECT_EQ(queue2.size(), 3);
    EXPECT_EQ(queue2.head(), 1);
}

TEST(TestQueueListLib, DefaultConstructor) {
    ASSERT_NO_THROW(QueueList<int> queue);
    QueueList<int> queue;
    EXPECT_TRUE(queue.is_empty());
    EXPECT_EQ(queue.size(), 0);
}

//TEST(TestQueueListLib, ConstructorWithSize) {
//    ASSERT_NO_THROW(Queue<int> queueList(10));
//    QueueList<int> queue(15);
//    EXPECT_TRUE(queue.is_empty());
//    EXPECT_EQ(queue.size(), 0);
//}

TEST(TestQueueListLib, Push) {
    QueueList<int> queue;
    queue.push(42);
    EXPECT_EQ(queue.head(), 42);
    EXPECT_EQ(queue.size(), 1);

    queue.push(100);
    EXPECT_EQ(queue.head(), 42);
    EXPECT_EQ(queue.size(), 2);

    QueueList<int> queue2;
    queue2.push(1);
    queue2.push(2);
}

TEST(TestQueueListLib, Pop) {
    QueueList<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    
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

TEST(TestQueueListLib, Clear) {
    QueueList<int> queue;
    for (int i = 0; i < 5; ++i) {
        queue.push(i);
    }

    EXPECT_FALSE(queue.is_empty());
    queue.clear();
    EXPECT_TRUE(queue.is_empty());
    EXPECT_EQ(queue.size(), 0);
}

TEST(TestQueueListLib, AssignmentOperator) {
    QueueList<int> queue1;
    queue1.push(10);
    queue1.push(20);
    queue1.push(30);

    QueueList<int> queue2;
    queue2 = queue1;

    EXPECT_EQ(queue2.size(), queue1.size());
    EXPECT_EQ(queue2.head(), queue1.head());
}

TEST(TestQueueListLib, MoveHead) {
    QueueList<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    EXPECT_EQ(queue.head(), 1);
    queue.pop();
    queue.push(4);

    EXPECT_EQ(queue.head(), 2);
    EXPECT_EQ(queue.size(), 3);


}