#include <gtest/gtest.h>
#include <dsa/MergeSort.h>
#include <vector>
#include <functional>

TEST(MergeSortTest, EmptyVector)
{
	std::vector<int> arr;
	dsa::MergeSort(arr);

	EXPECT_TRUE(arr.empty());
}

TEST(MergeSortTest, SingleElement)
{
	std::vector<int> arr = {10};
	dsa::MergeSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{10}));
}

TEST(MergeSortTest, AlreadySorted)
{
	std::vector<int> arr = {1,2,3,4,5};
	dsa::MergeSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,2,3,4,5}));
}

TEST(MergeSortTest, ReverseSorted)
{
	std::vector<int> arr = {5,4,3,2,1};
	dsa::MergeSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,2,3,4,5}));
}

TEST(MergeSortTest, RandomOrder)
{
	std::vector<int> arr = {5,3,4,6,8,1};
	dsa::MergeSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,3,4,5,6,8}));
}

TEST(MergeSortTest, DuplicateValues)
{
	std::vector<int> arr = {4,2,4,1,2,4};
	dsa::MergeSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,2,2,4,4,4}));
}

TEST(MergeSortTest, CustomComparatorDescending)
{
	std::vector<int> arr = {5,3,4,6,8,1};
	dsa::MergeSort(arr, std::greater<int>());

	EXPECT_EQ(arr, (std::vector<int>{8,6,5,4,3,1}));
}

TEST(MergeSortTest, EvenSizedVector)
{
	std::vector<int> arr = { 5,3,4,6 };
	dsa::MergeSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{3,4,5,6}));
}

TEST(MergeSortTest, OddSizedVector)
{
	std::vector<int> arr = {5,3,4,6,1};
	dsa::MergeSort(arr);

	EXPECT_EQ(arr, (std::vector<int>{1,3,4,5,6}));
}