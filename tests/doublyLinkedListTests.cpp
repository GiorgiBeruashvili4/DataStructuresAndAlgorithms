#include <gtest/gtest.h>
#include <dsa/doublyLinkedList.h>
#include <stdexcept>

TEST(DoublyLinkedListTest, PushBack)
{
	dsa::DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	EXPECT_EQ(l.size(), 3);
	EXPECT_EQ(l.front(), 1);
	EXPECT_EQ(l.back(), 3);
}

TEST(DoublyLinkedListTest, PushFront)
{
	dsa::DoublyLinkedList<int> l;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);

	EXPECT_EQ(l.size(), 3);
	EXPECT_EQ(l.front(), 3);
	EXPECT_EQ(l.back(), 1);
}

TEST(DoublyLinkedListTest, PopBack)
{
	dsa::DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.pop_back();

	EXPECT_EQ(l.size(), 2);
	EXPECT_EQ(l.back(), 2);
}

TEST(DoublyLinkedListTest, PopFront)
{
	dsa::DoublyLinkedList<int> l;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);

	l.pop_front();

	EXPECT_EQ(l.size(), 2);
	EXPECT_EQ(l.front(), 2);
}

TEST(DoublyLinkedListTest, Empty)
{
	dsa::DoublyLinkedList<int> l;

	EXPECT_TRUE(l.empty());
	EXPECT_EQ(l.size(), 0);

	l.push_back(1);

	EXPECT_FALSE(l.empty());
}

TEST(DoublyLinkedListTest, Insert)
{
	dsa::DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(4);

	l.insert(3, 2);

	EXPECT_EQ(l.size(), 4);
	EXPECT_EQ(l.at(2), 3);
}

TEST(DoublyLinkedListTest, InsertAtFront)
{
	dsa::DoublyLinkedList<int> l;

	l.push_back(2);
	l.push_back(3);

	l.insert(1, 0);

	EXPECT_EQ(l.size(), 3);
	EXPECT_EQ(l.front(), 1);
}

TEST(DoublyLinkedListTest, InsertAtEnd)
{
	dsa::DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);

	l.insert(3, l.size());

	EXPECT_EQ(l.size(), 3);
	EXPECT_EQ(l.back(), 3);
}


TEST(DoublyLinkedListTest, RemoveAt)
{
	dsa::DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.removeAt(1);

	EXPECT_EQ(l.size(), 2);
	EXPECT_EQ(l.at(0), 1);
	EXPECT_EQ(l.at(1), 3);
}

TEST(DoublyLinkedListTest, RemoveAtFront)
{
	dsa::DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.removeAt(0);

	EXPECT_EQ(l.size(), 2);
	EXPECT_EQ(l.front(), 2);
}

TEST(DoublyLinkedListTest, RemoveAtEnd)
{
	dsa::DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.removeAt(l.size() - 1);

	EXPECT_EQ(l.size(), 2);
	EXPECT_EQ(l.back(), 2);
}

TEST(DoublyLinkedListTest, RemoveValue)
{
	dsa::DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	EXPECT_TRUE(l.removeValue(2));
	EXPECT_EQ(l.size(), 2);
	EXPECT_FALSE(l.removeValue(100));
}

TEST(DoublyLinkedListTest, ContainsAndIndexOf)
{
	dsa::DoublyLinkedList<int> l;

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
	dsa::DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.reverse();

	EXPECT_EQ(l.front(), 3);
	EXPECT_EQ(l.back(), 1);
}

TEST(DoublyLinkedListTest, At)
{
	dsa::DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	EXPECT_EQ(l.at(0), 1);
	EXPECT_EQ(l.at(1), 2);
	EXPECT_EQ(l.at(2), 3);
}

TEST(DoublyLinkedListTest, Clear)
{
	dsa::DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.clear();

	EXPECT_TRUE(l.empty());
	EXPECT_EQ(l.size(), 0);
}

TEST(DoublyLinkedListTest, ClearOnEmptyListIsSafe)
{
	dsa::DoublyLinkedList<int> l;

	l.clear();

	EXPECT_TRUE(l.empty());
}

TEST(DoublyLinkedListTest, PopFrontOnEmptyThrows)
{
	dsa::DoublyLinkedList<int> l;

	EXPECT_THROW(l.pop_front(), std::out_of_range);
}

TEST(DoublyLinkedListTest, PopBackOnEmptyThrows)
{
	dsa::DoublyLinkedList<int> l;

	EXPECT_THROW(l.pop_back(), std::out_of_range);
}

TEST(DoublyLinkedListTest, AtOutOfRangeThrows)
{
	dsa::DoublyLinkedList<int> l;

	EXPECT_THROW(l.at(5), std::out_of_range);
}

TEST(DoublyLinkedListTest, DoubleReverseRestoresOrder)
{
	dsa::DoublyLinkedList<int> l;

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
	dsa::DoublyLinkedList<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.reverse();
	l.pop_back();

	EXPECT_EQ(l.size(), 2);
	EXPECT_EQ(l.back(), 2);
	EXPECT_EQ(l.front(), 3);
}

TEST(DoublyLinkedListTest, CopyConstructorIsDeep)
{
	dsa::DoublyLinkedList<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	dsa::DoublyLinkedList<int> b(a);
	b.push_back(4);

	EXPECT_EQ(a.size(), 3);
	EXPECT_EQ(b.size(), 4);
	EXPECT_EQ(a.back(), 3);
	EXPECT_EQ(b.back(), 4);
}

TEST(DoublyLinkedListTest, CopyAssignmentIsDeep)
{
	dsa::DoublyLinkedList<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	dsa::DoublyLinkedList<int> b;
	b.push_back(100);

	b = a;

	EXPECT_EQ(b.size(), 3);
	EXPECT_EQ(b.back(), 3);

	b.push_back(4);

	EXPECT_EQ(a.size(), 3);
	EXPECT_EQ(a.back(), 3);
	EXPECT_EQ(b.back(), 4);
}

TEST(DoublyLinkedListTest, SelfAssignmentIsSafe)
{
	dsa::DoublyLinkedList<int> a;
	a.push_back(1);
	a.push_back(2);

	a = a;

	EXPECT_EQ(a.size(), 2);
	EXPECT_EQ(a.front(), 1);
	EXPECT_EQ(a.back(), 2);
}