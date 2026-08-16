#include <gtest/gtest.h>
#include <dsa/SelectionSort.h>
#include <vector>
#include <functional>

TEST(SelectionSortTest, EmptyVector)
{
	std::vector<int> arr;
	dsa::SelectionSort(arr);

	EXPECT_TRUE(arr.empty());
}

TEST(SelectionSortTest, SingleElement)
{
	std::vector<int> arr = {10};
	dsa::SelectionSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{10}));
}

TEST(SelectionSortTest, AlreadySorted)
{
	std::vector<int> arr = {1,2,3,4,5};
	dsa::SelectionSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,2,3,4,5}));
}

TEST(SelectionSortTest, ReverseSorted)
{
	std::vector<int> arr = {5,4,3,2,1};
	dsa::SelectionSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,2,3,4,5}));
}

TEST(SelectionSortTest, RandomOrder)
{
	std::vector<int> arr = {5,3,4,6,8,1};
	dsa::SelectionSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,3,4,5,6,8}));
}

TEST(SelectionSortTest, DuplicateValues)
{
	std::vector<int> arr = {4,2,4,1,2,4};
	dsa::SelectionSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,2,2,4,4,4}));
}

TEST(SelectionSortTest, CustomComparatorDescending)
{
	std::vector<int> arr = {5,3,4,6,8,1};
	dsa::SelectionSort(arr, std::greater<int>());

	EXPECT_EQ(arr, (std::vector<int>{8,6,5,4,3,1}));
}