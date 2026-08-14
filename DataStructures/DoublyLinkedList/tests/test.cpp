#include <gtest/gtest.h>
#include "list.h"
#include <stdexcept>

TEST(DoublyLinkedListTest, PushBack)
{
	DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	EXPECT_EQ(l.size(), 3);
	EXPECT_EQ(l.front(), 1);
	EXPECT_EQ(l.back(), 3);
}

TEST(DoublyLinkedListTest, PushFront)
{
	DoublyLinkedList<int> l;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);

	EXPECT_EQ(l.size(), 3);
	EXPECT_EQ(l.front(), 3);
	EXPECT_EQ(l.back(), 1);
}

TEST(DoublyLinkedListTest, PopBack)
{
	DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.pop_back();

	EXPECT_EQ(l.size(), 2);
	EXPECT_EQ(l.back(), 2);
}

TEST(DoublyLinkedListTest, PopFront)
{
	DoublyLinkedList<int> l;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);

	l.pop_front();

	EXPECT_EQ(l.size(), 2);
	EXPECT_EQ(l.front(), 2);
}

TEST(DoublyLinkedListTest, Empty)
{
	DoublyLinkedList<int> l;

	EXPECT_TRUE(l.empty());
	EXPECT_EQ(l.size(), 0);

	l.push_back(1);

	EXPECT_FALSE(l.empty());
}

TEST(DoublyLinkedListTest, Insert)
{
	DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(4);

	l.insert(3, 2);

	EXPECT_EQ(l.size(), 4);
	EXPECT_EQ(l.at(2), 3);
}

TEST(DoublyLinkedListTest, RemoveAt)
{
	DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.removeAt(1);

	EXPECT_EQ(l.size(), 2);
	EXPECT_EQ(l.at(0), 1);
	EXPECT_EQ(l.at(1), 3);
}

TEST(DoublyLinkedListTest, RemoveValue)
{
	DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	EXPECT_TRUE(l.removeValue(2));
	EXPECT_EQ(l.size(), 2);
	EXPECT_FALSE(l.removeValue(100));
}

TEST(DoublyLinkedListTest, ContainsAndIndexOf)
{
	DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	EXPECT_TRUE(l.contains(1));
	EXPECT_FALSE(l.contains(100));
	EXPECT_EQ(l.indexOf(3), 2);
	EXPECT_EQ(l.indexOf(100), -1);
}

TEST(DoublyLinkedListTest, Reverse)
{
	DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.reverse();

	EXPECT_EQ(l.front(), 3);
	EXPECT_EQ(l.back(), 1);
}

TEST(DoublyLinkedListTest, At)
{
	DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	EXPECT_EQ(l.at(0), 1);
	EXPECT_EQ(l.at(1), 2);
	EXPECT_EQ(l.at(2), 3);
}

TEST(DoublyLinkedListTest, Clear)
{
	DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.clear();

	EXPECT_TRUE(l.empty());
	EXPECT_EQ(l.size(), 0);
}

TEST(DoublyLinkedListTest, PopFrontOnEmptyThrows)
{
	DoublyLinkedList<int> l;

	EXPECT_THROW(l.pop_front(), std::out_of_range);
}

TEST(DoublyLinkedListTest, AtOutOfRangeThrows)
{
	DoublyLinkedList<int> l;

	EXPECT_THROW(l.at(5), std::out_of_range);
}

TEST(DoublyLinkedListTest, DoubleReverseRestoresOrder)
{
	DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.reverse();
	l.reverse();

	EXPECT_EQ(l.at(0), 1);
	EXPECT_EQ(l.at(1), 2);
	EXPECT_EQ(l.at(2), 3);
	EXPECT_EQ(l.front(), 1);
	EXPECT_EQ(l.back(), 3);
}

TEST(DoublyLinkedListTest, PopBackAfterReverse)
{
	DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.reverse();
	l.pop_back();

	EXPECT_EQ(l.size(), 2);
	EXPECT_EQ(l.back(), 2);
	EXPECT_EQ(l.front(), 3);
}