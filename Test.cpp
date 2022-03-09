/**
 * Tests for mat.cpp
 *
 * AUTHOR: Moriah David
 * 
 * Date: 2022-03
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input){
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("good input positive (odd)"){

	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));

    CHECK(nospaces(mat(3, 5, '@', '-')) == nospaces("@@@"
                                                    "@-@"
                                                    "@-@"
                                                    "@-@"
                                                    "@@@"));

    CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@"));

    CHECK(nospaces(mat(13, 9, '@', '-')) == nospaces("@@@@@@@@@@@@@"
                                                     "@-----------@"
                                                     "@-@@@@@@@@@-@"
                                                     "@-@-------@-@"
                                                     "@-@-@@@@@-@-@"
                                                     "@-@-------@-@"
                                                     "@-@@@@@@@@@-@"
                                                     "@-----------@"
                                                     "@@@@@@@@@@@@@"));
}

TEST_CASE("bad input positive (even)"){

	CHECK_THROWS(mat(10, 10, '$', '%'));

    CHECK_THROWS(mat(0, 0, '$', '%'));

    CHECK_THROWS(mat(4, 2, '$', '%'));

    CHECK_THROWS(mat(80, 200, '$', '%'));
}

TEST_CASE("bad input positive (even&odd)"){

	CHECK_THROWS(mat(10, 99, '$', '%'));

    CHECK_THROWS(mat(7, 0, '$', '%'));

    CHECK_THROWS(mat(55, 22, '$', '%'));
}

TEST_CASE("bad input negative (even)"){

	CHECK_THROWS(mat(-10, -0, '$', '%'));

    CHECK_THROWS(mat(-2, -100, '$', '%'));
}

TEST_CASE("bad input negative (odd)"){

	CHECK_THROWS(mat(-3, -5, '$', '%'));

    CHECK_THROWS(mat(-1, -1, '$', '%'));
}

TEST_CASE("bad input negative&positive"){
	CHECK_THROWS(mat(-77, 9, '$', '%'));

    CHECK_THROWS(mat(1, -63, '$', '%'));

    CHECK_THROWS(mat(-25, 21, '$', '%'));
	
}

TEST_CASE("bad input negative (even&odd)"){

	CHECK_THROWS(mat(10, -5, '$', '%'));

    CHECK_THROWS(mat(-10, 5, '$', '%'));
}

TEST_CASE("bad input not ascii"){

    CHECK_THROWS(mat(3, 5, -128, '%'));
    
    CHECK_THROWS(mat(3, 5, '%', -128));

    CHECK_THROWS(mat(3, 5, -1, '%'));

    CHECK_THROWS(mat(3, 5, -2, '%'));

    CHECK_THROWS(mat(3, 5, '@', -80));
}
