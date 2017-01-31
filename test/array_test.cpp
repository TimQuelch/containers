#define BOOST_TEST_MODULE array_test
#include <boost/test/included/unit_test.hpp>

#include "array.h"

BOOST_AUTO_TEST_CASE(default_constructor) {
	size_t size = 10;
	containers::array<int> zeroSize;
	containers::array<int> smallSize(size);

	for (int i = 0; i < size; i++) {
		smallSize[i] = i;
	}
	for (int i = 0; i < size; i++) {
		BOOST_TEST(smallSize[i] == i);
	}
}

BOOST_AUTO_TEST_CASE(dummy_test_1) {
	BOOST_TEST(0 == 0);
}

BOOST_AUTO_TEST_CASE(dummy_test_2) {
	BOOST_TEST(0 == 0);
}

BOOST_AUTO_TEST_CASE(dummy_test_3) {
	BOOST_TEST(0 == 0);
}

BOOST_AUTO_TEST_CASE(dummy_test_4) {
	BOOST_TEST(0 == 0);
}

BOOST_AUTO_TEST_CASE(dummy_test_5) {
	BOOST_TEST(0 == 0);
}
