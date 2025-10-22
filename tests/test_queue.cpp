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