// 

/**
 *
 * AUTHORS: yuval yahod
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(12423222)) == nospaces("_===_\n(-.o)/\n/(] [)\n (\" \")\n"));
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )\n"));
    CHECK(nospaces(snowman(11111122)) == nospaces("_===_\n(.,.)\n<(] [)>\n(\" \")\n"));
    CHECK(nospaces(snowman(11111133)) == nospaces("_===_\n(.,.)\n<(> <)>\n(___)\n"));
    CHECK(nospaces(snowman(11111144)) == nospaces("_===_\n(.,.)\n<(   )>\n(   )\n"));
    CHECK(nospaces(snowman(22221411)) == nospaces("___\n.....\n(o.o)\n<( : )\n( : )\n"));
    CHECK(nospaces(snowman(22222211)) == nospaces("___\n.....\n \\(o.o)/\n( : )\n( : )\n"));
    CHECK(nospaces(snowman(22222211)) == nospaces("___\n.....\n \\(o.o)/\n( : )\n( : )\n"));
    CHECK(nospaces(snowman(22222224)) == nospaces("___\n.....\n \\(o.o)/\n(] [)\n(   )\n"));
    CHECK(nospaces(snowman(22222211)) == nospaces("___\n.....\n \\(o.o)/\n( : )\n( : )\n"));
    CHECK(nospaces(snowman(31423222)) == nospaces("_\n /_\\\n(-,o)/\n/(] [)\n (\" \")"));
    CHECK(nospaces(snowman(31423233)) == nospaces("_\n /_\\\n(-,o)/\n/(> <)\n (___)"));
    CHECK(nospaces(snowman(33333333)) == nospaces("_\n /_\\\n(O_O)\n/(> <)\\\n (___)"));
    CHECK(nospaces(snowman(34123412)) == nospaces("_\n /_\\\n(. o)\n/( : )\n (\" \")"));
    CHECK(nospaces(snowman(43434343)) == nospaces("___ \n(_*_)\n (-_O)\n(   )\\\n (___)"));
    CHECK(nospaces(snowman(43214321)) == nospaces("___ \n(_*_)\n (o_.)\n(] [)\\\n ( : )"));
    CHECK(nospaces(snowman(44444444)) == nospaces("___ \n(_*_)\n (- -)\n(   )\n (   )"));




}

TEST_CASE("Bad snowman code"){
    CHECK_THROWS(snowman(51212121));//the first number is not in range
    CHECK_THROWS(snowman(15212121));//the second number is not in range
    CHECK_THROWS(snowman(21512121));//...
    CHECK_THROWS(snowman(11252121));
    CHECK_THROWS(snowman(11215121));
    CHECK_THROWS(snowman(11212521));
    CHECK_THROWS(snowman(11212151));
    CHECK_THROWS(snowman(11212125));//the lest number is not in range

}
TEST_CASE("Invalid input length") {
    CHECK_THROWS(snowman(1));//1 number
    CHECK_THROWS(snowman(11));
    CHECK_THROWS(snowman(222));
    CHECK_THROWS(snowman(3333));
    CHECK_THROWS(snowman(1234));
    CHECK_THROWS(snowman(12341));
    CHECK_THROWS(snowman(122222));
    CHECK_THROWS(snowman(1333221));//7 numbers
    CHECK_THROWS(snowman(111111111));//9 numbers
}
TEST_CASE("Negetiv input"){
    CHECK_THROWS(snowman(-11234123)); //negetiv number

}

