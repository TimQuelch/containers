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
