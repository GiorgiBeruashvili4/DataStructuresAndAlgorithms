#pragma once
#include <iostream>
#include <cassert>
#include "list.h"

void testPushBack()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	assert(l.size() == 3);
	assert(l.front() == 1);
	assert(l.back() == 3);

	std::cout << "testPushBack passed" << std::endl;
}

void testPushFront()
{
	List<int> l;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);

	assert(l.size() == 3);
	assert(l.front() == 3);
	assert(l.back() == 1);

	std::cout << "testPushFront passed" << std::endl;
}

void testPopBack()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.pop_back();

	assert(l.size() == 2);
	assert(l.back() == 2);

	std::cout << "testPopBack passed" << std::endl;
}

void testPopFront()
{
	List<int> l;

	l.push_front(1);
	l.push_front(2);
	l.push_front(3);

	l.pop_front();

	assert(l.size() == 2);
	assert(l.front() == 2);

	std::cout << "testPopFront passed" << std::endl;
}

void testEmpty()
{
	List<int> l;

	assert(l.empty() == true);
	assert(l.size() == 0);

	l.push_back(1);
	assert(l.empty() == false);

	std::cout << "testEmpty passed" << std::endl;
}

void testInsert()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(4);

	l.insert(3, 2);

	assert(l.size() == 4);
	assert(l.at(2) == 3);

	std::cout << "testInsert passed" << std::endl;
}

void testRemoveAt()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.removeAt(1);

	assert(l.size() == 2);
	assert(l.at(0) == 1);
	assert(l.at(1) == 3);

	std::cout << "testRemoveAt passed" << std::endl;
}

void testRemoveValue()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	bool removed = l.removeValue(2);
	assert(removed == true);
	assert(l.size() == 2);

	bool notRemoved = l.removeValue(100);
	assert(notRemoved == false);

	std::cout << "testRemoveValue passed" << std::endl;
}

void testContainsAndIndexOf()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	assert(l.contains(1) == true);
	assert(l.contains(100) == false);

	assert(l.indexOf(3) == 2);
	assert(l.indexOf(100) == -1);

	std::cout << "testContainsAndIndexOf passed" << std::endl;
}

void testReverse()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.reverse();

	assert(l.front() == 3);
	assert(l.back() == 1);

	std::cout << "testReverse passed" << std::endl;
}

void testAt()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	assert(l.at(0) == 1);
	assert(l.at(1) == 2);
	assert(l.at(2) == 3);

	std::cout << "testAt passed" << std::endl;
}

void testClear()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.clear();

	assert(l.empty() == true);
	assert(l.size() == 0);

	std::cout << "testClear passed" << std::endl;
}

void testPopFrontOnEmptyThrows()
{
	List<int> l;

	bool caught = false;

	try
	{
		l.pop_front();
	}
	catch (const std::out_of_range&)
	{
		caught = true;
	}

	assert(caught == true);

	std::cout << "testPopFrontOnEmptyThrows passed" << std::endl;
}

void testAtOutOfRangeThrows()
{
	List<int> l;

	bool caught = false;

	try
	{
		l.at(5);
	}
	catch (const std::out_of_range&)
	{
		caught = true;
	}

	assert(caught == true);

	std::cout << "testAtOutOfRangeThrows passed" << std::endl;
}

void testDoubleReverse()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.reverse();
	l.reverse();

	assert(l.at(0) == 1);
	assert(l.at(1) == 2);
	assert(l.at(2) == 3);
	assert(l.front() == 1);
	assert(l.back() == 3);

	std::cout << "testDoubleReverse passed" << std::endl;
}

void testPopBackAfterReverse()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.reverse();
	l.pop_back();

	assert(l.size() == 2);
	assert(l.back() == 2);
	assert(l.front() == 3);

	std::cout << "testPopBackAfterReverse passed" << std::endl;
}

void run()
{
	testPushBack();
	testPushFront();
	testPopBack();
	testPopFront();
	testEmpty();
	testInsert();
	testRemoveAt();
	testRemoveValue();
	testContainsAndIndexOf();
	testReverse();
	testAt();
	testClear();
	testPopFrontOnEmptyThrows();
	testAtOutOfRangeThrows();
	testDoubleReverse();
	testPopBackAfterReverse();

	std::cout << "\nAll tests passed\n";
}