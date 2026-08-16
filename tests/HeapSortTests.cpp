#include <gtest/gtest.h>
#include <dsa/HeapSort.h>
#include <vector>
#include <functional>

TEST(HeapSortTest, EmptyVector)
{
	std::vector<int> arr;
	dsa::HeapSort(arr);

	EXPECT_TRUE(arr.empty());
}

TEST(HeapSortTest, SingleElement)
{
	std::vector<int> arr = { 10 };
	dsa::HeapSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{10}));
}

TEST(HeapSortTest, AlreadySorted)
{
	std::vector<int> arr = { 1,2,3,4,5 };
	dsa::HeapSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(HeapSortTest, ReverseSorted)
{
	std::vector<int> arr = { 5,4,3,2,1 };
	dsa::HeapSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(HeapSortTest, RandomOrder)
{
	std::vector<int> arr = { 5,3,4,6,8,1 };
	dsa::HeapSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1, 3, 4, 5, 6, 8}));
}

TEST(HeapSortTest, DuplicateValues)
{
	std::vector<int> arr = { 4,2,4,1,2,4 };
	dsa::HeapSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1, 2, 2, 4, 4, 4}));
}

TEST(HeapSortTest, CustomComparatorDescending)
{
	std::vector<int> arr = { 5,3,4,6,8,1 };
	dsa::HeapSort(arr, std::greater<int>());

	EXPECT_EQ(arr, (std::vector<int>{8, 6, 5, 4, 3, 1}));
}