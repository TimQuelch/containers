#define BOOST_TEST_MODULE array_test
#include <boost/test/included/unit_test.hpp>

#include "array.h"

BOOST_AUTO_TEST_CASE(defaultConstructor) {
	containers::array<int> zeroSize{};
	BOOST_TEST(zeroSize.size() == 0);
}

BOOST_AUTO_TEST_CASE(sizeConstructor) {
	size_t size = 10;
	containers::array<int> a{size};
	BOOST_TEST(a.size() == size);
}

BOOST_AUTO_TEST_CASE(elementAccess) {
	size_t size = 10;
	containers::array<int> a{size};
	for (int i = 0; i < size; i++) {
		a[i] = i;
	}
	for (int i = 0; i < size; i++) {
		BOOST_TEST(a[i] == i);
	}
}

BOOST_AUTO_TEST_CASE(elementAccessAt) {
	size_t size = 10;
	containers::array<int> a{size};
	for (int i = 0; i < size; i++) {
		a.at(i) = i;
	}
	for (int i = 0; i < size; i++) {
		BOOST_TEST(a.at(i) == i);
	}
}

BOOST_AUTO_TEST_CASE(elementAccessFront) {
	size_t size = 5;
	containers::array<int> a{size};
	a[0] = 5;
	BOOST_TEST(a.front() == 5);
	a.front() = 7;
	BOOST_TEST(a.front() == 7);
}

BOOST_AUTO_TEST_CASE(elementAccessBack) {
	size_t size = 5;
	containers::array<int> a{size};
	a[size - 1] = 5;
	BOOST_TEST(a.back() == 5);
	a.back() = 7;
	BOOST_TEST(a.back() == 7);
}

BOOST_AUTO_TEST_CASE(getEmpty) {
	containers::array<int> a{static_cast<size_t>(0)};
	containers::array<int> b{static_cast<size_t>(5)};
	BOOST_TEST(a.empty());
	BOOST_TEST(!b.empty());
}

BOOST_AUTO_TEST_CASE(fillArray) {
	size_t size = 5;
	int val = 3;
	containers::array<int> a{size};
	a.fill(val);
	for (int i = 0; i < size; i++) {
		BOOST_TEST(a[i] == val);
	}
	val = -4;
	a.fill(val);
	for (int i = 0; i < size; i++) {
		BOOST_TEST(a[i] == val);
	}
}

BOOST_AUTO_TEST_CASE(getSize) {
	size_t sizeA = 5;
	containers::array<int> a{sizeA};
	BOOST_TEST(a.size() == sizeA);
	size_t sizeB = 2;
	containers::array<int> b{sizeB};
	BOOST_TEST(b.size() == sizeB);
	size_t sizeC = 8;
	containers::array<int> c{sizeC};
	BOOST_TEST(c.size() == sizeC);
}
