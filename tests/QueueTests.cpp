#include <gtest/gtest.h>
#include <stdexcept>
#include <dsa/Queue.h>

TEST(QueueTest, EmptyOnConstruction)
{
	dsa::Queue<int> queue;

	EXPECT_TRUE(queue.empty());
	EXPECT_EQ(queue.size(), 0);
}

TEST(QueueTest, FrontIsFirstInsertedElement)
{
	dsa::Queue<int> queue;
	for (int i : {10, 20, 30, 40, 50})
	{
		queue.enqueue(i);
	}

	EXPECT_EQ(queue.front(), 10);
}

TEST(QueueTest, EnqueueIsCorrect)
{
	dsa::Queue<int> queue;
	
	queue.enqueue(10);
	queue.enqueue(20);

	EXPECT_EQ(queue.front(), 10);
	EXPECT_EQ(queue.size(), 2);

	queue.enqueue(30);

	EXPECT_EQ(queue.front(), 10);
	EXPECT_EQ(queue.size(), 3);
}

TEST(QueueTest, DequeueIsCorrect)
{
	dsa::Queue<int> queue;
	for (int i : {10, 20, 30})
	{
		queue.enqueue(i);
	}

	EXPECT_EQ(queue.front(), 10);

	queue.dequeue();

	EXPECT_EQ(queue.front(), 20);
	EXPECT_EQ(queue.size(), 2);
}

TEST(QueueTest, DequeueOnEmptyThrows)
{
	dsa::Queue<int> queue;

	EXPECT_THROW(queue.dequeue(), std::out_of_range);
}

TEST(QueueTest, FrontOnEmptyThrows)
{
	dsa::Queue<int> queue;

	EXPECT_THROW(queue.front(), std::out_of_range);
}

TEST(QueueTest, ConstFrontOnEmptyThrows)
{
	const dsa::Queue<int> queue;

	EXPECT_THROW(queue.front(), std::out_of_range);
}

TEST(QueueTest, DequeueThenEnqueue)
{
	dsa::Queue<int> queue;

	queue.enqueue(10);
	queue.dequeue();

	EXPECT_TRUE(queue.empty());
	EXPECT_EQ(queue.size(), 0);

	queue.enqueue(20);

	EXPECT_FALSE(queue.empty());
	EXPECT_EQ(queue.front(), 20);
}

TEST(QueueTest, FifoOrderWithMixedOperations)
{
	dsa::Queue<int> queue;

	queue.enqueue(10);
	queue.enqueue(20);
	queue.dequeue();
	queue.enqueue(30);
	queue.enqueue(40);
	queue.dequeue();

	EXPECT_EQ(queue.size(), 2);
	EXPECT_EQ(queue.front(), 30);
}

TEST(QueueTest, CopyConstructorIsDeep)
{
	dsa::Queue<int> a;

	for (int i : {10, 20, 30})
	{
		a.enqueue(i);
	}

	dsa::Queue<int> b(a);

	b.enqueue(40);
	b.dequeue();

	EXPECT_EQ(a.front(), 10);
	EXPECT_EQ(a.size(), 3);
}

TEST(QueueTest, CopyAssignmentIsDeep)
{
	dsa::Queue<int> a;
	for (int i : {10, 20, 30})
	{
		a.enqueue(i);
	}

	dsa::Queue<int> b;
	b.enqueue(100);

	b = a;

	EXPECT_EQ(b.front(), 10);
	EXPECT_EQ(b.size(), 3);

	b.enqueue(40);
	b.dequeue();

	EXPECT_EQ(a.front(), 10);
	EXPECT_EQ(a.size(), 3);
	EXPECT_EQ(b.front(), 20);
}

TEST(QueueTest, SelfAssignmentIsSafe)
{
	dsa::Queue<int> a;
	a.enqueue(10);
	a.enqueue(20);

	a = a;

	EXPECT_EQ(a.front(), 10);
	EXPECT_EQ(a.size(), 2);
}

TEST(QueueTest, ClearEmptiesQueue)
{
	dsa::Queue<int> queue;

	queue.enqueue(10);
	queue.clear();

	EXPECT_TRUE(queue.empty());
	EXPECT_EQ(queue.size(), 0);
}

TEST(QueueTest, ClearOnEmptyQueueIsSafe)
{
	dsa::Queue<int> queue;
	queue.clear();

	EXPECT_TRUE(queue.empty());
}