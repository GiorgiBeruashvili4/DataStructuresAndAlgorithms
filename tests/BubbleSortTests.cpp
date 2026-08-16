#include <gtest/gtest.h>
#include <dsa/BubbleSort.h>
#include <vector>
#include <functional>

TEST(BubbleSortTest, EmptyVector)
{
	std::vector<int> arr;
	dsa::BubbleSort(arr);

	EXPECT_TRUE(arr.empty());
}

TEST(BubbleSortTest, SingleElement)
{
	std::vector<int> arr = {10};
	dsa::BubbleSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{10}));
}

TEST(BubbleSortTest, AlreadySorted)
{
	std::vector<int> arr = {1,2,3,4,5};
	dsa::BubbleSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,2,3,4,5}));
}

TEST(BubbleSortTest, ReverseSorted)
{
	std::vector<int> arr = {5,4,3,2,1};
	dsa::BubbleSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,2,3,4,5}));
}

TEST(BubbleSortTest, RandomOrder)
{
	std::vector<int> arr = {5,3,4,6,8,1};
	dsa::BubbleSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,3,4,5,6,8}));
}

TEST(BubbleSortTest, DuplicateValues)
{
	std::vector<int> arr = {4,2,4,1,2,4};
	dsa::BubbleSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,2,2,4,4,4}));
}

TEST(BubbleSortTest, CustomComparatorDescending)
{
	std::vector<int> arr = {5,3,4,6,8,1};
	dsa::BubbleSort(arr, std::greater<int>());

	EXPECT_EQ(arr, (std::vector<int>{8,6,5,4,3,1}));
}