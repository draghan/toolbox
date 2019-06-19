/*
    This file is distributed under MIT License.

    Copyright (c) 2019 draghan

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#include "../external/Catch2/single_include/catch2/catch.hpp"
#include "../src/toolbox/string/remove.hpp"
#include "../src/toolbox/string/query.hpp"
#include "../src/toolbox/string/transform.hpp"


TEST_CASE("String: remove character from string and return copy - removeChar", "[string][remove]")
{
    SECTION("Remove 'a' in 'Bear' pattern")
    {
        const std::string pattern{"Bear"};
        const auto result = toolbox::string::removeChar(pattern, 'a');

        REQUIRE(pattern == "Bear");
        REQUIRE(result == "Ber");
    }

    SECTION("Remove 'e' in 'beer' pattern")
    {
        const std::string pattern{"beer"};
        const auto result = toolbox::string::removeChar(pattern, 'e');

        REQUIRE(pattern == "beer");
        REQUIRE(result == "br");
    }

    SECTION("Remove 'c' in 'CCCc' pattern")
    {
        const std::string pattern{"CCCc"};
        const auto result = toolbox::string::removeChar(pattern, 'c');

        REQUIRE(pattern == "CCCc");
        REQUIRE(result == "CCC");
    }

    SECTION("Remove 'c' in 'cCCC' pattern")
    {
        const std::string pattern{"cCCC"};
        const auto result = toolbox::string::removeChar(pattern, 'c');

        REQUIRE(pattern == "cCCC");
        REQUIRE(result == "CCC");
    }

    SECTION("Remove 'c' in 'cCCcCCc' pattern")
    {
        const std::string pattern{"cCCcCCc"};
        const auto result = toolbox::string::removeChar(pattern, 'c');

        REQUIRE(pattern == "cCCcCCc");
        REQUIRE(result == "CCCC");
    }

    SECTION("Remove ' ' in 'cCCcCCc' pattern")
    {
        const std::string pattern{"cCCcCCc"};
        const auto result = toolbox::string::removeChar(pattern, ' ');

        REQUIRE(pattern == result);
    }

    SECTION("Remove ' ' in empty pattern")
    {
        const std::string pattern{""};
        const auto result = toolbox::string::removeChar(pattern, ' ');

        REQUIRE(pattern.empty());
        REQUIRE(result.empty());
    }

    SECTION("Remove 'a' in 'aaa' pattern")
    {
        const std::string pattern{"aaa"};
        const auto result = toolbox::string::removeChar(pattern, 'a');

        REQUIRE(pattern == "aaa");
        REQUIRE(result.empty());
    }
}

TEST_CASE("String: remove character from string in place - removeCharInPlace", "[string][remove]")
{
    SECTION("Remove 'a' in 'Bear' pattern")
    {
        std::string pattern{"Bear"};
        toolbox::string::removeCharInPlace(pattern, 'a');

        REQUIRE(pattern == "Ber");
    }

    SECTION("Remove 'e' in 'beer' pattern")
    {
        std::string pattern{"beer"};
        toolbox::string::removeCharInPlace(pattern, 'e');

        REQUIRE(pattern == "br");
    }

    SECTION("Remove 'c' in 'CCCc' pattern")
    {
        std::string pattern{"CCCc"};
        toolbox::string::removeCharInPlace(pattern, 'c');

        REQUIRE(pattern == "CCC");
    }

    SECTION("Remove 'c' in 'cCCC' pattern")
    {
        std::string pattern{"cCCC"};
        toolbox::string::removeCharInPlace(pattern, 'c');

        REQUIRE(pattern == "CCC");
    }

    SECTION("Remove 'c' in 'cCCcCCc' pattern")
    {
        std::string pattern{"cCCcCCc"};
        toolbox::string::removeCharInPlace(pattern, 'c');

        REQUIRE(pattern == "CCCC");
    }

    SECTION("Remove ' ' in 'cCCcCCc' pattern")
    {
        std::string pattern{"cCCcCCc"};
        toolbox::string::removeCharInPlace(pattern, ' ');

        REQUIRE(pattern == "cCCcCCc");
    }

    SECTION("Remove ' ' in empty pattern")
    {
        std::string pattern{""};
        toolbox::string::removeCharInPlace(pattern, ' ');

        REQUIRE(pattern.empty());
    }

    SECTION("Remove 'a' in 'aaa' pattern")
    {
        std::string pattern{"aaa"};
        toolbox::string::removeCharInPlace(pattern, 'a');

        REQUIRE(pattern.empty());
    }
}

TEST_CASE("String: remove multiple characters from string and return copy - removeChars", "[string][remove]")
{
    SECTION("Remove characters 'AB' from pattern 'ABC'")
    {
        std::string pattern{"ABC"};
        auto result = toolbox::string::removeChars(pattern, "AB");

        REQUIRE(pattern == "ABC");
        REQUIRE(result == "C");
    }

    SECTION("Remove characters 'BA' from pattern 'ABC'")
    {
        std::string pattern{"ABC"};
        auto result = toolbox::string::removeChars(pattern, "BA");

        REQUIRE(pattern == "ABC");
        REQUIRE(result == "C");
    }

    SECTION("Remove characters 'AB' from pattern 'abc'")
    {
        std::string pattern{"abc"};
        auto result = toolbox::string::removeChars(pattern, "AB");

        REQUIRE(pattern == "abc");
        REQUIRE(result == "abc");
    }

    SECTION("Remove characters 'A' from pattern 'ABBA'")
    {
        std::string pattern{"ABBA"};
        auto result = toolbox::string::removeChars(pattern, "A");

        REQUIRE(pattern == "ABBA");
        REQUIRE(result == "BB");
    }

    SECTION("Remove characters 'A' from empty pattern")
    {
        std::string pattern{""};
        auto result = toolbox::string::removeChars(pattern, "A");

        REQUIRE(pattern == "");
        REQUIRE(result == "");
    }

    SECTION("Remove empty blacklist from pattern 'ABBA'")
    {
        std::string pattern{"ABBA"};
        auto result = toolbox::string::removeChars(pattern, "");

        REQUIRE(pattern == "ABBA");
        REQUIRE(result == "ABBA");
    }

    SECTION("Remove empty blacklist from empty pattern")
    {
        std::string pattern{""};
        auto result = toolbox::string::removeChars(pattern, "");

        REQUIRE(pattern == "");
        REQUIRE(result == "");
    }

    SECTION("Remove characters 'ABBA' from pattern 'A'")
    {
        std::string pattern{"A"};
        auto result = toolbox::string::removeChars(pattern, "ABBA");

        REQUIRE(pattern == "A");
        REQUIRE(result == "");
    }

    SECTION("Remove characters 'ABBA' from pattern 'Ac'")
    {
        std::string pattern{"Ac"};
        auto result = toolbox::string::removeChars(pattern, "ABBA");

        REQUIRE(pattern == "Ac");
        REQUIRE(result == "c");
    }
}

TEST_CASE("String: remove multiple characters from string in place - removeCharsInPlace", "[string][remove]")
{
    SECTION("Remove characters 'AB' from pattern 'ABC'")
    {
        std::string pattern{"ABC"};
        toolbox::string::removeCharsInPlace(pattern, "AB");

        REQUIRE(pattern == "C");
    }

    SECTION("Remove characters 'BA' from pattern 'ABC'")
    {
        std::string pattern{"ABC"};
        toolbox::string::removeCharsInPlace(pattern, "BA");

        REQUIRE(pattern == "C");
    }

    SECTION("Remove characters 'AB' from pattern 'abc'")
    {
        std::string pattern{"abc"};
        toolbox::string::removeCharsInPlace(pattern, "AB");

        REQUIRE(pattern == "abc");
    }

    SECTION("Remove characters 'A' from pattern 'ABBA'")
    {
        std::string pattern{"ABBA"};
        toolbox::string::removeCharsInPlace(pattern, "A");

        REQUIRE(pattern == "BB");
    }

    SECTION("Remove characters 'A' from empty pattern")
    {
        std::string pattern{""};
        toolbox::string::removeCharsInPlace(pattern, "A");

        REQUIRE(pattern == "");
    }

    SECTION("Remove empty blacklist from pattern 'ABBA'")
    {
        std::string pattern{"ABBA"};
        auto result = toolbox::string::removeChars(pattern, "");

        REQUIRE(pattern == "ABBA");
        REQUIRE(result == "ABBA");
    }

    SECTION("Remove empty blacklist from empty pattern")
    {
        std::string pattern{""};
        toolbox::string::removeCharsInPlace(pattern, "");

        REQUIRE(pattern == "");
    }

    SECTION("Remove characters 'ABBA' from pattern 'A'")
    {
        std::string pattern{"A"};
        toolbox::string::removeCharsInPlace(pattern, "ABBA");

        REQUIRE(pattern == "");
    }

    SECTION("Remove characters 'ABBA' from pattern 'Ac'")
    {
        std::string pattern{"Ac"};
        toolbox::string::removeCharsInPlace(pattern, "ABBA");

        REQUIRE(pattern == "c");
    }
}

TEST_CASE("String: testing query about begining - startsWith", "[string][query]")
{
    SECTION("Single char version: one element false")
    {
        std::string pattern{"x"};
        REQUIRE_FALSE(toolbox::string::startsWith(pattern, 'X'));
    }

    SECTION("Single char version: one element true")
    {
        std::string pattern{"x"};
        REQUIRE(toolbox::string::startsWith(pattern, 'x'));
    }

    SECTION("Single char version: empty string")
    {
        std::string pattern{""};
        REQUIRE(!toolbox::string::startsWith(pattern, ' '));
    }

    SECTION("Single char version: true")
    {
        std::string pattern{"xxX"};
        REQUIRE(toolbox::string::startsWith(pattern, 'x'));
    }

    SECTION("Single char version: false")
    {
        std::string pattern{"xxX"};
        REQUIRE_FALSE(toolbox::string::startsWith(pattern, 'X'));
    }

    SECTION("Testing whether empty string starts with an empty string")
    {
        std::string pattern{""};
        REQUIRE(toolbox::string::startsWith(pattern, ""));
        REQUIRE(pattern == "");
    }

    SECTION("Testing whether empty string does not start with 'A'")
    {
        std::string pattern{""};
        REQUIRE(toolbox::string::startsWith(pattern, "A") == false);
        REQUIRE(pattern == "");
    }

    SECTION("Testing whether 'ABC' starts with an empty string")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::startsWith(pattern, ""));
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' starts with 'A'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::startsWith(pattern, "A"));
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' starts with 'AB'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::startsWith(pattern, "AB"));
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' starts with 'ABC'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::startsWith(pattern, "ABC"));
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' doesn't start with 'ABCD'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::startsWith(pattern, "ABCD") == false);
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' doesn't start with 'D'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::startsWith(pattern, "D") == false);
        REQUIRE(pattern == "ABC");
    }
}

TEST_CASE("String: testing query about ending - endsWith", "[string][query]")
{
    SECTION("Single char version: empty string")
    {
        std::string pattern{""};
        REQUIRE(!toolbox::string::endsWith(pattern, ' '));
    }

    SECTION("Single char version: true")
    {
        std::string pattern{"Xxx"};
        REQUIRE(toolbox::string::endsWith(pattern, 'x'));
    }

    SECTION("Single char version: false")
    {
        std::string pattern{"xxx"};
        REQUIRE_FALSE(toolbox::string::endsWith(pattern, 'X'));
    }

    SECTION("Single char version: one element false")
    {
        std::string pattern{"x"};
        REQUIRE_FALSE(toolbox::string::endsWith(pattern, 'X'));
    }

    SECTION("Single char version: one element true")
    {
        std::string pattern{"x"};
        REQUIRE(toolbox::string::endsWith(pattern, 'x'));
    }

    SECTION("Testing whether empty string ends with an empty string")
    {
        std::string pattern{""};
        REQUIRE(toolbox::string::endsWith(pattern, ""));
        REQUIRE(pattern == "");
    }

    SECTION("Testing whether empty string does not end with 'A'")
    {
        std::string pattern{""};
        REQUIRE(toolbox::string::endsWith(pattern, "A") == false);
        REQUIRE(pattern == "");
    }

    SECTION("Testing whether 'ABC' ends with an empty string")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::endsWith(pattern, ""));
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' ends with 'C'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::endsWith(pattern, "C"));
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' ends with 'BC'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::endsWith(pattern, "BC"));
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' ends with 'ABC'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::endsWith(pattern, "ABC"));
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' doesn't end with 'ABCD'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::endsWith(pattern, "ABCD") == false);
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' doesn't end with 'D'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::endsWith(pattern, "D") == false);
        REQUIRE(pattern == "ABC");
    }
}

TEST_CASE("String: testing query about containing any of the selected characters - containsAny", "[string][query]")
{
    SECTION("Corner case: empty source")
    {
        REQUIRE(toolbox::string::containsAny("", ""));
        REQUIRE_FALSE(toolbox::string::containsAny("", "zxcvfgrb."));
    }

    SECTION("Corner case: empty whitelist")
    {
        REQUIRE(toolbox::string::containsAny("", ""));
        REQUIRE_FALSE(toolbox::string::containsAny("a", ""));
    }

    SECTION("Positive")
    {
        REQUIRE(toolbox::string::containsAny("Abba", "AaBbCcDd"));
        REQUIRE(toolbox::string::containsAny("a", "AaBb"));
        REQUIRE(toolbox::string::containsAny("aaaaaaaaaaBCD", "a"));
    }

    SECTION("Negative")
    {
        REQUIRE_FALSE(toolbox::string::containsAny("Abbac", "Z"));
        REQUIRE_FALSE(toolbox::string::containsAny("a", "ABb"));
        REQUIRE_FALSE(toolbox::string::containsAny("AaBbCc", ""));
    }
}

TEST_CASE("String: testing query about containing only selected characters - containsOnly", "[string][query]")
{
    SECTION("Corner case: empty source")
    {
        REQUIRE(toolbox::string::containsOnly("", ""));
        REQUIRE_FALSE(toolbox::string::containsOnly("", "zxcvfgrb."));
    }

    SECTION("Corner case: empty whitelist")
    {
        REQUIRE(toolbox::string::containsOnly("", ""));
        REQUIRE_FALSE(toolbox::string::containsOnly("a", ""));
    }

    SECTION("Positive")
    {
        REQUIRE(toolbox::string::containsOnly("Abba", "AaBb"));
        REQUIRE(toolbox::string::containsOnly("a", "AaBb"));
        REQUIRE(toolbox::string::containsOnly("aaaaaaaaaa", "AaBb"));
    }

    SECTION("Negative")
    {
        REQUIRE_FALSE(toolbox::string::containsOnly("Abbac", "AaBb"));
        REQUIRE_FALSE(toolbox::string::containsOnly("a", "ABb"));
        REQUIRE_FALSE(toolbox::string::containsOnly("AaBbCc", "AaBb"));
    }
}

TEST_CASE("String: testing query about containing - contains", "[string][query]")
{
    SECTION("Single char version: one element false")
    {
        std::string pattern{"x"};
        REQUIRE_FALSE(toolbox::string::contains(pattern, 'X'));
    }

    SECTION("Single char version: one element true")
    {
        std::string pattern{"x"};
        REQUIRE(toolbox::string::contains(pattern, 'x'));
    }

    SECTION("Single char version: empty string")
    {
        std::string pattern{""};
        REQUIRE(!toolbox::string::contains(pattern, ' '));
    }

    SECTION("Single char version: true")
    {
        std::string pattern{"xxX"};
        REQUIRE(toolbox::string::contains(pattern, 'x'));
    }

    SECTION("Single char version: false")
    {
        std::string pattern{"xxx"};
        REQUIRE_FALSE(toolbox::string::contains(pattern, 'X'));
    }

    SECTION("Testing whether empty string contains an empty string")
    {
        std::string pattern{""};
        REQUIRE(toolbox::string::contains(pattern, ""));
        REQUIRE(pattern == "");
    }

    SECTION("Testing whether empty string does not contain 'A'")
    {
        std::string pattern{""};
        REQUIRE(toolbox::string::contains(pattern, "A") == false);
        REQUIRE(pattern == "");
    }

    SECTION("Testing whether 'ABC' contains an empty string")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::contains(pattern, ""));
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' contains 'C'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::contains(pattern, "C"));
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' contains 'BC'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::contains(pattern, "BC"));
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' contains 'ABC'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::contains(pattern, "ABC"));
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' doesn't contain 'ABCD'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::contains(pattern, "ABCD") == false);
        REQUIRE(pattern == "ABC");
    }

    SECTION("Testing whether 'ABC' doesn't contain 'D'")
    {
        std::string pattern{"ABC"};
        REQUIRE(toolbox::string::contains(pattern, "D") == false);
        REQUIRE(pattern == "ABC");
    }
}

TEST_CASE("String: trim beginning and end, return copy - trim", "[string][remove]")
{
    SECTION("Spaces from begining")
    {
        std::string pattern{" ABC"};
        auto result = toolbox::string::trim(pattern);

        REQUIRE(pattern == " ABC");
        REQUIRE(result == "ABC");
    }

    SECTION("Spaces from begining and end")
    {
        std::string pattern{" ABC  "};
        auto result = toolbox::string::trim(pattern);

        REQUIRE(pattern == " ABC  ");
        REQUIRE(result == "ABC");
    }

    SECTION("Spaces from end")
    {
        std::string pattern{"ABC   "};
        auto result = toolbox::string::trim(pattern);

        REQUIRE(pattern == "ABC   ");
        REQUIRE(result == "ABC");
    }

    SECTION("Spaces from begining and end - don't touch spaces from inside")
    {
        std::string pattern{" AB C  "};
        auto result = toolbox::string::trim(pattern);

        REQUIRE(pattern == " AB C  ");
        REQUIRE(result == "AB C");
    }


    SECTION("Tabs from begining")
    {
        std::string pattern{"\tABC"};
        auto result = toolbox::string::trim(pattern);

        REQUIRE(pattern == "\tABC");
        REQUIRE(result == "ABC");
    }

    SECTION("Tabs from begining and end")
    {
        std::string pattern{"\tABC\t\t"};
        auto result = toolbox::string::trim(pattern);

        REQUIRE(pattern == "\tABC\t\t");
        REQUIRE(result == "ABC");
    }

    SECTION("Tabs from end")
    {
        std::string pattern{"ABC\t\t\t"};
        auto result = toolbox::string::trim(pattern);

        REQUIRE(pattern == "ABC\t\t\t");
        REQUIRE(result == "ABC");
    }

    SECTION("Tabs from begining and end - don't touch spaces from inside")
    {
        std::string pattern{"\tAB\tC\t\t"};
        auto result = toolbox::string::trim(pattern);

        REQUIRE(pattern == "\tAB\tC\t\t");
        REQUIRE(result == "AB\tC");
    }

    // --

    SECTION("User defined characters")
    {
        std::string pattern{"xyzABCxxyy"};
        auto result = toolbox::string::trim(pattern, "xyz");

        REQUIRE(pattern == "xyzABCxxyy");
        REQUIRE(result == "ABC");
    }

    // --

    SECTION("Corner cases: empty pattern")
    {
        std::string pattern{""};
        auto result = toolbox::string::trim(pattern);

        REQUIRE(pattern == "");
        REQUIRE(result == "");
    }

    SECTION("Corner cases: empty pattern, empty chars to trim")
    {
        std::string pattern{""};
        auto result = toolbox::string::trim(pattern, "");

        REQUIRE(pattern == "");
        REQUIRE(result == "");
    }

    SECTION("Corner cases: empty chars to trim")
    {
        std::string pattern{"  ABC  "};
        auto result = toolbox::string::trim(pattern, "");

        REQUIRE(pattern == "  ABC  ");
        REQUIRE(result == "  ABC  ");
    }
}

TEST_CASE("String: trim beginning, return copy - trimAtBegin", "[string][remove]")
{
    SECTION("Spaces from begining")
    {
        std::string pattern{" ABC"};
        auto result = toolbox::string::trimAtBegin(pattern);

        REQUIRE(pattern == " ABC");
        REQUIRE(result == "ABC");
    }

    SECTION("Spaces from begining and end")
    {
        std::string pattern{" ABC  "};
        auto result = toolbox::string::trimAtBegin(pattern);

        REQUIRE(pattern == " ABC  ");
        REQUIRE(result == "ABC  ");
    }

    SECTION("Spaces from end")
    {
        std::string pattern{"ABC   "};
        auto result = toolbox::string::trimAtBegin(pattern);

        REQUIRE(pattern == "ABC   ");
        REQUIRE(result == pattern);
    }

    SECTION("Spaces from begining and end - don't touch spaces from inside")
    {
        std::string pattern{" AB C  "};
        auto result = toolbox::string::trimAtBegin(pattern);

        REQUIRE(pattern == " AB C  ");
        REQUIRE(result == "AB C  ");
    }


    SECTION("Tabs from begining")
    {
        std::string pattern{"\tABC"};
        auto result = toolbox::string::trimAtBegin(pattern);

        REQUIRE(pattern == "\tABC");
        REQUIRE(result == "ABC");
    }

    SECTION("Tabs from begining and end")
    {
        std::string pattern{"\t\tABC\t\t"};
        auto result = toolbox::string::trimAtBegin(pattern);

        REQUIRE(pattern == "\t\tABC\t\t");
        REQUIRE(result == "ABC\t\t");
    }

    SECTION("Tabs from end")
    {
        std::string pattern{"ABC\t\t\t"};
        auto result = toolbox::string::trimAtBegin(pattern);

        REQUIRE(pattern == "ABC\t\t\t");
        REQUIRE(result == "ABC\t\t\t");
    }

    SECTION("Tabs from begining and end - don't touch spaces from inside")
    {
        std::string pattern{"\tAB\tC\t\t"};
        auto result = toolbox::string::trimAtBegin(pattern);

        REQUIRE(pattern == "\tAB\tC\t\t");
        REQUIRE(result == "AB\tC\t\t");
    }

    // --

    SECTION("User defined characters")
    {
        std::string pattern{"xyzABCxxyy"};
        auto result = toolbox::string::trimAtBegin(pattern, "xyz");

        REQUIRE(pattern == "xyzABCxxyy");
        REQUIRE(result == "ABCxxyy");
    }

    // --

    SECTION("Corner cases: empty pattern")
    {
        std::string pattern{""};
        auto result = toolbox::string::trimAtBegin(pattern);

        REQUIRE(pattern == "");
        REQUIRE(result == "");
    }

    SECTION("Corner cases: empty pattern, empty chars to trim")
    {
        std::string pattern{""};
        auto result = toolbox::string::trimAtBegin(pattern, "");

        REQUIRE(pattern == "");
        REQUIRE(result == "");
    }

    SECTION("Corner cases: empty chars to trim")
    {
        std::string pattern{"  ABC  "};
        auto result = toolbox::string::trimAtBegin(pattern, "");

        REQUIRE(pattern == "  ABC  ");
        REQUIRE(result == "  ABC  ");
    }
}

TEST_CASE("String: trim end, return copy - trimAtEnd", "[string][remove]")
{
    SECTION("Spaces from begining")
    {
        std::string pattern{" ABC"};
        auto result = toolbox::string::trimAtEnd(pattern);

        REQUIRE(pattern == " ABC");
        REQUIRE(result == " ABC");
    }

    SECTION("Spaces from begining and end")
    {
        std::string pattern{" ABC  "};
        auto result = toolbox::string::trimAtEnd(pattern);

        REQUIRE(pattern == " ABC  ");
        REQUIRE(result == " ABC");
    }

    SECTION("Spaces from end")
    {
        std::string pattern{"ABC   "};
        auto result = toolbox::string::trimAtEnd(pattern);

        REQUIRE(pattern == "ABC   ");
        REQUIRE(result == "ABC");
    }

    SECTION("Spaces from begining and end - don't touch spaces from inside")
    {
        std::string pattern{" AB C  "};
        auto result = toolbox::string::trimAtEnd(pattern);

        REQUIRE(pattern == " AB C  ");
        REQUIRE(result == " AB C");
    }


    SECTION("Tabs from begining")
    {
        std::string pattern{"\tABC"};
        auto result = toolbox::string::trimAtEnd(pattern);

        REQUIRE(pattern == "\tABC");
        REQUIRE(result == "\tABC");
    }

    SECTION("Tabs from begining and end")
    {
        std::string pattern{"\t\tABC\t\t"};
        auto result = toolbox::string::trimAtEnd(pattern);

        REQUIRE(pattern == "\t\tABC\t\t");
        REQUIRE(result == "\t\tABC");
    }

    SECTION("Tabs from end")
    {
        std::string pattern{"ABC\t\t\t"};
        auto result = toolbox::string::trimAtEnd(pattern);

        REQUIRE(pattern == "ABC\t\t\t");
        REQUIRE(result == "ABC");
    }

    SECTION("Tabs from begining and end - don't touch spaces from inside")
    {
        std::string pattern{"\tAB\tC\t\t"};
        auto result = toolbox::string::trimAtEnd(pattern);

        REQUIRE(pattern == "\tAB\tC\t\t");
        REQUIRE(result == "\tAB\tC");
    }

    // --

    SECTION("User defined characters")
    {
        std::string pattern{"xyzABCxxyy"};
        auto result = toolbox::string::trimAtEnd(pattern, "xyz");

        REQUIRE(pattern == "xyzABCxxyy");
        REQUIRE(result == "xyzABC");
    }

    // --

    SECTION("Corner cases: empty pattern")
    {
        std::string pattern{""};
        auto result = toolbox::string::trimAtEnd(pattern);

        REQUIRE(pattern == "");
        REQUIRE(result == "");
    }

    SECTION("Corner cases: empty pattern, empty chars to trim")
    {
        std::string pattern{""};
        auto result = toolbox::string::trimAtEnd(pattern, "");

        REQUIRE(pattern == "");
        REQUIRE(result == "");
    }

    SECTION("Corner cases: empty chars to trim")
    {
        std::string pattern{"  ABC  "};
        auto result = toolbox::string::trimAtEnd(pattern, "");

        REQUIRE(pattern == "  ABC  ");
        REQUIRE(result == "  ABC  ");
    }
}

TEST_CASE("String: trim beginning in place- trimAtBeginInPlace", "[string][remove]")
{
    SECTION("Spaces from begining")
    {
        std::string pattern{" ABC"};
        toolbox::string::trimAtBeginInPlace(pattern);

        REQUIRE(pattern == "ABC");
    }

    SECTION("Spaces from begining and end")
    {
        std::string pattern{" ABC  "};
        REQUIRE_NOTHROW(toolbox::string::trimAtBeginInPlace(pattern));


        REQUIRE(pattern == "ABC  ");
    }

    SECTION("Spaces from end")
    {
        std::string pattern{"ABC   "};
        REQUIRE_NOTHROW(toolbox::string::trimAtBeginInPlace(pattern));

        REQUIRE(pattern == "ABC   ");
    }

    SECTION("Spaces from begining and end - don't touch spaces from inside")
    {
        std::string pattern{" AB C  "};
        REQUIRE_NOTHROW(toolbox::string::trimAtBeginInPlace(pattern));

        REQUIRE(pattern == "AB C  ");
    }


    SECTION("Tabs from begining")
    {
        std::string pattern{"\tABC"};
        REQUIRE_NOTHROW(toolbox::string::trimAtBeginInPlace(pattern));

        REQUIRE(pattern == "ABC");
    }

    SECTION("Tabs from begining and end")
    {
        std::string pattern{"\t\tABC\t\t"};
        REQUIRE_NOTHROW(toolbox::string::trimAtBeginInPlace(pattern));

        REQUIRE(pattern == "ABC\t\t");
    }

    SECTION("Tabs from end")
    {
        std::string pattern{"ABC\t\t\t"};
        REQUIRE_NOTHROW(toolbox::string::trimAtBeginInPlace(pattern));

        REQUIRE(pattern == "ABC\t\t\t");
    }

    SECTION("Tabs from begining and end - don't touch spaces from inside")
    {
        std::string pattern{"\tAB\tC\t\t"};
        REQUIRE_NOTHROW(toolbox::string::trimAtBeginInPlace(pattern));

        REQUIRE(pattern == "AB\tC\t\t");
    }

    // --

    SECTION("User defined characters")
    {
        std::string pattern{"xyzABCxxyy"};
        REQUIRE_NOTHROW(toolbox::string::trimAtBeginInPlace(pattern, "xyz"));

        REQUIRE(pattern == "ABCxxyy");
    }

    // --

    SECTION("Corner cases: empty pattern")
    {
        std::string pattern{""};
        REQUIRE_NOTHROW(toolbox::string::trimAtBeginInPlace(pattern));

        REQUIRE(pattern == "");
    }

    SECTION("Corner cases: empty pattern, empty chars to trim")
    {
        std::string pattern{""};
        REQUIRE_NOTHROW(toolbox::string::trimAtBeginInPlace(pattern, ""));

        REQUIRE(pattern == "");
    }

    SECTION("Corner cases: empty chars to trim")
    {
        std::string pattern{"  ABC  "};
        REQUIRE_NOTHROW(toolbox::string::trimAtBeginInPlace(pattern, ""));

        REQUIRE(pattern == "  ABC  ");
    }
}

TEST_CASE("String: trim ending in place- trimAtEndInPlace", "[string][remove]")
{
    SECTION("Spaces from begining")
    {
        std::string pattern{" ABC"};
        toolbox::string::trimAtEndInPlace(pattern);

        REQUIRE(pattern == " ABC");
    }

    SECTION("Spaces from begining and end")
    {
        std::string pattern{" ABC  "};
        REQUIRE_NOTHROW(toolbox::string::trimAtEndInPlace(pattern));


        REQUIRE(pattern == " ABC");
    }

    SECTION("Spaces from end")
    {
        std::string pattern{"ABC   "};
        REQUIRE_NOTHROW(toolbox::string::trimAtEndInPlace(pattern));

        REQUIRE(pattern == "ABC");
    }

    SECTION("Spaces from begining and end - don't touch spaces from inside")
    {
        std::string pattern{" AB C  "};
        REQUIRE_NOTHROW(toolbox::string::trimAtEndInPlace(pattern));

        REQUIRE(pattern == " AB C");
    }


    SECTION("Tabs from begining")
    {
        std::string pattern{"\tABC"};
        REQUIRE_NOTHROW(toolbox::string::trimAtEndInPlace(pattern));

        REQUIRE(pattern == "\tABC");
    }

    SECTION("Tabs from begining and end")
    {
        std::string pattern{"\t\tABC\t\t"};
        REQUIRE_NOTHROW(toolbox::string::trimAtEndInPlace(pattern));

        REQUIRE(pattern == "\t\tABC");
    }

    SECTION("Tabs from end")
    {
        std::string pattern{"ABC\t\t\t"};
        REQUIRE_NOTHROW(toolbox::string::trimAtEndInPlace(pattern));

        REQUIRE(pattern == "ABC");
    }

    SECTION("Tabs from begining and end - don't touch spaces from inside")
    {
        std::string pattern{"\tAB\tC\t\t"};
        REQUIRE_NOTHROW(toolbox::string::trimAtEndInPlace(pattern));

        REQUIRE(pattern == "\tAB\tC");
    }

    // --

    SECTION("User defined characters")
    {
        std::string pattern{"xyzABCxxyy"};
        REQUIRE_NOTHROW(toolbox::string::trimAtEndInPlace(pattern, "xyz"));

        REQUIRE(pattern == "xyzABC");
    }

    // --

    SECTION("Corner cases: empty pattern")
    {
        std::string pattern{""};
        REQUIRE_NOTHROW(toolbox::string::trimAtEndInPlace(pattern));

        REQUIRE(pattern == "");
    }

    SECTION("Corner cases: empty pattern, empty chars to trim")
    {
        std::string pattern{""};
        REQUIRE_NOTHROW(toolbox::string::trimAtEndInPlace(pattern, ""));

        REQUIRE(pattern == "");
    }

    SECTION("Corner cases: empty chars to trim")
    {
        std::string pattern{"  ABC  "};
        REQUIRE_NOTHROW(toolbox::string::trimAtEndInPlace(pattern, ""));

        REQUIRE(pattern == "  ABC  ");
    }
}

TEST_CASE("String: trim beginning and ending in place- trimInPlace", "[string][remove]")
{
    SECTION("Spaces from begining")
    {
        std::string pattern{" ABC"};
        toolbox::string::trimInPlace(pattern);

        REQUIRE(pattern == "ABC");
    }

    SECTION("Spaces from begining and end")
    {
        std::string pattern{" ABC  "};
        REQUIRE_NOTHROW(toolbox::string::trimInPlace(pattern));


        REQUIRE(pattern == "ABC");
    }

    SECTION("Spaces from end")
    {
        std::string pattern{"ABC   "};
        REQUIRE_NOTHROW(toolbox::string::trimInPlace(pattern));

        REQUIRE(pattern == "ABC");
    }

    SECTION("Spaces from begining and end - don't touch spaces from inside")
    {
        std::string pattern{" AB C  "};
        REQUIRE_NOTHROW(toolbox::string::trimInPlace(pattern));

        REQUIRE(pattern == "AB C");
    }


    SECTION("Tabs from begining")
    {
        std::string pattern{"\tABC"};
        REQUIRE_NOTHROW(toolbox::string::trimInPlace(pattern));

        REQUIRE(pattern == "ABC");
    }

    SECTION("Tabs from begining and end")
    {
        std::string pattern{"\t\tABC\t\t"};
        REQUIRE_NOTHROW(toolbox::string::trimInPlace(pattern));

        REQUIRE(pattern == "ABC");
    }

    SECTION("Tabs from end")
    {
        std::string pattern{"ABC\t\t\t"};
        REQUIRE_NOTHROW(toolbox::string::trimInPlace(pattern));

        REQUIRE(pattern == "ABC");
    }

    SECTION("Tabs from begining and end - don't touch spaces from inside")
    {
        std::string pattern{"\tAB\tC\t\t"};
        REQUIRE_NOTHROW(toolbox::string::trimInPlace(pattern));

        REQUIRE(pattern == "AB\tC");
    }

    // --

    SECTION("User defined characters")
    {
        std::string pattern{"xyzABCxxyy"};
        REQUIRE_NOTHROW(toolbox::string::trimInPlace(pattern, "xyz"));

        REQUIRE(pattern == "ABC");

        pattern = "xyz ABC xxyy";
        REQUIRE_NOTHROW(toolbox::string::trimInPlace(pattern, "xyz"));

        REQUIRE(pattern == " ABC ");
    }

    // --

    SECTION("Corner cases: empty pattern")
    {
        std::string pattern{""};
        REQUIRE_NOTHROW(toolbox::string::trimInPlace(pattern));

        REQUIRE(pattern == "");
    }

    SECTION("Corner cases: empty pattern, empty chars to trim")
    {
        std::string pattern{""};
        REQUIRE_NOTHROW(toolbox::string::trimInPlace(pattern, ""));

        REQUIRE(pattern == "");
    }

    SECTION("Corner cases: empty chars to trim")
    {
        std::string pattern{"  ABC  "};
        REQUIRE_NOTHROW(toolbox::string::trimInPlace(pattern, ""));

        REQUIRE(pattern == "  ABC  ");
    }
}


TEST_CASE("String: convert hex string to single variable", "[string][transform]")
{
    SECTION("Conversion to uint8_t")
    {
        uint8_t result;
        REQUIRE_NOTHROW(result = toolbox::string::convertHexString<uint8_t>("0xAB"));
        REQUIRE(result == 0xAB);

        REQUIRE_THROWS(result = toolbox::string::convertHexString<uint8_t>("0xABC"));

        REQUIRE_NOTHROW(result = toolbox::string::convertHexString<uint8_t>("BC"));
        REQUIRE(result == 0xBC);

        REQUIRE_NOTHROW(result = toolbox::string::convertHexString<uint8_t>(""));
        REQUIRE(result == 0);

        REQUIRE_NOTHROW(result = toolbox::string::convertHexString<uint8_t>("1"));
        REQUIRE(result == 1);
    }

    SECTION("Conversion to uint16_t")
    {
        uint16_t result;
        REQUIRE_NOTHROW(result = toolbox::string::convertHexString<uint16_t>("0xABBA"));
        REQUIRE(result == 0xABBA);

        REQUIRE_THROWS(result = toolbox::string::convertHexString<uint16_t>("0xABCDE"));

        REQUIRE_THROWS(result = toolbox::string::convertHexString<uint16_t>("0xZ"));

        REQUIRE_NOTHROW(result = toolbox::string::convertHexString<uint16_t>("BC"));
        REQUIRE(result == 0xBC);

        REQUIRE_NOTHROW(result = toolbox::string::convertHexString<uint16_t>(""));
        REQUIRE(result == 0);

        REQUIRE_NOTHROW(result = toolbox::string::convertHexString<uint16_t>("1"));
        REQUIRE(result == 1);
    }
}