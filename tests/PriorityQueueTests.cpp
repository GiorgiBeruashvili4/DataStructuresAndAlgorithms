#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <functional>
#include <dsa/PriorityQueue.h>

TEST(PriorityQueueTest, EmptyOnConstruction)
{
	dsa::PriorityQueue<int> pq;

	EXPECT_TRUE(pq.empty());
	EXPECT_EQ(pq.size(), 0);
}

TEST(PriorityQueueTest, TopIsHighestPriorityElement)
{
	dsa::PriorityQueue<int> pq;
	for (int i : {5,2,4,1,3})
	{
		pq.push(i);
	}

	EXPECT_EQ(pq.top(), 5);
}

TEST(PriorityQueueTest, PushIsCorrect)
{
	dsa::PriorityQueue<int> pq;
	
	pq.push(10);
	pq.push(20);

	EXPECT_EQ(pq.top(), 20);
	EXPECT_EQ(pq.size(), 2);

	pq.push(5);

	EXPECT_EQ(pq.top(), 20);
	EXPECT_EQ(pq.size(), 3);

	pq.push(30);

	EXPECT_EQ(pq.top(), 30);
	EXPECT_EQ(pq.size(), 4);
}

TEST(PriorityQueueTest, PopIsCorrect)
{
	dsa::PriorityQueue<int> pq;
	for (int i : {10,20,30})
	{
		pq.push(i);
	}

	EXPECT_EQ(pq.top(), 30);

	pq.pop();

	EXPECT_EQ(pq.top(), 20);
	EXPECT_EQ(pq.size(), 2);
}

TEST(PriorityQueueTest, PopOnEmptyThrows)
{
	dsa::PriorityQueue<int> pq;

	EXPECT_THROW(pq.pop(), std::out_of_range);
}

TEST(PriorityQueueTest, TopOnEmptyThrows)
{
	const dsa::PriorityQueue<int> pq;

	EXPECT_THROW(pq.top(), std::out_of_range);
}

TEST(PriorityQueueTest, PriorityOrderWithMixedOperations)
{
	dsa::PriorityQueue<int> pq;

	pq.push(10);
	pq.push(20);
	pq.pop();
	pq.push(30);
	pq.push(5);
	pq.pop();

	EXPECT_EQ(pq.top(), 10);
	EXPECT_EQ(pq.size(), 2);
}

TEST(PriorityQueueTest, KeepsDescendingOrder)
{
	dsa::PriorityQueue<int> pq;
	for (int i : {15,3,27,8,42,1,99,6})
	{
		pq.push(i);
	}

	std::vector<int> result;
	while (!pq.empty())
	{
		result.push_back(pq.top());
		pq.pop();
	}

	std::vector<int> expected = {99,42,27,15,8,6,3,1};

	EXPECT_EQ(result, expected);
}

TEST(PriorityQueueTest, HandlesDuplicates)
{
	dsa::PriorityQueue<int> pq;
	for (int i : {4,4,2,2,7,7,1})
	{
		pq.push(i);
	}

	std::vector<int> result;
	while (!pq.empty())
	{
		result.push_back(pq.top());
		pq.pop();
	}

	std::vector<int> expected = {7,7,4,4,2,2,1};

	EXPECT_EQ(result, expected);
}

TEST(PriorityQueueTest, MinHeapWithGreaterComparator)
{
	dsa::PriorityQueue<int, std::greater<int>> pq;
	for (int i : {5,3,8,1,9})
	{
		pq.push(i);
	}

	EXPECT_EQ(pq.top(), 1);

	pq.pop();

	EXPECT_EQ(pq.top(), 3);
}

TEST(PriorityQueueTest, WorksWithStrings)
{
	dsa::PriorityQueue<std::string> pq;
	pq.push("banana");
	pq.push("apple");
	pq.push("cherry");

	EXPECT_EQ(pq.top(), "cherry");

	pq.pop();

	EXPECT_EQ(pq.top(), "banana");
}

struct Task
{
	std::string name;
	int priority;

	bool operator<(const Task& other) const
	{
		return priority < other.priority;
	}
};

TEST(PriorityQueueTest, WorksWithCustomTypes)
{
	dsa::PriorityQueue<Task> pq;
	pq.push({ "low", 1 });
	pq.push({ "high",10 });
	pq.push({ "medium", 5 });

	EXPECT_EQ(pq.top().name, "high");

	pq.pop();

	EXPECT_EQ(pq.top().name, "medium");
}

TEST(PriorityQueueTest, CopyConstructorIsDeep)
{
	dsa::PriorityQueue<int> a;
	for (int i : {10,30,20})
	{
		a.push(i);
	}

	dsa::PriorityQueue<int> b(a);

	b.push(40);
	b.pop();

	EXPECT_EQ(a.top(), 30);
	EXPECT_EQ(a.size(), 3);
}

TEST(PriorityQueueTest, CopyAssignmentIsDeep)
{
	dsa::PriorityQueue<int> a;
	for (int i : {10,30,20})
	{
		a.push(i);
	}

	dsa::PriorityQueue<int> b;
	b.push(100);

	b = a;

	EXPECT_EQ(b.top(), 30);
	EXPECT_EQ(b.size(), 3);

	b.push(5);
	b.pop();

	EXPECT_EQ(a.top(), 30);
	EXPECT_EQ(a.size(), 3);
	EXPECT_EQ(b.top(), 20);
}

TEST(PriorityQueueTest, SelfAssignmentIsSafe)
{
	dsa::PriorityQueue<int> a;
	a.push(10);
	a.push(20);

	a = a;

	EXPECT_EQ(a.top(), 20);
	EXPECT_EQ(a.size(), 2);
}