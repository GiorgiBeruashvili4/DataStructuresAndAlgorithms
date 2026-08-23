#include <gtest/gtest.h>
#include <dsa/AVL.h>
#include <sstream>
#include <stdexcept>

TEST(AVLTest, EmptyOnConstruction)
{
    dsa::AVL<int> tree;
    EXPECT_TRUE(tree.empty());
    EXPECT_EQ(tree.size(), 0);
}

TEST(AVLTest, InsertAndContains)
{
    dsa::AVL<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    EXPECT_TRUE(tree.contains(10));
    EXPECT_FALSE(tree.contains(100));
}

TEST(AVLTest, InOrderIsSorted)
{
    dsa::AVL<int> tree;
    for (int i : {10, 5, 15, 3, 7})
    {
        tree.insert(i);
    }

    std::ostringstream out;
    tree.inOrder(out);

    EXPECT_EQ(out.str(), "3 5 7 10 15 ");
}

TEST(AVLTest, RemoveLeaf)
{
    dsa::AVL<int> tree;
    for (int i : {10, 5, 15})
    {
        tree.insert(i);
    }

    EXPECT_TRUE(tree.remove(5));
    EXPECT_FALSE(tree.contains(5));
}

TEST(AVLTest, RemoveNodeWithTwoChildren)
{
    dsa::AVL<int> tree;
    for (int i : {10, 5, 15, 3})
    {
        tree.insert(i);
    }

    EXPECT_TRUE(tree.remove(10));
    EXPECT_FALSE(tree.contains(10));

    std::ostringstream out;
    tree.inOrder(out);

    EXPECT_EQ(out.str(), "3 5 15 ");
}

TEST(AVLTest, RemovePredecessorWithChild)
{
    dsa::AVL<int> tree;
    for (int i : {10, 5, 15, 2, 7, 1})
    {
        tree.insert(i);
    }

    EXPECT_TRUE(tree.remove(10));

    std::ostringstream out;
    tree.inOrder(out);

    EXPECT_EQ(out.str(), "1 2 5 7 15 ");
}

TEST(AVLTest, RemoveNonExistentValue)
{
    dsa::AVL<int> tree;
    tree.insert(10);

    EXPECT_FALSE(tree.remove(999));
    EXPECT_EQ(tree.size(), 1u);
}

TEST(AVLTest, RemoveOnEmptyBST)
{
    dsa::AVL<int> tree;

    EXPECT_FALSE(tree.remove(10));
}

TEST(AVLTest, MinMaxThrowOnEmpty)
{
    dsa::AVL<int> tree;

    EXPECT_THROW(tree.min(), std::runtime_error);
    EXPECT_THROW(tree.max(), std::runtime_error);
}

TEST(AVLTest, MinMax)
{
    dsa::AVL<int> tree;
    for (int i : {10, 5, 15, 3, 20})
    {
        tree.insert(i);
    }

    EXPECT_EQ(tree.min(), 3);
    EXPECT_EQ(tree.max(), 20);
}

TEST(AVLTest, CopyConstructorIsDeep)
{
    dsa::AVL<int> a;
    for (int i : {10, 5, 15})
    {
        a.insert(i);
    }

    dsa::AVL<int> b(a);
    b.insert(20);

    EXPECT_FALSE(a.contains(20));
}

TEST(AVLTest, CopyAssignmentIsDeep)
{
    dsa::AVL<int> a;
    for (int i : {10, 5, 15})
    {
        a.insert(i);
    }

    dsa::AVL<int> b(a);
    b.insert(20);

    b = a;

    EXPECT_TRUE(b.contains(10));
    EXPECT_FALSE(b.contains(20));

    b.insert(30);

    EXPECT_FALSE(a.contains(30));
}

TEST(AVLTest, SelfAssignmentIsSafe)
{
    dsa::AVL<int> a;
    for (int i : {10, 5, 15})
    {
        a.insert(i);
    }

    a = a;

    EXPECT_EQ(a.size(), 3u);
    EXPECT_TRUE(a.contains(10));
}

TEST(AVLTest, Equality)
{
    dsa::AVL<int> a, b;
    for (int i : {10, 5, 15})
    {
        a.insert(i);
    }
    for (int i : {10, 15, 5})
    {
        b.insert(i);
    }

    EXPECT_TRUE(a == b);
}

TEST(AVLTest, ClearEmptiesTree)
{
    dsa::AVL<int> tree;

    tree.insert(10);
    tree.clear();

    EXPECT_TRUE(tree.empty());
}

TEST(AVLTest, EmptyTressAreEqual)
{
    dsa::AVL<int> a, b;

    EXPECT_TRUE(a == b);
}

TEST(AVLTest, StaysBalancedOnSortedInput)
{
    dsa::AVL<int> tree;
    for (int i = 0;i < 7;++i)
    {
        tree.insert(i);
    }

    std::ostringstream out;
    tree.preOrder(out);

    EXPECT_EQ(out.str(), "3 1 0 2 5 4 6 ");
}

TEST(AVLTest, RemoveTriggersRebalance)
{
    dsa::AVL<int> tree;
    for (int i : {5, 3, 8, 2, 4, 7, 9, 1})
    {
        tree.insert(i);
    }

    tree.remove(9);
    tree.remove(7);

    std::ostringstream out;
    tree.inOrder(out);

    EXPECT_EQ(out.str(), "1 2 3 4 5 8 ");
}