#include <gtest/gtest.h>
#include "stack.h"
#include <sstream>
#include <stdexcept>

TEST(StackTest, EmptyOnConstruction)
{
	Stack<int> stack;

	EXPECT_TRUE(stack.empty());
	EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, PeekIsLastInsertedElement)
{
	Stack<int> stack;

	for (int i : {10, 20, 30, 40, 50})
	{
		stack.push(i);
	}

	EXPECT_EQ(stack.peek(), 50);
}

TEST(StackTest, PushIsCorrect)
{
	Stack<int> stack;

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
	Stack<int> stack;

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
	Stack<int> a;

	for (int i : {10, 20, 30, 40, 50})
	{
		a.push(i);
	}

	Stack<int> b(a);

	b.push(60);

	EXPECT_EQ(a.peek(), 50);
}

TEST(StackTest, CopyAssignmentIsDeep)
{
	Stack<int> a;
	for (int i : {10, 20, 30, 40, 50})
	{
		a.push(i);
	}

	Stack<int> b;
	b.push(100);
	b = a;

	EXPECT_EQ(b.peek(), 50);

	b.push(60);

	EXPECT_EQ(a.peek(), 50);
	EXPECT_EQ(b.peek(), 60);
}

TEST(StackTest, ClearEmptiesStack)
{
	Stack<int> stack;

	stack.push(10);
	stack.clear();

	EXPECT_TRUE(stack.empty());
}

TEST(StackTest, LifoOrderWithMixedOperations)
{
	Stack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.pop();
	stack.push(30);
	stack.push(40);
	stack.pop();

	EXPECT_EQ(stack.size(), 2);
	EXPECT_EQ(stack.peek(), 30);
}