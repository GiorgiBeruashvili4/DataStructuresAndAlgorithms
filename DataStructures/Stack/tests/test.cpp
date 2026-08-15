#include <gtest/gtest.h>
#include "stack.h"
#include <sstream>
#include <stdexcept>

TEST(StackTest, EmptyOnConstruction)
{
	dsa::Stack<int> stack;

	EXPECT_TRUE(stack.empty());
	EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, PeekIsLastInsertedElement)
{
	dsa::Stack<int> stack;

	for (int i : {10, 20, 30, 40, 50})
	{
		stack.push(i);
	}

	EXPECT_EQ(stack.peek(), 50);
}

TEST(StackTest, PushIsCorrect)
{
	dsa::Stack<int> stack;

	for (int i : {10, 20, 30, 40, 50})
	{
		stack.push(i);
	}
	
	EXPECT_EQ(stack.peek(), 50);

	stack.push(60);

	EXPECT_EQ(stack.peek(), 60);
}

TEST(StackTest, PopIsCorrect)
{
	dsa::Stack<int> stack;

	for (int i : {10, 20, 30, 40, 50})
	{
		stack.push(i);
	}

	EXPECT_EQ(stack.peek(), 50);

	stack.pop();

	EXPECT_EQ(stack.peek(), 40);
}

TEST(StackTest, CopyConstructorIsDeep)
{
	dsa::Stack<int> a;

	for (int i : {10, 20, 30, 40, 50})
	{
		a.push(i);
	}

	dsa::Stack<int> b(a);

	b.push(60);

	EXPECT_EQ(a.peek(), 50);
}

TEST(StackTest, CopyAssignmentIsDeep)
{
	dsa::Stack<int> a;
	for (int i : {10, 20, 30, 40, 50})
	{
		a.push(i);
	}

	dsa::Stack<int> b;
	b.push(100);
	b = a;

	EXPECT_EQ(b.peek(), 50);

	b.push(60);

	EXPECT_EQ(a.peek(), 50);
	EXPECT_EQ(b.peek(), 60);
}

TEST(StackTest, ClearEmptiesStack)
{
	dsa::Stack<int> stack;

	stack.push(10);
	stack.clear();

	EXPECT_TRUE(stack.empty());
}

TEST(StackTest, LifoOrderWithMixedOperations)
{
	dsa::Stack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.pop();
	stack.push(30);
	stack.push(40);
	stack.pop();

	EXPECT_EQ(stack.size(), 2);
	EXPECT_EQ(stack.peek(), 30);
}