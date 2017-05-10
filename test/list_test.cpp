#define BOOST_TEST_MODULE array_test
#include <boost/test/included/unit_test.hpp>

#include "list.h"

BOOST_AUTO_TEST_CASE(defaultConstructor) {
	containers::list<int> a{};
	BOOST_TEST(1);
}
