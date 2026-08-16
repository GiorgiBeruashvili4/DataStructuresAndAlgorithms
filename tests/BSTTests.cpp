#include <gtest/gtest.h>
#include <dsa/BST.h>
#include <sstream>
#include <stdexcept>

TEST(BSTTest, EmptyOnConstruction)
{
	dsa::BST<int> tree;
	EXPECT_TRUE(tree.empty());
	EXPECT_EQ(tree.size(), 0);
}

TEST(BSTTest, InsertAndContains)
{
    dsa::BST<int> tree;
	tree.insertRecursive(10);
	tree.insertRecursive(5);
	tree.insertRecursive(15);

	EXPECT_TRUE(tree.containsRecursive(10));
	EXPECT_FALSE(tree.containsRecursive(100));
}

TEST(BSTTest, InsertAndContainsIterative)
{
    dsa::BST<int> tree;
    tree.insertIterative(10);
    tree.insertIterative(5);
    tree.insertIterative(15);

    EXPECT_TRUE(tree.containsIterative(10));
    EXPECT_FALSE(tree.containsIterative(100));
}

TEST(BSTTest, InOrderIsSorted)
{
    dsa::BST<int> tree;
	for (int i : {10, 5, 15, 3, 7})
	{
		tree.insertIterative(i);
	}

	std::ostringstream out;
	tree.inOrder(out);

	EXPECT_EQ(out.str(), "3 5 7 10 15 ");
}

TEST(BSTTest, RemoveLeaf)
{
    dsa::BST<int> tree;
	for (int i : {10, 5, 15})
	{
		tree.insertRecursive(i);
	}

	EXPECT_TRUE(tree.removeRecursive(5));
	EXPECT_FALSE(tree.containsRecursive(5));
}

TEST(BSTTest, RemoveLeafIterative)
{
    dsa::BST<int> tree;
    for (int i : {10, 5, 15})
    {
        tree.insertIterative(i);
    }

    EXPECT_TRUE(tree.removeIterative(5));
    EXPECT_FALSE(tree.containsIterative(5));
}

TEST(BSTTest, RemoveNodeWithTwoChildren)
{
    dsa::BST<int> tree;
	for (int i : {10, 5, 15, 3})
	{
		tree.insertIterative(i);
	}

	EXPECT_TRUE(tree.removeRecursive(10));
	EXPECT_FALSE(tree.containsRecursive(10));

	std::ostringstream out;
	tree.inOrder(out);

	EXPECT_EQ(out.str(), "3 5 15 ");
}

TEST(BSTTest, RemoveNodeWithTwoChildrenIterative)
{
    dsa::BST<int> tree;
    for (int i : {10, 5, 15, 3})
    {
        tree.insertIterative(i);
    }

    EXPECT_TRUE(tree.removeIterative(10));
    EXPECT_FALSE(tree.containsIterative(10));

    std::ostringstream out;
    tree.inOrder(out);

    EXPECT_EQ(out.str(), "3 5 15 ");
}

TEST(BSTTest, RemovePredecessorWithChild)
{
    dsa::BST<int> tree;
    for (int i : {10, 5, 15, 2, 7, 1})
    {
        tree.insertRecursive(i);
    }

    EXPECT_TRUE(tree.removeRecursive(10));

    std::ostringstream out;
    tree.inOrder(out);

    EXPECT_EQ(out.str(), "1 2 5 7 15 ");
}

TEST(BSTTest, RemovePredecessorWithChildIterative)
{
    dsa::BST<int> tree;
    for (int i : {10, 5, 15, 2, 7, 1})
    {
        tree.insertIterative(i);
    }

    EXPECT_TRUE(tree.removeIterative(10));

    std::ostringstream out;
    tree.inOrder(out);

    EXPECT_EQ(out.str(), "1 2 5 7 15 ");
}

TEST(BSTTest, RemoveNonExistentValue)
{
    dsa::BST<int> tree;
    tree.insertRecursive(10);

    EXPECT_FALSE(tree.removeRecursive(999));
    EXPECT_EQ(tree.size(), 1u);
}

TEST(BSTTest, RemoveNonExistentValueIterative)
{
    dsa::BST<int> tree;
    tree.insertIterative(10);

    EXPECT_FALSE(tree.removeIterative(999));
    EXPECT_EQ(tree.size(), 1u);
}

TEST(BSTTest, RemoveOnEmptyBST)
{
    dsa::BST<int> tree;

    EXPECT_FALSE(tree.removeRecursive(10));
    EXPECT_FALSE(tree.removeIterative(10));
}

TEST(BSTTest, MinMaxThrowOnEmpty)
{
    dsa::BST<int> tree;

    EXPECT_THROW(tree.min(), std::runtime_error);
    EXPECT_THROW(tree.max(), std::runtime_error);
}

TEST(BSTTest, MinMax)
{
    dsa::BST<int> tree;
    for (int i : {10, 5, 15, 3, 20})
    {
        tree.insertRecursive(i);
    }

    EXPECT_EQ(tree.min(), 3);
    EXPECT_EQ(tree.max(), 20);
}

TEST(BSTTest, HeightOfEmptyBSTIsZero)
{
    dsa::BST<int> tree;

    EXPECT_EQ(tree.height(), 0);
}

TEST(BSTTest, CopyConstructorIsDeep)
{
    dsa::BST<int> a;
    for (int i : {10, 5, 15})
    {
        a.insertRecursive(i);
    }

    dsa::BST<int> b(a);
    b.insertRecursive(20);

    EXPECT_FALSE(a.containsRecursive(20));
}

TEST(BSTTest, CopyAssignmentIsDeep)
{
    dsa::BST<int> a;
    for (int i : {10, 5, 15})
    {
        a.insertRecursive(i);
    }

    dsa::BST<int> b(a);
    b.insertRecursive(20);

    b = a;

    EXPECT_TRUE(b.containsRecursive(10));
    EXPECT_FALSE(b.containsRecursive(20));

    b.insertRecursive(30);

    EXPECT_FALSE(a.containsRecursive(30));
}

TEST(BSTTest, SelfAssignmentIsSafe)
{
    dsa::BST<int> a;
    for (int i : {10, 5, 15})
    {
        a.insertRecursive(i);
    }

    a = a;

    EXPECT_EQ(a.size(), 3u);
    EXPECT_TRUE(a.containsRecursive(10));
}

TEST(BSTTest, Equality)
{
    dsa::BST<int> a, b;
    for (int i : {10, 5, 15})
    {
        a.insertRecursive(i);
    }
    for (int i : {10, 15, 5})
    {
        b.insertRecursive(i);
    }

    EXPECT_TRUE(a == b);
}

TEST(BSTTest, ClearEmptiesTree)
{
    dsa::BST<int> tree;

    tree.insertRecursive(10);
    tree.clear();

    EXPECT_TRUE(tree.empty());
}

TEST(BSTTEsts, EmptyTressAreEqual)
{
    dsa::BST<int> a, b;

    EXPECT_TRUE(a == b);
}