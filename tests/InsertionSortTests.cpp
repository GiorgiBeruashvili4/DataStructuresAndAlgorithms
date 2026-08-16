#include <gtest/gtest.h>
#include <dsa/InsertionSort.h>
#include <vector>
#include <functional>

TEST(InsertionSortTest, EmptyVector)
{
	std::vector<int> arr;
	dsa::InsertionSort(arr);

	EXPECT_TRUE(arr.empty());
}

TEST(InsertionSortTest, SingleElement)
{
	std::vector<int> arr = {10};
	dsa::InsertionSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{10}));
}

TEST(InsertionSortTest, AlreadySorted)
{
	std::vector<int> arr = {1,2,3,4,5};
	dsa::InsertionSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,2,3,4,5}));
}

TEST(InsertionSortTest, ReverseSorted)
{
	std::vector<int> arr = {5,4,3,2,1};
	dsa::InsertionSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,2,3,4,5}));
}

TEST(InsertionSortTest, RandomOrder)
{
	std::vector<int> arr = {5,3,4,6,8,1};
	dsa::InsertionSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,3,4,5,6,8}));
}

TEST(InsertionSortTest, DuplicateValues)
{
	std::vector<int> arr = {4,2,4,1,2,4};
	dsa::InsertionSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,2,2,4,4,4}));
}

TEST(InsertionSortTest, CustomComparatorDescending)
{
	std::vector<int> arr = {5,3,4,6,8,1};
	dsa::InsertionSort(arr, std::greater<int>());

	EXPECT_EQ(arr, (std::vector<int>{8,6,5,4,3,1}));
}