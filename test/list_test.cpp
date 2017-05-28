#define BOOST_TEST_MODULE array_test
#include <boost/test/included/unit_test.hpp>

#include "list.h"

BOOST_AUTO_TEST_CASE(defaultConstructor) {
	containers::list<int> a{};
	BOOST_TEST(a.size() == 0);
}

BOOST_AUTO_TEST_CASE(pushFrontSize) {
	containers::list<int> a{};
	a.push_front(5);
	BOOST_TEST(a.size() == 1);
}

BOOST_AUTO_TEST_CASE(pushBackSize) {
	containers::list<int> a{};
	a.push_back(5);
	BOOST_TEST(a.size() == 1);
}

BOOST_AUTO_TEST_CASE(pushFrontValue) {
	containers::list<int> a{};
	int value = 5;
	a.push_front(5);
	BOOST_TEST(a.front() == value);
}

BOOST_AUTO_TEST_CASE(pushBackValue) {
	containers::list<int> a{};
	int value = 5;
	a.push_back(5);
	BOOST_TEST(a.back() == value);
}

BOOST_AUTO_TEST_CASE(pushFrontRepeated) {
	containers::list<int> a{};
	for (int i = 1; i < 10; i++) {
		a.push_front(i);
		BOOST_TEST(a.size() == i);
		BOOST_TEST(a.front() == i);
	}
}

BOOST_AUTO_TEST_CASE(pushBackRepeated) {
	containers::list<int> a{};
	for (int i = 1; i < 10; i++) {
		a.push_back(i);
		BOOST_TEST(a.size() == i);
		BOOST_TEST(a.back() == i);
	}
}

BOOST_AUTO_TEST_CASE(popFront) {
	containers::list<int> a{};
	int size = 10;
	for (int i = 1; i <= size; i++) {
		a.push_back(i);
	}
	for (int i = 1; i <= size; i++) {
		BOOST_TEST(a.front() == i);
		a.pop_front();
		BOOST_TEST(a.size() == size - i);
	}
}

BOOST_AUTO_TEST_CASE(popBack) {
	containers::list<int> a{};
	int size = 10;
	for (int i = 1; i <= size; i++) {
		a.push_front(i);
	}
	for (int i = 1; i <= size; i++) {
		BOOST_TEST(a.back() == i);
		a.pop_back();
		BOOST_TEST(a.size() == size - i);
	}
}
